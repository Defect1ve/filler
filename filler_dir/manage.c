/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:37:16 by ikotvits          #+#    #+#             */
/*   Updated: 2018/07/08 15:37:18 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	manage_token(t_coord *s)
{
	int		i;

	s->min_x = s->piece_w;
	s->min_y = s->piece_h;
	i = -1;
	while (s->arr_x[++i] != -1)
	{
		if (s->min_x > s->arr_x[i])
			s->min_x = s->arr_x[i];
		if (s->min_y > s->arr_y[i])
			s->min_y = s->arr_y[i];
	}
	i = -1;
	while (s->arr_x[++i] != -1)
	{
		s->arr_x[i] -= s->min_x;
		s->arr_y[i] -= s->min_y;
	}
}

void	clean_it(t_coord *s)
{
	int i;

	i = -1;
	while (++i < s->map_h)
		free(s->map[i]);
	free(s->map);
	free(s->arr_x);
	free(s->arr_y);
}
