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
		if (*((*parser)->line))
		{
			if (check_format(parser, info) != 1)
				return (error_free_line(parser));
		}
		(*parser)->first_time = 0;
		free(((*parser)->line));
		return (1);
	}
	if ((*parser)->ret <= 0)
		return (error_msg_fd(12, (*parser)->fd));
	free(((*parser)->line));
	return (1);
}

/*
** To get the good coordinates when I ll try to place a piece
*/

static int		get_plat_right(t_filler_info **info, t_parser **parser)
{
	char	*tmp;
	int		u;

	u = -1;
	if (!(tmp = ft_strdup((*info)->sogm)))
		return (0);
	free((*info)->sogm);
	(*info)->sogm = NULL;
	(*info)->sogm = ft_strnew((*info)->nb_rows * (*info)->nb_cols);
	if (!(*info)->sogm)
		return (0);
	(*parser)->i = 0;
	while (tmp[++u])
	{
		if (tmp[u] == '.' || tmp[u] == 'x' || tmp[u] == 'X' || tmp[u] == 'O' ||
			tmp[u] == 'o')
		{
			((*info)->sogm)[(*parser)->i] = tmp[u];
			(*parser)->i += 1;
		}
	}
	free(tmp);
	return (1);
}

int				read_sogp(t_parser **parser, t_filler_info **info)
{
	(*parser)->i = -1;
	if (get_plateau_size(info, parser))
	{
		if ((*info)->sogm == NULL)
			(*info)->sogm = ft_strnew(0);
		while (++((*parser)->i) < (*info)->nb_rows + 1)
		{
			get_next_line(STDIN_FILENO, &((*parser)->line));
			if (!((*parser)->line))
				return (error_info_malloc(12, parser, NULL));
			(*info)->sogm =
				ft_strjoin_free((*info)->sogm, (*parser)->line, 3);
			(*info)->sogm = ft_strjoin_free((*info)->sogm, "\n", 1);
			if ((*info)->sogm == NULL)
				return (error_info_malloc(12, parser, NULL));
		}
		if (!get_plat_right(info, parser))
			return (error_info_malloc(0, parser, "Memory: get_plat_right"));
		//ft_putstr_fd((*info)->sogm, (*parser)->fd);
	}
	else
		return (error_info_malloc(0, parser,
					"Get_plateau_size() returned a error"));
	return (1);
}
