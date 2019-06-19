/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lbl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:16:12 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/19 16:16:15 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	add_col_or_row(t_place **c, t_filler_info **info,
							t_parser **parser, int *pos)
{
	if (((*c)->i) % (*info)->piece_cols == (*info)->piece_cols - 1)
	{
		if ((((*pos) + (*info)->nb_cols) /
				(*info)->nb_cols) < (*info)->nb_rows)
		{
			*pos += (*info)->nb_cols;
			*pos -= (*info)->piece_cols - 1;
		}
		else
			return (0);
	}
	else
	{
		if (((*pos) + 1) % (*info)->nb_cols > 0)
			*pos += 1;
		else
			return (0);
	}
	((*c)->i)++;
	return (1);
}

static int	check_if_fit(t_filler_info **info, t_parser **parser, t_place **c)
{
	(*c)->posf = (*c)->pos;
	(*c)->contact = 0;
	(*c)->i = 0;
	while (((*info)->sogp)[(*c)->i])
	{
		if (((*info)->sogp)[(*c)->i] == '*' &&
			((*info)->sogm)[(*c)->posf] == (*info)->player_char)
		{
			((*c)->contact)++;
			(*c)->result = add_col_or_row(c, info, parser, &((*c)->posf));
		}
		else if (((*info)->sogp)[(*c)->i] == '*' &&
					((*info)->sogm)[(*c)->posf] == '.')
			(*c)->result = add_col_or_row(c, info, parser, &((*c)->posf));
		else if (((*info)->sogp)[(*c)->i] == '.')
			(*c)->result = add_col_or_row(c, info, parser, &((*c)->posf));
		else
			return (0);
		if (!(*c)->result || (*c)->contact > 1)
			return (0);
	}
	if ((*c)->contact == 0)
		return (0);
	return (1);
}

/*
** Change how to find a contact point
*/

static int	change_return_values(t_filler_info **info,
									t_place **c, t_parser **parser)
{
	if ((*c)->i % (*info)->piece_cols == (*info)->piece_cols - 1)
	{
		if ((*info)->return_values[0] == 0)
			return (0);
		(*info)->return_values[0] -= 1;
		(*info)->return_values[1] += (*info)->piece_cols - 1;
		(*c)->pos += (*info)->piece_cols - 1;
		(*c)->pos -= (*info)->nb_cols;
	}
	else
	{
		if ((*info)->return_values[1] == 0)
			return (0);
		((*c)->pos)--;
		(*info)->return_values[1] -= 1;
	}
	(*c)->i += 1;
	return (1);
}

static int	is_placable(t_filler_info **info, t_parser **parser)
{
	t_place *c;

	if (!(c = (t_place *)malloc(sizeof(t_place))))
		return (0);
	c->pos = (*info)->pos;
	c->i = 0;
	(*info)->return_values[0] = (*info)->pos / (*info)->nb_cols;
	(*info)->return_values[1] = (*info)->pos % (*info)->nb_cols;
	while (c->i < (*info)->piece_cols * (*info)->piece_rows)
	{
		while ((*info)->sogp[c->i] != '*' && (*info)->sogp[c->i] != '\0')
			if (!change_return_values(info, &c, parser))
				return (0);
		if ((*info)->sogp[c->i])
		{
			if (check_if_fit(info, parser, &c))
				return (1);
			if (!change_return_values(info, &c, parser))
				return (0);
		}
	}
	return (0);
}

/*
** Find available position nearest of the top
*/

int			fill_lbl(t_filler_info **info, t_parser **parser)
{
	(*info)->pos = 0;
	while (((*info)->pos) < (*info)->nb_rows * (*info)->nb_cols)
	{
		if (((*info)->sogm)[(*info)->pos] == (*info)->player_char)
		{
			if (is_placable(info, parser))
				return (1);
		}
		(*info)->pos += 1;
	}
	return (0);
}
