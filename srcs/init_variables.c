/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:20:16 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/07 15:38:56 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		init_variables(t_parser **parser, t_filler_info **info)
{
	if (!(*parser = (t_parser*)malloc(sizeof(t_parser))))
		return (error_msg_fd(12, (*parser)->fd));
	(*parser)->fd = open("./program.trace", O_WRONLY);
	(*parser)->first_time = 1;
	if (!(*info = (t_filler_info*)malloc(sizeof(t_filler_info))))
		return (error_info_malloc(12, parser, NULL));
	(*info)->sogm = NULL;
	(*info)->sogp = ft_strnew(0);
	(*info)->player_number = 0;
	return (1);
}
