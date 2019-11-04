CHECKER = checker
PUSHSWAP = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEAD = pushswap.h
SRC = checker.c check.c error.c input.c list_op.c pushswap.c
OBJ = $(SRC1:.c=.o)

all: $(CHECKER) $(PUSHSWAP)

$(CHECKER): $(OBJ) checker.o
	make -C ./libft/
	$(CC) $(FLAGS) -o $(CHECKER) $(OBJ) checker.c $(LIBFT)

$(PUSHSWAP): $(OBJ) push_swap.o
	make -C ./libft/
	$(CC) $(FLAGS) -o $(PUSHSWAP) $(OBJ) push_swap.c $(LIBFT)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	rm -f $(CHECKER) $(PUSHSWAP)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re