/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:22:50 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/07 22:46:50 by gvirga           ###   ########.fr       */
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

/*
** To get the good coordinates for later I have to remove the /n
*/
static int		piece_no_newline(t_filler_info **info, t_parser **parser)
{
	char	*tmp;
	int		i;
	int		u;

	u = -1;
	i = 0;
	ft_putstr_fd("test2\n", (*parser)->fd);
	if (!(tmp = ft_strdup((*info)->sogp)))
		return (0);
	free((*info)->sogp);
	(*info)->sogp = NULL;
	(*info)->sogp = ft_strnew((*info)->piece_cols * (*info)->piece_rows);
	if (!(*info)->sogp)
		return (0);
	ft_putstr_fd("test1\n", (*parser)->fd);
	while (tmp[++u])
	{
		if (tmp[u] == '*' || tmp[u] == '.')
		{
			((*info)->sogp)[i] = tmp[u];
			i++;
		}
	}
	ft_putstr_fd("test3\n", (*parser)->fd);
	free(tmp);
	return (1);
}

int				get_piece(t_parser **parser, t_filler_info **info)
{
	(*parser)->i = -1;
	if (get_piece_info(parser, info))
	{
		if ((*info)->sogp == NULL)
			(*info)->sogp = ft_strnew(0);
		while (++((*parser)->i) < (*info)->piece_rows)
		{
			get_next_line(STDIN_FILENO, &((*parser)->line));
			if (!((*parser)->line))
				return (error_info_malloc(0, parser, "Memory: get_piece GNL"));
			(*info)->sogp =
				ft_strjoin_free((*info)->sogp, (*parser)->line, 3);
			(*info)->sogp = ft_strjoin_free((*info)->sogp, "\n", 1);
			if ((*info)->sogp == NULL)
				return (error_info_malloc(12, parser, NULL));
		}
	}
	else
		return (error_info_malloc(0, parser, "Get_piece() returned a error"));
	if (!piece_no_newline(info, parser))
		return (error_info_malloc(0, parser, "Memory: piece_no_newline"));
	get_real_width_height_piece(info);
	return (1);
}
