/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:10:43 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/29 21:24:10 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_piece_info(t_piece **p, char **line)
{
	char		*verif;

	verif = *line;
	if (ft_strncmp(verif, "Piece ", 6) > 0)
		return (0);
	verif += 6;
	if (*verif < '0' || *verif > '9')
		return (0);
	(*p)->piece_rows = ft_atoi(verif);
	while (*verif && (*verif >= '0' &&
					*verif <= '9'))
		verif += 1;
	if (*verif)
		verif += 1;
	if (*verif < 0 || *verif > '9')
		return (0);
	(*p)->piece_cols = ft_atoi(verif);
	ft_strdel(line);
	return (1);
}

static void	fill_sogp(char **line, t_piece **p, int *u)
{
	int			i;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == '.' || (*line)[i] == '*')
			((*p)->sogp)[++(*u)] = (*line)[i];
	}
}

static int	malloc_sogp(t_piece **p, char **line)
{
	if ((*p)->sogp != NULL)
		ft_strdel(&((*p)->sogp));
	if (!((*p)->sogp = ft_strnew((*p)->piece_rows * (*p)->piece_cols)))
		return (0);
	return (1);
}

static void	get_real_width_height_piece(t_piece **p)
{
	int		i;

	i = -1;
	(*p)->init_x = (*p)->piece_cols;
	(*p)->init_y = (*p)->piece_rows;
	while ((*p)->sogp[++i])
	{
		if ((*p)->sogp[i] == '*')
		{
			if (i % (*p)->piece_cols < (*p)->init_x)
				(*p)->init_x = i % (*p)->piece_cols;
			if (i % (*p)->piece_cols > (*p)->end_x)
				(*p)->end_x = i % (*p)->piece_cols;
			if (i / (*p)->piece_cols < (*p)->init_y)
				(*p)->init_y = i / (*p)->piece_cols;
			if (i / (*p)->piece_cols > (*p)->end_y)
				(*p)->end_y = i / (*p)->piece_cols;
		}
	}
}

int			get_piece(char **line, t_piece **p)
{
	int		u;
	int		i;

	u = -1;
	i = -1;
	if (get_piece_info(p, line) && malloc_sogp(p, line))
	{
		while (++i < (*p)->piece_rows)
		{
			if (!(get_next_line(0, line)))
				return (0);
			fill_sogp(line, p, &u);
			ft_strdel(line);
		}
	}
	else
		return (0);
	get_real_width_height_piece(p);
	return (1);
}
