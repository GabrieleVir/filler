/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledieu <jledieu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:04:41 by jledieu           #+#    #+#             */
/*   Updated: 2016/04/23 17:16:56 by jledieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include <mlx.h>
# include "../../includes/filler.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	size_t	nbline;
	size_t	winx;
	size_t	winy;
	int		start;
	int		firstround;
	int		**mapxyz;
	int		resulto;
	int		resultx;
	int		takemap;
	char	*sresulto;
	char	*sresultx;
	char	*mapjoin;
	char	**map;
}				t_mlx;

void			ft_getmap_xy(t_mlx *e, size_t y, size_t x);
void			ft_put_pixel(t_mlx *e);
#endif
