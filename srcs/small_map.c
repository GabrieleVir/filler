/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:39:01 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 00:42:55 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		small_map(t_sog **map, t_piece **p)
{
	if ((*map)->my_y < ((*map)->nb_rows / 2))
	{
		if ((*map)->my_x < ((*map)->nb_cols / 2))
		{
			if (algo_dl(map, p) == 1)
				return (1);
		}
		else if ((*map)->my_x >= ((*map)->nb_cols / 2))
			if (algo_dr(map, p) == 1)
				return (1);
	}
	else if ((*map)->my_y >= ((*map)->nb_rows / 2))
	{
		if ((*map)->my_x < ((*map)->nb_cols / 2))
		{
			if (algo_ul(map, p) == 1)
				return (1);
		}
		else if ((*map)->my_x >= ((*map)->nb_cols / 2))
			if (algo_ur(map, p) == 1)
				return (1);
	}
	return (0);
}