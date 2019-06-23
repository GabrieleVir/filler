/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_to_play.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 21:48:51 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 08:10:10 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_format(t_sog **map, char *line)
{
	char		*verif;

	verif = line;
	verif += 8;
	if (*verif < '0' || *verif > '9')
		return (0);
	(*map)->nb_rows = ft_atoi(verif);
	while (*verif && (*verif >= '0' &&
					*verif <= '9'))
		verif += 1;
	if (*verif != '\0')
		verif += 1;
	if (*verif < '0' || *verif > '9')
		return (0);
	(*map)->nb_cols = ft_atoi(verif);
	return (1);
}

static void		fill_sogm(char *line, t_sog **map, int *u)
{
	int			i;

	i = -1;
	while ((line)[++i])
	{
		if (line[i] == '.' || line[i] == 'O' ||
				line[i] == 'X' ||
				line[i] == 'x' || line[i] == 'o')
		{
			if (*u >= (*map)->nb_cols * (*map)->nb_rows)
				return ;
			((*map)->sogm)[++(*u)] = line[i];
		}
	}
}

static void	get_info_players(t_sog **map)
{
	int		i;

	if (!(*map)->first_time)
		return ;
	i = -1;
	while ((*map)->sogm[++i])
	{
		if ((*map)->sogm[i] == (*map)->player_char[0])
		{
			(*map)->my_x = i % (*map)->nb_cols;
			(*map)->my_y = i / (*map)->nb_cols;
		}
		if ((*map)->sogm[i] == (*map)->player_char[1])
		{
			(*map)->enemy_x = i % (*map)->nb_cols;
			(*map)->enemy_y = i / (*map)->nb_cols;
		}
	}
	(*map)->first_time = 0;
}

static int	get_map(t_sog **map)
{
	int		i;
	char	*line;
	int		u;

	u = -1;
	i = 0;
	while (i <= (*map)->nb_rows)
	{
		if (!(get_next_line(0, &line)))
			return (0);
		fill_sogm(line, map, &u);
		ft_strdel(&line);
		i++;
	}
	if (u >= (*map)->nb_cols * (*map)->nb_rows)
		return (0);
	((*map)->sogm)[u] = '\0';
	get_info_players(map);
	return (1);
}

static int	read_sogm(char **line, t_sog **map)
{
	if ((*map)->first_time)
	{
		if (check_format(map, *line) != 1)
			return (0);
		if (!((*map)->sogm = ft_strnew((*map)->nb_rows * (*map)->nb_cols)))
			return (0);
	}
	ft_strdel(line);
	if (!(get_map(map)))
		return (0);
	return (1);
}

int			turn_to_play(t_sog **map, t_piece **p)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau ", 8) == 0)
		{
			if (!(read_sogm(&line, map)))
				return (0);
		}
		else if (ft_strncmp(line, "Piece ", 6) == 0)
		{
			if (!get_piece(&line, p))
				return (0);
			return (1);
		}
		else
			ft_strdel(&line);
	}
    return (1);
}