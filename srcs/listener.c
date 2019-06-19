/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 04:27:43 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/14 04:27:46 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		vm_listener(t_parser **parser, t_filler_info **info)
{
	while (((*parser)->ret = get_next_line(STDIN_FILENO, &((*parser)->line))) > 0)
	{
		if (ft_strncmp((*parser)->line, "Plateau ", 8) == 0)
		{
			if (!(read_sogm(parser, info)))
				return (0);

		}
		else if (ft_strncmp((*parser)->line, "Piece ", 6) == 0)
		{
			if (!get_piece(parser, info))
				return (0);
			break ;
		}
		else
		{
			free((*parser)->line);
			(*parser)->line = NULL;
		}
	}
    return (1);
}
