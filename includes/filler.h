#ifndef FILLER_H
# define FILLER_H

#include "libft.h"

typedef struct      s_sog
{
    char            **map;
    char            player_char[2];
    int             width;
    int             height;
    int             enemy_x;
    int             enemy_y;
    int             my_x;
    int             my_y;
    int             init_x;
    int             init_y;
    int             len_line;
    char            *ret;
}                   t_sog;

typedef struct      s_piece
{
    int             tmp_x;
    int             tmp_y;
    int             contacts;
    int             final_x;
    int             final_y;
    char            **piece;
    int             width;
    int             height;
    int             real_width;
    int             real_height;
    int             init_x;
    int             end_x;
    int             init_y;
    int             end_y;
}                  t_piece;
