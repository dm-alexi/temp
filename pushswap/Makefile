CHECKER = checker
PUSHSWAP = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEAD = pushswap.h
SRC1 = checker.c error.c input.c list_op.c pushswap.c
OBJ1 = $(SRC1:.c=.o)

all: $(CHECKER)

$(CHECKER): $(OBJ1)
	make -C ./libft/
	$(CC) $(FLAGS) -o $(CHECKER) $(OBJ1) $(LIBFT)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ1)
	make clean -C ./libft/

fclean: clean
	rm -f $(CHECKER)
	rm -f $(PUSHSWAP)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re