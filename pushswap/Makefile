CHECKER = checker
PUSHSWAP = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEAD = pushswap.h
SRC = check.c error.c input.c output.c list_op.c stack_op.c sort.c mergesort.c reduce.c 
OBJ = $(SRC:.c=.o)

all: $(CHECKER) $(PUSHSWAP)

$(CHECKER): $(OBJ) checker.o
	make -C ./libft/
	$(CC) $(FLAGS) -o $(CHECKER) $(OBJ) checker.c $(LIBFT)

$(PUSHSWAP): $(OBJ) pushswap.o
	make -C ./libft/
	$(CC) $(FLAGS) -o $(PUSHSWAP) $(OBJ) pushswap.c $(LIBFT)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ) checker.o pushswap.o
	make clean -C ./libft/

fclean: clean
	rm -f $(CHECKER) $(PUSHSWAP)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re