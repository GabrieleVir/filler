/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 02:09:32 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:15:01 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/visu.h"

static int		ft_get_color(t_mlx *e, int y, int x)
{
	if (e->mapxyz[y][x] == 1)
		return (0xFF0000);
	else if (e->mapxyz[y][x] == 10)
		return (0x550000);
	else if (e->mapxyz[y][x] == 2)
		return (0x0000FF);
	else if (e->mapxyz[y][x] == 20)
		return (0x000055);
	else
		return (0xFFFFFF);
}

int				ft_put_pixel_first_round(t_mlx *e, size_t y, size_t x)
{
	size_t	tmpx;
	size_t	tmpy;

	if ((e->mapxyz[y][x] >= e->mapxyz[y][x + 1] ||
		e->mapxyz[y][x] < e->mapxyz[y][x + 1]) && x < ft_strlen(e->map[y]) - 1)
	{
		tmpx = (x * 10);
		while (tmpx < ((x + 1) * 10))
			mlx_pixel_put(e->mlx, e->win, 200 + tmpx++, 200 + (y * 10),
			ft_get_color(e, y, x));
	}
	if (y < e->nbline - 1 && (e->mapxyz[y][x] >= e->mapxyz[y + 1][x] ||
		e->mapxyz[y][x] < e->mapxyz[y + 1][x]) && x < ft_strlen(e->map[y + 1]))
	{
		tmpy = (y * 10);
		while (tmpy < ((y + 1) * 10))
			mlx_pixel_put(e->mlx, e->win, 200 + (x * 10), 200 + tmpy++,
			ft_get_color(e, y, x));
	}
	return (++x);
}

int				ft_put_pixel_other_round(t_mlx *e, size_t y, size_t x)
{
	size_t	tmpx;
	size_t	tmpy;

	if (x + 1 < ft_strlen(e->map[y]) && e->mapxyz[y][x] != 0 &&
	e->mapxyz[y][x + 1] != 0)
		if ((e->mapxyz[y][x] >= e->mapxyz[y][x + 1] ||
			e->mapxyz[y][x] < e->mapxyz[y][x + 1]) &&
			x < ft_strlen(e->map[y]) - 1)
		{
			tmpx = (x * 10);
			while (tmpx < ((x + 1) * 10))
				mlx_pixel_put(e->mlx, e->win, 200 + tmpx++, 200 + (y * 10),
				ft_get_color(e, y, x));
		}
	if (y + 1 < e->nbline && e->mapxyz[y][x] != 0 && e->mapxyz[y + 1][x] != 0)
		if (y < e->nbline - 1 && (e->mapxyz[y][x] >= e->mapxyz[y + 1][x] ||
			e->mapxyz[y][x] < e->mapxyz[y + 1][x]) &&
			x < ft_strlen(e->map[y + 1]))
		{
			tmpy = (y * 10);
			while (tmpy < ((y + 1) * 10))
				mlx_pixel_put(e->mlx, e->win, 200 + (x * 10), 200 + tmpy++,
				ft_get_color(e, y, x));
		}
	return (++x);
}

void			ft_put_pixel(t_mlx *e)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < e->nbline)
	{
		x = 0;
		while (x < ft_strlen(e->map[0]))
		{
			if (e->firstround == 0)
				x = ft_put_pixel_first_round(e, y, x);
			else
				x = ft_put_pixel_other_round(e, y, x);
		}
		y++;
	}
}
