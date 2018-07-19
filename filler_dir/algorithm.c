/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:42:43 by ikotvits          #+#    #+#             */
/*   Updated: 2018/07/08 15:42:44 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	distance_iter(t_coord *s, int i, short distance, char *flag)
{
	int j;

	while (++i < s->map_h)
	{
		j = -1;
		while (++j < s->map_w)
			if (s->map[i][j] == 999 && ((j - 1 > -1 && s->map[i][j - 1] != 999
			&& s->map[i][j - 1] != distance && s->map[i][j - 1] != -1) ||
			(j + 1 < s->map_w && s->map[i][j + 1] != 999 && s->map[i][j + 1] !=
			distance && s->map[i][j + 1] != -1) || (i - 1 > -1 &&
			s->map[i - 1][j] != 999 && s->map[i - 1][j] != distance &&
			s->map[i - 1][j] != -1) || (i + 1 < s->map_h && s->map[i + 1][j]
			!= 999 && s->map[i + 1][j] != distance && s->map[i + 1][j] != -1)))
			{
				s->map[i][j] = distance;
				*flag = 1;
			}
	}
}

void	add_distance(t_coord *s)
{
	int		i;
	short	distance;
	char	flag;

	distance = 1;
	while (1)
	{
		flag = 0;
		i = -1;
		distance_iter(s, i, distance, &flag);
		if (!flag)
			break ;
		distance++;
	}
}

void	best_one(t_coord *s, int local_sum, int i, int j)
{
	s->min_sum = local_sum;
	s->x = i - s->min_x;
	s->y = j - s->min_y;
}

void	place_check(t_coord *s, int i, int j)
{
	int k;
	int l;
	int local_sum;

	l = 0;
	k = 0;
	local_sum = 0;
	while (s->arr_x[k] != -1)
	{
		if (s->arr_x[k] + i < s->map_h && s->arr_y[k] + j < s->map_w &&
		s->arr_x[k] + i > -1 && s->arr_y[k] + j > -1
		&& s->map[s->arr_x[k] + i][s->arr_y[k] + j] == -1)
			l++;
		if ((s->arr_x[k] + i >= s->map_h || s->arr_y[k] + j >= s->map_w ||
		s->arr_x[k] + i < 0 || s->arr_y[k] + j < 0 ||
		s->map[s->arr_x[k] + i][s->arr_y[k] + j] == -2) && (l = 2))
			break ;
		if (s->map[s->arr_x[k] + i][s->arr_y[k] + j] > 0)
			local_sum += s->map[s->arr_x[k] + i][s->arr_y[k] + j];
		k++;
	}
	if (l == 1 && local_sum < s->min_sum)
		best_one(s, local_sum, i, j);
}

int		algorithm(t_coord *s)
{
	int i;
	int j;

	s->x = 0;
	s->y = 0;
	s->min_sum = 99999;
	add_distance(s);
	i = -1;
	while (++i < s->map_h)
	{
		j = -1;
		while (++j < s->map_w)
			place_check(s, i, j);
	}
	ft_printf("%hd %hd\n", s->x, s->y);
	clean_it(s);
	return ((s->min_sum == 99999) ? 1 : 0);
}
