/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 08:58:38 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 14:59:52 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		big_map(t_sog **map, t_piece **p)
{
	int bad_pos;

	get_contact(p, map);
	if ((*p)->near_contact == 0)
	{
		if ((*map)->my_y < (*map)->enemy_y)
		{
			dprintf((*p)->fd, "here1?\n");
			if (algo_ul(map, p) == 1)
				return (1);
		}
		else if ((*map)->my_y >= (*map)->enemy_y)
		{
			dprintf((*p)->fd, "there?\n");
			if (algo_dr(map, p) == 1)
				return (1);
		}
	}
	else
	{
		dprintf((*p)->fd, "here?\n");
		bad_pos = algo_approach(map, p);
		if (bad_pos == 0)
			return (1);
	}
	return (0);
}
