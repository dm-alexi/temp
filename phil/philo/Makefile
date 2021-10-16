NAME = philo
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = main.c misc.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

-include $(OBJ:.o=.d)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lpthread

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $< -MMD

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ:.o=.d)

re: fclean all

.PHONY: all clean fclean re