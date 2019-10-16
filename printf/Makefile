NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEAD = fillit.h
SRC = ft_printf.c ft_printf_string.c ft_printf_int.c ft_printf_uint.c ft_printf_ptr.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	ar rc $(NAME) $(OBJ) libft/*.o

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