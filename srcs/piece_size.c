/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:48:53 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/07 22:51:22 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Scanning the piece by rows starting by the top and then the bottom
*/

static void	get_height(int i, t_filler_info **info)
{
	int		upper_point;

	while (i < (*info)->piece_cols * (*info)->piece_rows)
	{
		if (((*info)->sogp)[i] == '*')
		{
			upper_point = i / (*info)->piece_cols;
			break ;
		}
		i++;
	}
	i = (*info)->piece_cols * (*info)->piece_rows;
	while (--i >= 0)
	{
		if (((*info)->sogp)[i] == '*')
		{
			(*info)->p_height = (upper_point - (i / (*info)->piece_cols)) + 1;
			break ;
		}
	}
}

static void	get_width_right(int i, t_filler_info **info, int leftest_point)
{
	int		iter;
	int		col;

	i = (*info)->nb_cols * (*info)->nb_rows - 1;
	iter = (*info)->nb_rows;
	col = 0;
	while (--iter)
	{
		if (((*info)->sogp[i]) == '*')
		{
			(*info)->p_width = (leftest_point) - (i % (*info)->nb_cols) + 1;
			break ;
		}
		if (iter == 0 && ((*info)->sogp)[i] != '*')
		{
			iter = (*info)->nb_rows;
			col++;
			i = ((*info)->nb_cols * (*info)->nb_rows - 1) - col;
		}
		i -= (*info)->nb_cols;
	}
}

/*
** Scanning the piece by column starting by the left
*/

static void	get_width(int i, t_filler_info **info)
{
	int		iter;
	int		col;
	int		leftest_point;

	col = 0;
	iter = (*info)->nb_rows;
	leftest_point = 0;
	while (--iter)
	{
		if (((*info)->sogp[i]) == '*')
		{
			leftest_point = i % (*info)->nb_cols;
			break ;
		}
		if (iter == 0 && ((*info)->sogp)[i] != '*')
		{
			iter = (*info)->nb_rows;
			col++;
			i = col;
		}
		i += (*info)->nb_cols;
	}
	get_width_right(i, info, leftest_point);
}

void		get_real_width_height_piece(t_filler_info **info)
{
	int		i;

	i = 0;
	get_height(i, info);
	//get_width(i, info);
}
