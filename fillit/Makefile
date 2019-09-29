NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = fillit.h
SRC = main.c columns.c nodes.c print.c readfile.c rows.c solution.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(FLAGS) -o $@ -L libft -lft

%.o: %.c $(HEAD)
	$(CC) $< $(FLAGS) -o $@ -L libft -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
