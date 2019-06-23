/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:36:11 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 13:07:41 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		is_placable2(t_piece **p, int i, int i2)
{
	if ((*p)->contact == 1)
	{
		(*p)->return_x = i2;
		(*p)->return_y = i;
		return (0);
	}
	return (1);
}

int				is_placable(int i, int i2, t_sog **map, t_piece **p)
{
	t_place	c;

	c.i = -1;
	(*p)->contact = 0;
	if (i + (*p)->piece_rows > (*map)->nb_rows ||
		i2 + (*p)->piece_cols > (*map)->nb_cols)
		return (1);
	while (++(c.i) < (*p)->piece_rows * (*p)->piece_cols)
	{
		c.pos = i2 + (c.i % (*p)->piece_cols) +
					((i + (c.i / (*p)->piece_cols))
						* (*map)->nb_cols);
		c.pos_c = (*map)->sogm[c.pos];
		if ((*p)->sogp[c.i] == '*' && (
			(c.pos_c == (*map)->player_char[1] || c.pos_c ==
			(*map)->player_char[1] + 32) || (c.pos_c != '.' && c.pos_c !=
			(*map)->player_char[0] && c.pos_c != (*map)->player_char[0] + 32)))
			return (1);
		if ((*p)->sogp[c.i] == '*' &&
				c.pos_c == (*map)->player_char[0])
			(*p)->contact++;
	}
	if (is_placable2(p, i, i2) == 0)
		return (0);
	return (1);
}

void			print_result(t_piece **p, t_sog **map)
{
	ft_putnbr((*p)->return_y);
	ft_putchar(' ');
	ft_putnbr((*p)->return_x);
	ft_putchar('\n');
	(*map)->my_x = (*p)->return_x;
	(*map)->my_y = (*p)->return_y;
}
