NAME = visu

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = visu.c ft_getmap_xy.c ft_put_pixel.c get_next_line.c

OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C ../libft/ fclean && make -C ../libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC)  $(CFLAGS) $(OBJ) ../libft/libft.a -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o visu

all : $(NAME)

clean :
	$(RM) $(OBJ)
	make -C ../libft/ clean

fclean : clean
	$(RM) $(NAME)
	make -C ../libft/ fclean

re : fclean all

.PHONY : all clean fclean re
