/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:43:46 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 07:45:48 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		algo_ul(t_sog **map, t_piece **p)
{
	int	i;
	int	i2;
	int	ret;

	i = (*map)->nb_rows;
	(*p)->return_x = 0;
	(*p)->return_y = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = (*map)->nb_cols;
		while (i2 > 0)
		{
			ret = is_placable(i, i2, map, p);
			if (ret == 0)
			{
				print_result(p, map);
				return (0);
			}
			i2--;
		}
		i--;
	}
	return (1);
}

int		algo_ur(t_sog **map, t_piece **p)
{
	int	i;
	int	i2;
	int	ret;

	i = (*map)->nb_rows;
	(*p)->return_x = 0;
	(*p)->return_y = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = -1;
		while (++i2 < (*map)->nb_cols)
		{
			ret = is_placable(i, i2, map, p);
			if (ret == 0)
			{
				print_result(p, map);
				return (0);
			}
		}
		i--;
	}
	return (1);
}
