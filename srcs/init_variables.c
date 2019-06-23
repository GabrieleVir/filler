/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:02:37 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 09:10:41 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		init_piece_variables(t_piece **piece)
{
	(*piece)->sogp = NULL;
	(*piece)->contact = 0;
	(*piece)->tmp_x = 0;
	(*piece)->tmp_y = 0;
	(*piece)->contact = 0;
	(*piece)->init_x = 0;
	(*piece)->end_x = 0;
	(*piece)->init_y = 0;
	(*piece)->end_y = 0;
}

int				init_variables(t_sog **map, t_piece **piece)
{
	if (!(*map = (t_sog *)malloc(sizeof(t_sog))))
		return (0);
	if (!(*piece = (t_piece *)malloc(sizeof(t_piece))))
	{
		free(map);
		return (0);
	}
	(*map)->sogm = NULL;
	(*map)->player_char[0] = 0;
	(*map)->player_char[1] = 0;
	(*map)->nb_cols = 0;
	(*map)->nb_rows = 0;
	(*map)->enemy_x = 0;
	(*map)->enemy_y = 0;
	(*map)->my_x = 0;
	(*map)->my_y = 0;
	(*map)->first_time = 1;
	init_piece_variables(piece);
	return (1);
}
