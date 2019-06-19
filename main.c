/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:26:25 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/07 17:25:30 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** The main will init the struct variables and
** launch an infinite loop and there are 3 things it does in this loop:
** 1) The first time it runs, it will put all the info necessary for the
** rest of the program (player 1 or player 2, player_char, char * to NULL)
** 2) Loop to see if there is the "Plateau" or "Piece" line and then get
** all the infos like the sogm (State of Game map) necessary to play
** 3) Launching the algorithm that will find good positions to give back
** to the vm and apply the different strategies.
*/

int		main(void)
{
	t_parser		*parser;
	t_filler_info	*info;

	init_variables(&parser, &info);
	while (1)
	{
		if (!info_player(&parser, &info))
		{
			break ;
		}
		if (!vm_listener(&parser, &info))
		{
			break ;
		}
		if (parser->ret < 0)
		{
			break ;
		}
		if (!fill_map(&info, &parser))
			break ;
	}
	free(info->sogm);
	free(info->sogp);
	return (0);
}
