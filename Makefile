# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvirga <gvirga@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 23:31:55 by gvirga            #+#    #+#              #
#    Updated: 2019/06/26 07:22:29 by gvirga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =gvirga.filler

HEADER_FILES =filler.h
LIBFT_DIR =libft/
LIBS =libft.a
LIBSDIR=libs/
LIBSPATH =$(addprefix $(LIBSDIR), $(LIBS))
SRCDIR=srcs/
CC = gcc 
CFLAGS = -fsanitize=address 
MAIN =main.c
FILES =sm_algo_down.c sm_algo_up.c check_position.c get_piece.c info_player.c \
	   init_variables.c play.c small_map.c turn_to_play.c big_map.c bm_algo.c \
	   contacts.c
SRCFILES =$(addprefix $(SRCDIR), $(FILES))
OBJ=$(subst .c,.o, $(FILES)) main.o
SRCOBJ =$(addprefix $(SRCDIR), $(OBJ))
INC_DIR =./includes/
LFLAGS =rc
FRAMEWORKS=
FRAMEWORKS_CMD=$(addprefix -framework , $(FRAMEWORKS))
FILES2=ft_putchar.c ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl.c \
ft_putendl_fd.c ft_memcpy.c ft_putwchar.c ft_putwstr.c \
\
ft_memccpy.c ft_memset.c ft_bzero.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
ft_strcpy.c ft_strncpy.c ft_strtrim.c ft_strsplit.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strstr.c \
ft_strchri.c ft_isdigit.c ft_putnbr.c ft_putnbr_fd.c ft_strchr.c \
ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strnjoin.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
\
ft_atoi.c ft_isalpha.c ft_isalnum.c ft_ispowerof2.c\
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_itoa.c \
ft_memdel.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_itoa_base.c \
ft_lstiter.c ft_lstmap.c ft_lstcpy.c ft_wordcount.c ft_atol.c ft_push_back.c \
ft_strnboccur.c ft_strjoin_free.c ft_ipower.c ft_npower.c ft_rchr.c \
ft_nbdigit.c ft_strjoin_freei.c ft_strnew_free.c ft_strsub_free.c \
ft_strdup_free.c ft_putlstr.c ft_memljoin.c ft_llnbdigit.c ft_bigpower.c \
ft_ftoa.c ft_round_str_double.c get_next_line.c
SRCFILES2 =$(addprefix libft/srcs/, $(FILES2))
SRCOBJ2 =$(subst .c, .o, $(SRCFILES2))

RED=\033[0;31m
YELLOW=\033[0;33m
GREEN=\033[0;32m
END=\033[0m
VOMI=\033[0;35m
VOMIETALEE=\033[44m
CYAN =\033[36m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CYAN)Building the $(NAME) executable$(END)"
	gcc $(CFLAGS) -o $@$(OBJ) $(LIBSPATH) $(FRAMEWORKS_CMD)
	@echo "$(GREEN)SUCCESS$(END)"

$(OBJ): $(SRCFILES) $(MAIN) $(SRCFILES2)
	@echo "$(CYAN)Compilation of source files for $(NAME) executable...$(END)"
	@$(CC) $(CFLAGS) $(MAIN) -c $(SRCFILES) -I $(INC_DIR)

$(SRCFILES2):
	@echo "$(YELLOW)Checking updates in the libs$(END)"
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)libft.a libs/
	@cp $(LIBFT_DIR)/includes/libft.h $(INC_DIR)

clean:
	@rm -Rf $(OBJ)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(RED)Suppression$(END) of source files for $(CYAN)$(NAME)$(END)..."

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Suppression$(END) of the lib $(CYAN)$(NAME)$(END)"
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all
