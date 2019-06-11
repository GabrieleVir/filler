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

int		main(void)
{
	t_parser		*parser;
	t_filler_info	*info;

	// for debugging
	init_variables(&parser, &info);
	while (1)
	{
		// parsing first
		if (!info_player(&parser, &info))
			return (-1);
		// read state of game part
		while ((parser->ret =
					get_next_line(STDIN_FILENO, &(parser->line))) > 0)
		{
			if (ft_strncmp(parser->line, "Plateau ", 8) == 0)
				read_sogp(&parser, &info);
			else if (ft_strncmp(parser->line, "Piece ", 6) == 0)
			{
				if (!get_piece(&parser, &info))
					return (-1);
				break ;
			}
			else
				free(parser->line);
		}
		if (parser->ret <= 0)
			return (-1);
		if (!fill_map(&info, &parser))
			return (-1);
		free((info)->sogp);
		free((info)->sogm);
		info->sogp = NULL;
		info->sogm = NULL;
// debug
	//	write(parser->fd, parser->line, ft_strlen(parser->line));
	//	write(parser->fd, "\n", 1);
		// algo
//		choose_strat(map, piece);
		// response to vm
//		free(parser->line);
//		parser->line = NULL;*/
	}
	return (0);
}
