/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap_xy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 00:46:53 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:14:57 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/visu.h"

static void		ft_getmap_xy_struct(t_mlx *e)
{
	size_t	y;

	y = 0;
	if (!(e->mapxyz = (int **)malloc((e->nbline) * sizeof(int *))))
		exit(EXIT_FAILURE);
	while (y < e->nbline)
	{
		e->mapxyz[y] = (int *)malloc(ft_strlen(e->map[0]) * sizeof(int));
		if (!(e->mapxyz[y]))
			exit(EXIT_FAILURE);
		y++;
	}
}

void			ft_getmap_xy(t_mlx *e, size_t y, size_t x)
{
	int		i;

	if (e->firstround == 0)
		ft_getmap_xy_struct(e);
	while (y < e->nbline)
	{
		i = 0;
		x = 0;
		while (e->map[y][i] != '\0')
		{
			if (e->map[y][i] == '.')
				e->mapxyz[y][x++] = 0;
			else if (e->map[y][i] == 'X')
				e->mapxyz[y][x++] = 1;
			else if (e->map[y][i] == 'x')
				e->mapxyz[y][x++] = 10;
			else if (e->map[y][i] == 'O')
				e->mapxyz[y][x++] = 2;
			else if (e->map[y][i] == 'o')
				e->mapxyz[y][x++] = 20;
			i++;
		}
		y++;
	}
}
