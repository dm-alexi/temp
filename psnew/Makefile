CHECKER = checker
PUSHSWAP = push_swap
GENERATE = generate
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEAD = pushswap.h
SRC = check.c error.c input.c output.c list_op.c stack_op.c sort.c mainsort.c ajusts.c
OBJ = $(SRC:.c=.o)

all: $(CHECKER) $(PUSHSWAP) $(GENERATE)

$(CHECKER): $(OBJ) checker.o
	make -C ./libft/
	$(CC) $(FLAGS) -o $(CHECKER) $(OBJ) checker.c $(LIBFT)

$(PUSHSWAP): $(OBJ) pushswap.o
	make -C ./libft/
	$(CC) $(FLAGS) -o $(PUSHSWAP) $(OBJ) pushswap.c $(LIBFT)

$(GENERATE): generate.o
	make -C ./libft/
	$(CC) $(FLAGS) -o $(GENERATE) generate.o $(LIBFT)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ) checker.o pushswap.o generate.o
	make clean -C ./libft/

fclean: clean
	rm -f $(CHECKER) $(PUSHSWAP) $(GENERATE)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re