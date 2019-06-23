/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:09:27 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/23 04:14:31 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct		s_sog
{
	char			*sogm;
	char			player_char[2];
	int				nb_cols;
	int				nb_rows;
	int				enemy_x;
	int				enemy_y;
	int				my_x;
	int				my_y;
	int				init_x;
	int				init_y;
	int				len_line;
	int				first_time;
	char			*ret;
}					t_sog;

typedef struct		s_piece
{
	int				tmp_x;
	int				tmp_y;
	int				contact;
	int				around_contacts;
	int				return_x;
	int				return_y;
	char			*sogp;
	int				piece_rows;
	int				piece_cols;
	int				real_width;
	int				real_height;
	int				init_x;
	int				end_x;
	int				init_y;
	int				end_y;
}					t_piece;

typedef struct		s_place
{
	int				test;
}					t_place;

/*
** init_variables.c
*/

int					init_variables(t_sog **map, t_piece **piece);

/*
** info_player.c
*/

int					info_player(t_sog **map, t_piece **piece);

/*
** turn_to_play.c
*/

int					turn_to_play(t_sog **map, t_piece **p);

/*
**	play.c
*/
int					play(t_sog **map, t_piece **p);

/*
** small_map.c
*/

int					small_map(t_sog **map, t_piece **p);

/*
** check_position.c
*/

int					is_placable(int i, int i2, t_sog **map, t_piece **p);
void				print_result(t_piece **p, t_sog **map);

/*
** algo_down.c
*/

int					algo_dr(t_sog **map, t_piece **p);
int					algo_dl(t_sog **map, t_piece **p);

/*
** algo_up.c
*/

int					algo_ul(t_sog **map, t_piece **p);
int					algo_ur(t_sog **map, t_piece **p);

/*
** get_piece.c
*/

int					get_piece(char **line, t_piece **p);


#endif
