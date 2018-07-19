/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:57:41 by ikotvits          #+#    #+#             */
/*   Updated: 2018/07/18 11:57:42 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H

# include "mlx.h"
# include "../libft/libft.h"

typedef struct	s_param
{
	short		**map;
	int			map_h;
	int			map_w;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_size;
	char		*player1;
	char		*player2;
	char		*res_1;
	char		*res_2;
	char		*line;
}				t_param;

void			get_map(t_param *s);
void			finish(t_param *param);
void			draw_map(t_param *s);
void			fill_it(t_param *s);
void			del_em_all(t_param *s);

#endif
