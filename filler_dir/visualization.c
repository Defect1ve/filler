/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 09:26:36 by ikotvits          #+#    #+#             */
/*   Updated: 2018/07/18 09:26:38 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualization.h"

int			start(t_param *param)
{
	while (get_next_line(0, &(param->line)) > 0)
	{
		if (ft_strstr(param->line, "Plateau"))
		{
			mlx_clear_window(param->mlx_ptr, param->win_ptr);
			mlx_string_put(param->mlx_ptr, param->win_ptr, param->win_size
			/ 20, param->win_size / 20, 0xDC143C, param->player1);
			mlx_string_put(param->mlx_ptr, param->win_ptr, param->win_size
			/ 20 * 15, param->win_size / 20, 0x1E90FF, param->player2);
			get_map(param);
			draw_map(param);
			fill_it(param);
			ft_strdel(&(param->line));
			del_em_all(param);
			return (0);
		}
		else if (ft_strstr(param->line, "=="))
			finish(param);
		ft_strdel(&param->line);
	}
	return (1);
}

static int	key_hook(int keycode, t_param *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(0);
	}
	else if (keycode == 49)
		mlx_loop_hook(param->mlx_ptr, start, param);
	return (0);
}

static int	exit_x(void)
{
	exit(0);
}

void		first_scr(char *line, t_param *param)
{
	int len;

	len = param->win_size / 2 - 150;
	get_next_line(0, &line);
	param->player1 = ft_strdup(ft_strchr(line, '/') + 1);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	get_next_line(0, &line);
	param->player2 = ft_strdup(ft_strchr(line, '/') + 1);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	mlx_string_put(param->mlx_ptr, param->win_ptr, len,
	len, 0xFF0000, " ___  _  _    _    ___  ___ ");
	mlx_string_put(param->mlx_ptr, param->win_ptr, len,
	len + 20, 0xFF0000, "| __>| || |  | |  | __>| . \\");
	mlx_string_put(param->mlx_ptr, param->win_ptr, len,
	len + 40, 0xFF0000, "| _> | || |_ | |_ | _> |   /");
	mlx_string_put(param->mlx_ptr, param->win_ptr, len,
	len + 60, 0xFF0000, "|_|  |_||___||___||___>|_\\_\\");
	mlx_string_put(param->mlx_ptr, param->win_ptr, param->win_size / 2 - 75,
	param->win_size * 0.9, 0xFF0000, "Just push SPACE");
}

int			main(void)
{
	t_param	*param;
	char	*line;
	int		i;

	line = NULL;
	param = (t_param *)malloc(sizeof(t_param));
	param->line = line;
	i = 5;
	while (i-- > 0)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	param->win_size = 1200;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr,
	param->win_size, param->win_size, "This Is Filler Bitch");
	first_scr(line, param);
	mlx_hook(param->win_ptr, 2, 0, key_hook, param);
	mlx_hook(param->win_ptr, 17, 1L << 17, exit_x, 0);
	mlx_loop(param->mlx_ptr);
}
