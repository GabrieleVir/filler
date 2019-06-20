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
**
*/

static int	init_vars(t_filler_info **info, t_place **c, int iteration)
{
	if (!((*c) = (t_place *)malloc(sizeof(t_place))))
		return (0);
	if (iteration == 0)
	{
		return (0);
	}
	else if (iteration == 1)
	{
		(*c)->target = 0;
		(*c)->pos = 0;
	}
	return (1);
}

static int	init_vars_target(t_place **c)
{
	(*c)->pos = (*c)->target < 
}

int			fill_ulc(t_filler_info **info, t_parser **parser, t_place **c)
{
		init_vars_target(c);
}

/*
** Fulc: Fill up left corner
** Flbl: Fill line by line
*/

int			fill_map(t_filler_info **info, t_parser **parser)
{
	t_place *coords;

	set_target(&coords, 1);
	if (fill_ulc(info, parser, &coords))
	{

	}
	else if (fill_lbl(info, parser))
	{
		ft_putstr_fd(ft_itoa((*info)->return_values[0]), 1);
		ft_putstr_fd(" ", 1);
		ft_putstr_fd(ft_itoa((*info)->return_values[1]), 1);
		ft_putstr_fd("\n", 1);
		return (1);
	}
	return (0);
}
