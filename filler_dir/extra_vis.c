/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_vis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 21:49:48 by ikotvits          #+#    #+#             */
/*   Updated: 2018/07/18 21:49:49 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualization.h"

void		del_em_all(t_param *s)
{
	int i;

	i = 0;
	while (i < s->map_h)
		free(s->map[i++]);
	free(s->map);
}

void		fill_cell(t_param *s, int i, int j)
{
	int x;
	int y;

	y = s->win_size * 1 / 10 + (s->win_size * 8 / 10) / s->map_w * i + 1;
	while (y <= s->win_size * 1 / 10 + (s->win_size * 8 / 10)
	/ s->map_w * (i + 1) - 1)
	{
		x = s->win_size * 1 / 10 + (s->win_size * 8 / 10) / s->map_w * j + 1;
		while (x <= s->win_size * 1 / 10 + (s->win_size * 8 / 10)
		/ s->map_w * (j + 1) - 1)
		{
			if (s->map[i][j] == 1)
				mlx_pixel_put(s->mlx_ptr, s->win_ptr, x, y, 0x0000FF);
			else if (s->map[i][j] == -1)
				mlx_pixel_put(s->mlx_ptr, s->win_ptr, x, y, 0x7F7FFF);
			else if (s->map[i][j] == -2)
				mlx_pixel_put(s->mlx_ptr, s->win_ptr, x, y, 0xFF8080);
			else if (s->map[i][j] == 2)
				mlx_pixel_put(s->mlx_ptr, s->win_ptr, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void		fill_it(t_param *s)
{
	int i;
	int j;

	i = -1;
	while (++i < s->map_h)
	{
		j = -1;
		while (++j < s->map_w)
			if (s->map[i][j] != 0)
				fill_cell(s, i, j);
	}
}

void		draw_map(t_param *s)
{
	int i;
	int j;
	int columns;
	int rows;

	i = s->win_size * 1 / 10;
	rows = s->map_h + 1;
	while (i <= s->win_size * 9 / 10 && rows--)
	{
		j = s->win_size * 1 / 10;
		while (j <= (s->win_size * 8 / 10) / s->map_w
		* s->map_w + s->win_size * 1 / 10)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, j++, i, 0xFFFFFF);
		i += (s->win_size * 8 / 10) / s->map_w;
	}
	j = s->win_size * 1 / 10;
	columns = s->map_w + 1;
	while (j <= s->win_size * 9 / 10 && columns--)
	{
		i = s->win_size * 1 / 10;
		while (i <= (s->win_size * 8 / 10) / s->map_w
		* s->map_h + s->win_size * 1 / 10)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, j, i++, 0xFFFFFF);
		j += (s->win_size * 8 / 10) / s->map_w;
	}
}

void		finish(t_param *param)
{
	param->res_1 = ft_strdup(param->line);
	ft_strdel(&param->line);
	get_next_line(0, &param->line);
	param->res_2 = ft_strdup(param->line);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50,
	param->win_size - 100, 0xDC143C, param->res_1);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 50,
	param->win_size - 50, 0x1E90FF, param->res_2);
}
