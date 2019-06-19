/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:17:48 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/07 21:35:34 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_first_line(t_parser **parser, t_filler_info **info)
{
	(*parser)->ret = get_next_line(STDIN_FILENO, &((*parser)->line));
	if ((*parser)->ret == 0)
	{
		free((*parser)->line);
		(*parser)->line = NULL;
		return (0);
	}
	else
	{
		if (!(ft_strncmp((*parser)->line, "$$$ exec p1 : [", 15)))
		{
			(*info)->player_number = 1;
			(*info)->player_char = 'O';
		}
		else if (!(ft_strncmp((*parser)->line, "$$$ exec p2 : [", 15)))
		{
			(*info)->player_number = 2;
			(*info)->player_char = 'X';
		}
		else
			return (0);
	}
	free((*parser)->line);
	(*parser)->line = NULL;
	return (1);
}

int		info_player(t_parser **parser, t_filler_info **info)
{
	if ((*parser)->first_time)
	{
		if (!check_first_line(parser, info))
			return (-1);
	}
	return (1);
}
