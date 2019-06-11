/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 02:42:45 by gvirga            #+#    #+#             */
/*   Updated: 2019/06/07 21:34:45 by gvirga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
// For O_WRONLY (to remove after the project is finised)
# include <fcntl.h>

typedef struct			s_parser
{
	int					fd;
	char				*line;
	int					first_time;
	int					i;
	int					ret;
}						t_parser;

typedef struct			s_filler_info
{
	char				*sogm;
	char				*sogp;
	int					player_number;
	int					nb_rows;
	int					nb_cols;
	int					piece_rows;
	int					piece_cols;
	int					p_width;
	int					p_height;
	int					pos;
	int					contact_pos[2];
	int					return_values[2];
	char				player_char;
}						t_filler_info;

typedef struct			s_place
{
	int					i;
	int					piece_i;
	int					x;
	int					y;
}						t_place;


/*
** strerror_manager.c
*/
int						error_msg_fd(int error, int fd);
int						error_str_fd(char *str, int fd);
int						error_info_malloc(int err_nb, t_parser **parser,
											char *err_str);
int						error_free_line(t_parser **parser);
/*
** info_player.c
*/
int						info_player(t_parser **parser, t_filler_info **info);
int						init_variables(t_parser **p, t_filler_info **i);
/*
** read_sogp.c
*/
int						read_sogp(t_parser **parser, t_filler_info **info);
/*
** get_piece.c
*/
int						get_piece(t_parser **parser, t_filler_info **info);
/*
** piece_size.c
*/
void					get_real_width_height_piece(t_filler_info **info);

/*
** fill_map.c
*/
int						fill_map(t_filler_info **info, t_parser **parser);

#endif
