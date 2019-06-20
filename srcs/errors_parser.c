/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 05:42:11 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/06 04:17:43 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		error_info_malloc(int err_nb, t_parser **parser, char *err_str)
{
	if (err_str == NULL)
		error_msg_fd(err_nb, (*parser)->fd);
	else
	{
		if (*parser)
			error_str_fd(err_str, (*parser)->fd);
	}
	free(*parser);
	return (0);
}

int		error_free_line(t_parser **parser)
{
	free((*parser)->line);
	return (0);
}
