/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:26:11 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/19 16:26:35 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Flbl: Fill line by line
*/

int		fill_map(t_filler_info **info, t_parser **parser)
{
	char	*str;

	if (fill_lbl(info, parser))
	{
		ft_putstr_fd(ft_itoa((*info)->return_values[0]), 1);
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(ft_itoa((*info)->return_values[1]), 1);
		ft_putstr_fd("\n", 1);
		return (1);
	}
	return (0);
}
