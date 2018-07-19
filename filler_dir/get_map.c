/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:53:23 by ikotvits          #+#    #+#             */
/*   Updated: 2018/07/18 12:53:24 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualization.h"

void	get_map_help(t_param *s, int i)
{
	int j;

	j = -1;
	while (++j < s->map_w)
	{
		if (s->line[j + 4] == 'X')
			s->map[i][j] = 1;
		else if (s->line[j + 4] == 'x')
			s->map[i][j] = -1;
		else if (s->line[j + 4] == 'O')
			s->map[i][j] = 2;
		else if (s->line[j + 4] == 'o')
			s->map[i][j] = -2;
		else
			s->map[i][j] = 0;
	}
}

void	get_map(t_param *s)
{
	int i;

	i = 0;
	while (*(s->line + i) > 57 || *(s->line + i) < 48)
		i++;
	s->map_h = ft_atoi(s->line + i);
	while (*(s->line + i) <= 57 && *(s->line + i) >= 48)
		i++;
	s->map_w = ft_atoi(s->line + i);
	ft_strdel(&s->line);
	get_next_line(0, &s->line);
	ft_strdel(&s->line);
	s->map = (short **)malloc(sizeof(short *) * s->map_h);
	i = -1;
	while (++i < s->map_h)
	{
		s->map[i] = (short *)malloc(sizeof(short) * s->map_w);
		get_next_line(0, &s->line);
		get_map_help(s, i);
		ft_strdel(&s->line);
	}
}
