NAME = libft.a

SRC = srcs/
HEADERS = includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I$(HEADERS) -c $(SRC)ft_putchar.c $(SRC)ft_putstr.c $(SRC)ft_strcmp.c $(SRC)ft_strlen.c $(SRC)ft_swap.c
	ar rc $(NAME) ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all