/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:00:42 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/26 07:13:31 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		last_try(t_sog **map, t_piece **p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	(*p)->return_x = 0;
	(*p)->return_y = 0;
	ret = 0;
	while (++i < (*map)->nb_rows - 1)
	{
		i2 = -1;
		while (++i2 < (*map)->nb_cols - 1)
		{
			ret = is_placable(i, i2, map, p);
			if (ret == 0)
			{
				print_result(p, map);
				return (0);
			}
		}
	}
	return (1);
}

int				main(void)
{
	t_sog	*map;
	t_piece	*piece_info;

	if (!(init_variables(&map, &piece_info)) ||
				!(info_player(&map, &piece_info)))
		return (0);
	while (1)
	{
		if (turn_to_play(&map, &piece_info))
		{
			if (play(&map, &piece_info))
			{
				if (last_try(&map, &piece_info) == 1)
				{
					print_result(&piece_info, &map);
					break ;
				}
			}
		}
	}
	free(piece_info->sogp);
	free(map->sogm);
	free(map);
	free(piece_info);
}
