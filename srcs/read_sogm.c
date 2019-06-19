/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sogp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:21:38 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/07 22:23:55 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_format(t_parser **parser, t_filler_info **info)
{
	char		*verif;

	verif = (*parser)->line;
	verif += 8;
	if (*verif < '0' || *verif > '9')
		return (error_str_fd("VM format not valid", (*parser)->fd));
	(*info)->nb_rows = ft_atoi(verif);
	while (*verif && (*verif >= '0' &&
					*verif <= '9'))
		verif += 1;
	if (*verif != '\0')
		verif += 1;
	if (*verif < '0' || *verif > '9')
		return (error_str_fd("VM format not valid", (*parser)->fd));
	(*info)->nb_cols = ft_atoi(verif);
	return (1);
}

static int		get_plateau_size(t_filler_info **info, t_parser **parser)
{
	if ((*parser)->first_time && (*parser)->ret > 0)
	{
		if (check_format(parser, info) != 1)
			return (error_free_line(parser));
		if (!((*info)->sogm = ft_strnew((*info)->nb_rows * (*info)->nb_cols)))
			return (error_info_malloc(12, parser, NULL));
		free(((*parser)->line));
		(*parser)->line = NULL;
		(*parser)->first_time = 0;
		return (1);
	}
	if ((*parser)->ret <= 0)
		return (error_msg_fd(12, (*parser)->fd));
	free(((*parser)->line));
	(*parser)->line = NULL;
	return (1);
}

static void		fill_sogm(t_filler_info **info, t_parser **parser, int *u)
{
	int			i;

	i = -1;
	while (((*parser)->line)[++i])
	{
		if (((*parser)->line)[i] == '.' || ((*parser)->line)[i] == 'O' ||
				((*parser)->line)[i] == 'X' ||
				((*parser)->line)[i] == 'x' || ((*parser)->line)[i] == 'o')
		{
			if (*u >= (*info)->nb_cols * (*info)->nb_rows)
				return ;
			((*info)->sogm)[++(*u)] = ((*parser)->line)[i];
		}
	}
}

int				read_sogm(t_parser **parser, t_filler_info **info)
{
	int		u;

	u = -1;
	(*parser)->i = -1;
	if (get_plateau_size(info, parser))
	{
		while (++((*parser)->i) <= (*info)->nb_rows)
		{
			if (!(get_next_line(STDIN_FILENO, &((*parser)->line))))
				return (error_info_malloc(12, parser, NULL));
			fill_sogm(info, parser, &u);
			free((*parser)->line);
			(*parser)->line = NULL;
		}
		if (u >= (*info)->nb_cols * (*info)->nb_rows)
			return (0);
		((*info)->sogm)[++u] = '\0';
	}
	else
		return (error_info_malloc(0, parser,
					"Get_plateau_size() returned a error"));
	return (1);
}
