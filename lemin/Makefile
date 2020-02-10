NAME = lem-in
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEAD = lemin.h
SRC = main.c nodes.c edges.c print.c input.c error.c delete.c bfs.c disjoint.c restore.c belford.c clone. solve.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C ./libft/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

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