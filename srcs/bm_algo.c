/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bm_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 10:07:36 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/26 05:19:12 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		init_around_points(t_contact *in, t_piece **p, int u,
									t_sog **map)
{
	(*in).irc = (((*in).i + (*in).y) * (*map)->nb_cols) +
					(u + (*in).x + (*in).around_i);
	(*in).idc = (((*in).i + (*in).y + (*in).around_i) *
					(*map)->nb_cols) + (u + (*in).x);
	(*in).ilc = (((*in).i + (*in).y) * (*map)->nb_cols) +
					(u + (*in).x - (*in).around_i);
	(*in).iuc = (((*in).i + (*in).y - (*in).around_i) *
					(*map)->nb_cols) + (u + (*in).x);
}

static void		check_adjacent_points(t_contact *in, t_piece **p, int u,
									t_sog **map)
{
	(*in).around_i = 0;
	while (++((*in).around_i) < 4)
	{
		init_around_points(in, p, u, map);
		if ((u + (*in).x + (*in).around_i) < (*map)->nb_cols &&
				(u + (*in).x - (*in).around_i) > 0 && ((*in).i + (*in).y +
				(*in).around_i) < (*map)->nb_rows && ((*in).i + (*in).y -
				(*in).around_i) > 0)
			if ((*map)->sogm[(*in).irc] == (*in).p2
			|| (*map)->sogm[(*in).irc] == (*in).p2_2
			|| (*map)->sogm[(*in).ilc] == (*in).p2
			|| (*map)->sogm[(*in).ilc] == (*in).p2_2
			|| (*map)->sogm[(*in).idc] == (*in).p2
			|| (*map)->sogm[(*in).idc] == (*in).p2_2
			|| (*map)->sogm[(*in).iuc] == (*in).p2
			|| (*map)->sogm[(*in).iuc] == (*in).p2_2)
				(*p)->contact_counter += (4 - (*in).around_i);
	}
}

static int		result_printing(int nbr_contact, t_piece **p, t_sog **map)
{
	if (nbr_contact == -1)
		return (0);
	(*p)->return_x = (*p)->tmp_x;
	(*p)->return_y = (*p)->tmp_y;
	print_result(p, map);
	return (1);
}

static int		count_contact(t_sog **map, t_piece **p, int y, int x)
{
	int			u;
	t_contact	in;

	in.i = -1;
	in.x = x;
	in.y = y;
	in.p2 = (*map)->player_char[1];
	in.p2_2 = (*map)->player_char[1] + 32;
	(*p)->contact_counter = 0;
	while (++(in.i) < (*p)->piece_rows)
	{
		u = -1;
		while (++u < (*p)->piece_cols)
			if ((*p)->sogp[((in.i) * (*p)->piece_cols) + u] == '*')
				check_adjacent_points(&in, p, u, map);
	}
	return ((*p)->contact_counter);
}

int				algo_circle(t_sog **map, t_piece **p)
{
	int	i;
	int	i2;
	int	contact_counter_tmp;
	int	nbr_contact;

	nbr_contact = -1;
	i = (*map)->nb_rows - ((*p)->piece_rows - (*p)->end_y);
	(*p)->tmp_x = 0;
	(*p)->tmp_y = 0;
	while (--i >= 0)
	{
		i2 = (*map)->nb_cols - ((*p)->piece_cols - (*p)->end_x);
		while (--i2 >= 0)
			if (is_placable(i, i2, map, p) == 0)
			{
				contact_counter_tmp = count_contact(map, p, i, i2);
				if (contact_counter_tmp > nbr_contact)
				{
					nbr_contact = contact_counter_tmp;
					(*p)->tmp_x = i2;
					(*p)->tmp_y = i;
				}
			}
	}
	return (result_printing(nbr_contact, p, map));
}
