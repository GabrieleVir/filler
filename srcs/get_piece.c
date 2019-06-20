/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:22:50 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/11 15:21:36 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_piece_info(t_parser **parser, t_filler_info **info)
{
	char		*verif;

	verif = (*parser)->line;
	if (ft_strncmp(verif, "Piece ", 6) > 0)
		return (error_str_fd("VM format not valid", (*parser)->fd));
	verif += 6;
	if (*verif < '0' || *verif > '9')
		return (error_str_fd("VM format not valid", (*parser)->fd));
	(*info)->piece_rows = ft_atoi(verif);
	while (*verif && (*verif >= '0' &&
					*verif <= '9'))
		verif += 1;
	if (*verif)
		verif += 1;
	if (*verif < 0 || *verif > '9')
		return (error_str_fd("VM format not valid", (*parser)->fd));
	(*info)->piece_cols = ft_atoi(verif);
	return (1);
}

static int		malloc_sogp(t_filler_info **info, t_parser **parser)
{
	free((*info)->sogp);
	if (!((*info)->sogp = ft_strnew((*info)->piece_rows * (*info)->piece_cols)))
		return (error_info_malloc(12, parser, NULL));
	return (1);
}

static void		fill_sogp(t_filler_info **info, t_parser **parser, int *u)
{
	int			i;

	i = -1;
	while (((*parser)->line)[++i])
	{
		if (((*parser)->line)[i] == '.' || ((*parser)->line)[i] == '*')
			((*info)->sogp)[++(*u)] = ((*parser)->line)[i];
	}
}

int				get_piece(t_parser **parser, t_filler_info **info)
{
	int		u;

	u = -1;
	(*parser)->i = -1;
	if (get_piece_info(parser, info) && malloc_sogp(info, parser))
	{
		while (++((*parser)->i) < (*info)->piece_rows)
		{
			if (!(get_next_line(STDIN_FILENO, &((*parser)->line))))
				return (error_info_malloc(12, parser, NULL));
			fill_sogp(info, parser, &u);
			free((*parser)->line);
			(*parser)->line = NULL;
		}
	}
	else
		return (error_info_malloc(0, parser, "Get_piece() returned a error"));
	get_real_width_height_piece(info);
	return (1);
}
