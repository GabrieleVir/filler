/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 09:11:28 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/26 05:46:53 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_cont_var(t_contact *info, t_sog **map)
{
	(*info).p1 = (*map)->player_char[0];
	(*info).p1_2 = (*map)->player_char[0] + 32;
	(*info).p2 = (*map)->player_char[1];
	(*info).p2_2 = (*map)->player_char[1] + 32;
}

/*
** dc: down character
** rc: right character
** uc: up character
** lc: left character
*/

static void	init_all_sides_chars(t_sog **map, t_contact *in, int i, int j)
{
	(*in).curr_c = (*map)->sogm[((i - 1) * (*map)->nb_cols) + j - 1];
	if (i - 1 - 3 > 0 && i - 1 + 3 < (*map)->nb_rows)
	{
		if ((*in).curr_c == (*in).p1 || (*in).curr_c == (*in).p1_2)
		{
			(*in).uc = (*map)->sogm[((i - 1 - 3) * (*map)->nb_cols) + j - 1];
			(*in).rc = (*map)->sogm[((i - 1) * (*map)->nb_cols) + j + 3 - 1];
			(*in).dc = (*map)->sogm[((i - 1 + 3) * (*map)->nb_cols) + j];
			(*in).lc = (*map)->sogm[((i - 1) * (*map)->nb_cols) + j - 3 - 1];
		}
	}
}

void		get_contact(t_piece **p, t_sog **map)
{
	int			i;
	int			j;
	t_contact	info;

	init_cont_var(&info, map);
	i = 2;
	while (++i < (*map)->nb_rows - 3)
	{
		j = 2;
		while (++j < (*map)->nb_cols - 3)
		{
			init_all_sides_chars(map, &info, i, j);
			if (info.curr_c == info.p1 || info.curr_c == info.p1_2)
			{
				if (info.rc == info.p2 || info.rc == info.p2_2 ||
				info.uc == info.p2 || info.uc == info.p2_2 ||
				info.lc == info.p2 || info.lc == info.p2_2 ||
				info.dc == info.p2 || info.dc == info.p2_2)
				{
					(*p)->near_contact = 1;
					return ;
				}
			}
		}
	}
}
