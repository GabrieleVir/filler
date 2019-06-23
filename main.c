/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:00:42 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 02:47:48 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
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

			}
			else
				break ;
		}
	}
	free(piece_info->sogp);
	free(map);
	free(piece_info);
}