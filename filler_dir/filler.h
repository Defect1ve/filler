/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:33:58 by ikotvits          #+#    #+#             */
/*   Updated: 2018/07/07 17:33:59 by ikotvits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_coord
{
	short		**map;
	int			*arr_x;
	int			*arr_y;
	int			piece_h;
	int			piece_w;
	int			map_h;
	int			map_w;
	char		symbol;
	short		x;
	short		y;
	int			min_sum;
	int			min_x;
	int			min_y;
}				t_coord;

void			manage_token(t_coord *s);
int				algorithm(t_coord *s);
void			clean_it(t_coord *s);
void			get_map(t_coord *s, char *line);

#endif
