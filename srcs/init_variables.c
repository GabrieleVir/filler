/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:02:37 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/22 20:17:10 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_variables(t_sog **map, t_piece **piece)
{
	if (!(*map = (t_sog *)malloc(sizeof(t_sog))))
		return (0);
	if (!(*piece = (t_piece *)malloc(sizeof(t_piece))))
	{
		free(map);
		return (0);
	}
	map->map = NULL;
	map->player_char[0] = 0;
	map->player_char[1] = 0;
	map->width = 0;
	map->height = 0;
	map->enemy_x = 0;
	map->enemy_y = 0;
	map->my_x = 0;
	map->my_y = 0;
	p->contact = 0;
	p->tmp_x = 0;
	p->tmp_y = 0;
	p->contact = 0;
	p->init_x = 0;
	p->end_x = 0;
	p->init_y = 0;
	p->end_y = 0;
}
