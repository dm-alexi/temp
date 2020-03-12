NAME = sscarecr.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_HEAD = libft/include/
HEAD_DIR = include/
HEAD_FILES = filler.h
HEADERS = $(addprefix $(HEAD_DIR),$(HEAD_FILES))
SRC = main.c error.c input.c solve.c setup.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(HEAD_DIR) -I$(LIBFT_HEAD) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re