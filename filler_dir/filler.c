/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:27:54 by ikotvits          #+#    #+#             */
/*   Updated: 2018/07/07 17:27:57 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_map_help(t_coord *s, char *line, int i)
{
	int j;

	j = -1;
	while (++j < s->map_w)
	{
		if (line[j + 4] == s->symbol || line[j + 4] == s->symbol + 32)
			s->map[i][j] = -1;
		else if (line[j + 4] != s->symbol && line[j + 4] != '.')
			s->map[i][j] = -2;
		else
			s->map[i][j] = 999;
	}
}

void	get_map(t_coord *s, char *line)
{
	int i;

	get_next_line(0, &line);
	i = 0;
	while (*(line + i) > 57 || *(line + i) < 48)
		i++;
	s->map_h = ft_atoi(line + i);
	while (*(line + i) <= 57 && *(line + i) >= 48)
		i++;
	s->map_w = ft_atoi(line + i);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	s->map = (short **)malloc(sizeof(short *) * s->map_h);
	i = -1;
	while (++i < s->map_h)
	{
		s->map[i] = (short *)malloc(sizeof(short) * s->map_w);
		get_next_line(0, &line);
		get_map_help(s, line, i);
		ft_strdel(&line);
	}
}

int		get_token_help(t_coord *s, char *line)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (++i < s->piece_h)
	{
		j = -1;
		get_next_line(0, &line);
		while (++j < s->piece_w)
			if (line[j] == '*')
			{
				s->arr_y[k] = j;
				s->arr_x[k++] = i;
			}
		ft_strdel(&line);
	}
	return (k);
}

void	get_token(t_coord *s, char *line)
{
	int i;
	int k;

	i = 0;
	get_next_line(0, &line);
	s->piece_h = ft_atoi(line + 6);
	while (*(line + 6 + i) <= 57 && *(line + 6 + i) >= 48)
		i++;
	s->piece_w = ft_atoi(line + 6 + i);
	free(line);
	s->arr_x = (int *)malloc(sizeof(int) * (s->piece_w * s->piece_h + 1));
	s->arr_y = (int *)malloc(sizeof(int) * (s->piece_h * s->piece_w + 1));
	k = get_token_help(s, line);
	s->arr_x[k] = -1;
	s->arr_y[k] = -1;
}

int		main(void)
{
	t_coord	*s;
	char	*line;

	s = (t_coord *)malloc(sizeof(t_coord));
	get_next_line(0, &line);
	s->symbol = (*(ft_strchr(line, 'p') + 1) == '1') ? 'O' : 'X';
	free(line);
	while (1)
	{
		get_map(s, line);
		get_token(s, line);
		manage_token(s);
		if (algorithm(s))
			return (0);
	}
	return (0);
}
