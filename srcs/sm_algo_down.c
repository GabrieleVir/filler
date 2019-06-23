/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_algo_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:35:39 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 13:03:18 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			algo_dl(t_sog **map, t_piece **p)
{
	int	i;
	int	i2;
	int	good_pos;

	i = -1;
	(*p)->return_x = 0;
	(*p)->return_y = 0;
	good_pos = 0;
	while (++i < (*map)->nb_rows)
	{
		i2 = (*map)->nb_cols;
		while (--i2 > 0)
		{
			good_pos = is_placable(i, i2, map, p);
			if (good_pos == 0)
			{
				print_result(p, map);
				return (0);
			}
		}
	}
	return (1);
}

int			algo_dr(t_sog **map, t_piece **p)
{
	int	i;
	int	i2;
	int	good_pos;

	i = -1;
	(*p)->return_x = 0;
	(*p)->return_y = 0;
	good_pos = 0;
	while (++i < (*map)->nb_rows - 1)
	{
		i2 = -1;
		while (++i2 < (*map)->nb_cols - 1)
		{
			good_pos = is_placable(i, i2, map, p);
			if (good_pos == 0)
			{
				print_result(p, map);
				return (0);
			}
		}
	}
	return (1);
}
