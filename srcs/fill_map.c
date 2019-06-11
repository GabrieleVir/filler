/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:26:11 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/11 15:49:14 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	add_col_or_row(t_place *c, int *pos, t_filler_info **info, t_parser **parser)
{
	if (((*c).i) % (*info)->piece_cols == (*info)->piece_cols - 1)
	{
		if (((*pos) + (*info)->nb_cols) /
				(*info)->nb_cols < (*info)->nb_cols)
		{
			(*pos) += (*info)->nb_cols;
			(*pos) -= (*info)->piece_cols - 1;
		}
		else
			return (0);
	}
	else if ((((*pos) + 1) % (*info)->nb_cols) < (*info)->nb_cols)
		(*pos)++;
	else
		return (0);
	(*c).i++;
	return (1) ;
}

static int	check_if_fit(t_filler_info **info, t_parser **parser, t_place c)
{
	int		pos;
	int		result;
	int		contact;

	contact = 0;
	pos = (*info)->pos;
	c.i = 0;
	// ft_putstr_fd((*info)->sogp, (*parser)->fd);
	// ft_putstr_fd("\n", (*parser)->fd);
	// ft_putnbr_fd(c.i, (*parser)->fd);
	while (((*info)->sogp)[c.i])
	{
		if (((*info)->sogp)[c.i] == '*' &&
			((*info)->sogm)[pos] == (*info)->player_char)
		{
			contact++;
			result = add_col_or_row(&c, &pos, info, parser);
		}
		else if (((*info)->sogp)[c.i] == '*' && ((*info)->sogm)[pos] == '.')
			result = add_col_or_row(&c, &pos, info, parser);
		else if (((*info)->sogp)[c.i] == '.')
			result = add_col_or_row(&c, &pos, info, parser);
		else
			return (0);
		if (!result || contact > 1)
			return (0);
	}
	ft_putnbr_fd(contact, (*parser)->fd);
	return (1);
}

/*
** Change how to find a contact point
*/

static int	is_placable(t_filler_info **info, t_parser **parser)
{
	t_place coords;
	int		pos;

	pos = (*info)->pos;
	coords.i = 0;
	(*info)->return_values[0] = (*info)->pos / (*info)->nb_cols;
	(*info)->return_values[1] = (*info)->pos % (*info)->nb_cols;
	(*info)->contact_pos[0] = (*info)->return_values[0];
	(*info)->contact_pos[1] = (*info)->return_values[1];
	while (((*info)->sogp)[coords.i] && ((*info)->sogp)[coords.i] != '*')
	{
		if (coords.i != 0 && coords.i % (*info)->piece_cols == (*info)->piece_cols - 1)
		{
			if ((*info)->return_values[0] > 0)
			{
				(*info)->return_values[0] -= 1;
				(*info)->return_values[1] += (*info)->piece_cols - 1;
				pos += (*info)->piece_cols - 1;
				pos -= (*info)->nb_cols;
			}
			else
				return (0);
		}
		else
		{
			if ((*info)->return_values[1] > 0)
			{
				(*info)->return_values[1] -= 1;
				pos -= 1;
			}
			else
				return (0);
		}
		coords.i++;
	}
	if (check_if_fit(info, parser, coords))
		return (1);
	else
		return (0);
	return (1);
}

/*
** Find available position nearest of the top
*/
static int	get_contact(t_filler_info **info, t_parser **parser)
{

	(*info)->pos = -1;
	while (++((*info)->pos) < (*info)->nb_rows * (*info)->nb_cols)
	{
		if (((*info)->sogm)[(*info)->pos] == (*info)->player_char)
		{
			if (is_placable(info, parser))
				return (1);
		}
	}
	return (0);
}

int		fill_map(t_filler_info **info, t_parser **parser)
{
	char	*str;
	// char	*play_str;

	if (get_contact(info, parser))
	{
		ft_putstr_fd(ft_itoa((*info)->return_values[0]),1);
		ft_putstr_fd(" ",1);
		ft_putstr_fd(ft_itoa((*info)->return_values[1]),1);
		ft_putstr_fd("\n",1);
		return (1);
	}
	// str = ft_itoa((*info)->pos / (*info)->nb_cols);
	// play_str = ft_strnew(0);
	// play_str = ft_strjoin_free(play_str, str, 0);
	// play_str = ft_strjoin_free(play_str, " ", 0);
	// str = ft_itoa((*info)->pos % (*info)->nb_cols);
	// play_str = ft_strjoin_free(play_str, str, 0);
	// play_str = ft_strjoin_free(play_str, "\n", 0);
	// ft_putstr_fd(play_str, 1);
	// ft_putstr_fd(play_str, (*parser)->fd);
	return (0);
}
