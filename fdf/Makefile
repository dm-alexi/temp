NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEAD = fdf.h
SRC = main.c input.c error.c init.c keyboard.c image.c draw.c matrices.c menu.c colors.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re