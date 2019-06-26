/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 08:58:38 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/26 03:31:44 by gvirga           ###   ########.fr       */
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
			if (algo_ul(map, p) == 1)
				return (1);
		}
		else if ((*map)->my_y >= (*map)->enemy_y)
		{
			if (algo_dr(map, p) == 1)
				return (1);
		}
	}
	else
	{
		bad_pos = algo_circle(map, p);
		if (bad_pos == 0)
			return (1);
	}
	return (0);
}
