/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:34:13 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 00:36:14 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		play(t_sog **map, t_piece **p)
{
	if ((*map)->nb_rows < 20)
		return (small_map(map, p));
	if ((*map)->nb_rows >= 20)
		return (big_map(map, p));
	return (0);
}