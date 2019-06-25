/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 15:40:34 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 18:53:22 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/visu.h"

static void		ft_get_result(t_mlx *e, char *line, int cas)
{
	if (cas == 1)
	{
		e->resulto = ft_atoi(&line[10]);
		e->sresulto = ft_strjoin(e->sresulto, "Resultat du premier joueur : ");
		e->sresulto = ft_strjoin(e->sresulto, ft_itoa(e->resulto));
		mlx_string_put(e->mlx, e->win, 200, 50, 0xFFFFFF, e->sresulto);
	}
	if (cas == 2)
	{
		e->resultx = ft_atoi(&line[10]);
		e->sresultx = ft_strjoin(e->sresultx, "Resultat du deuxieme joueur : ");
		e->sresultx = ft_strjoin(e->sresultx, ft_itoa(e->resultx));
		mlx_string_put(e->mlx, e->win, 200, 70, 0xFFFFFF, e->sresultx);
		if (e->resulto > e->resultx)
			mlx_string_put(e->mlx, e->win, 200, 110, 0x0000FF,
				"Le premier joueur a gagne !");
		else if (e->resulto < e->resultx)
			mlx_string_put(e->mlx, e->win, 200, 110, 0xFF0000,
				"Le deuxieme joueur a gagne !");
		else
			mlx_string_put(e->mlx, e->win, 200, 110, 0xFFFFFF, "Egalite !");
	}
}

static void		ft_takemap(t_mlx *e, char *line)
{
	if (e->takemap == 1)
	{
		e->mapjoin = ft_strjoin(e->mapjoin, &line[4]);
		e->mapjoin = ft_strjoin(e->mapjoin, "\n");
		e->nbline++;
	}
	if (e->takemap == 2)
	{
		e->map = ft_strsplit(e->mapjoin, '\n');
		ft_getmap_xy(e, 0, 0);
		ft_put_pixel(e);
		mlx_do_sync(e->mlx);
		e->firstround = 1;
		e->takemap = 0;
	}
}

static void		ft_getline(t_mlx *e)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(ft_strsub(line, 0, 3), "000") == 0)
		{
			e->takemap = 1;
			e->nbline = 0;
			ft_strclr(e->mapjoin);
		}
		if (ft_strcmp(ft_strsub(line, 0, 5), "Piece") == 0)
			e->takemap = 2;
		ft_takemap(e, line);
		if (ft_strcmp(ft_strsub(line, 0, 8), "== O fin") == 0)
			ft_get_result(e, line, 1);
		if (ft_strcmp(ft_strsub(line, 0, 8), "== X fin") == 0)
			ft_get_result(e, line, 2);
	}
}

static int		ft_key_hook(int keycode, t_mlx *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(EXIT_FAILURE);
	}
	if (keycode == 36 && e->start == 0)
	{
		e->start = 1;
		mlx_clear_window(e->mlx, e->win);
		ft_getline(e);
	}
	return (0);
}

int				main(void)
{
	t_mlx e;

	e.winx = 1500;
	e.winy = 1000;
	e.start = 0;
	e.takemap = 0;
	e.nbline = 0;
	e.firstround = 0;
	e.sresulto = "\0";
	e.sresultx = "\0";
	e.mapjoin = "\0";
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.winx, e.winy, "Filler Visualisateur 2.0");
	mlx_string_put(e.mlx, e.win, 500, 500, 0xFFFFFF,
		"Appuyez sur entree pour commencer le combat !");
	mlx_hook(e.win, 2, 0, ft_key_hook, &e);
	mlx_loop(e.mlx);
}
