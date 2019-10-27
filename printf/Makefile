NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
HEAD = ft_printf.h
SRC = ft_printf.c \
	ft_printf_string.c \
	ft_printf_int.c \
	ft_printf_uint.c \
	ft_printf_ptr.c \
	ft_printf_float.c \
	ft_printf_efg.c \
	ft_printf_f.c \
	ft_printf_e.c \
	ft_printf_n.c \
	ft_bigint.c \
	ft_bigint_exp.c \
	ft_printf_b.c \
	ft_printf_utoa.c \
	ft_printf_otoa.c \
	ft_printf_xtoa.c \
	ft_printf_r.c \
	ft_printf_wchar.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
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