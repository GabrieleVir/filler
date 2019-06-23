/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 08:58:38 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 09:13:36 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		big_map(t_sog **map, t_piece **p)
{
	int good_pos;

	get_contact(p, map);
	if ((*p)->contact == 0)
	{
		if ((*map)->my_y < (*map)->enemy_y)
		{
			if (go_contact1(map, p) == 1)
				return (1);
		}
		else if ((*map)->my_y >= (*map)->enemy_y)
		{
			if (go_contact2(map, p) == 1)
				return (1);
		}
	}
	else
	{
		good_pos = algo3(map, p);
		if (good_pos == 0)
			return (1);
	}
	return (0);
}
