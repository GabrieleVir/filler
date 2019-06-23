/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:37:17 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 09:02:50 by gvirga           ###   ########.fr       */
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
	else if (!(ft_strncmp(line, "$$$ exec p2 : [", 15)))
	{
		(*map)->player_char[0] = 'X';
		(*map)->player_char[1] = 'O';
	}
	else
		return (0);
	free(line);
	return (1);
}

void			get_info_players_on_map(t_sog **map)
{
	int		i;

	if (!(*map)->first_time)
		return ;
	i = -1;
	while ((*map)->sogm[++i])
	{
		if ((*map)->sogm[i] == (*map)->player_char[0])
		{
			(*map)->my_x = i % (*map)->nb_cols;
			(*map)->my_y = i / (*map)->nb_cols;
		}
		if ((*map)->sogm[i] == (*map)->player_char[1])
		{
			(*map)->enemy_x = i % (*map)->nb_cols;
			(*map)->enemy_y = i / (*map)->nb_cols;
		}
	}
	(*map)->first_time = 0;
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
