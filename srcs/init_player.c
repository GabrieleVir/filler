/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:37:17 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/22 20:37:36 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_first_line(t_sog **map)
{
	char		*line;

	get_next_line(0, &line);
	if (!(ft_strncmp(line, "$$$ exec p1 : [", 15)))
	{
		(*map)->player_char[0] = 'O';
		(*map)->player_char[1] = 'X';
	}
	else if (!(ft_strncmp((*parser)->line, "$$$ exec p2 : [", 15)))
	{
		(*map)->player_char[0] = 'X';
		(*map)->player_char[1] = 'O';
	}
	else
		return (0);
	free(line);
	return (1);
}

int				info_player(t_sog **map, t_piece **piece)
{
	if (!check_first_line(map))
	{
		free(map);
		free(piece);
		return (0);
	}
	return (1);
}
