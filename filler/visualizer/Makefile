NAME = ../visual
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ../libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEAD = $(LIBFT_DIR)include/
HEAD_DIR = include/
HEAD_FILES = visual.h
HEADERS = $(addprefix $(HEAD_DIR),$(HEAD_FILES))
SRC = main.c error.c input.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(HEAD_DIR) -I$(LIBFT_HEAD) -o $@ -c $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re