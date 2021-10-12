NAME = philo/philo
NAME_BONUS = philo_bonus/philo_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD_DIR = include
SRC_DIR = philo
SRC_FILES = main.c misc.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_DIR = philo_bonus
OBJ = $(SRC:.c=.o)
# BONUS_FILES = main.c misc.c
# BONUS_SRC = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
# BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

-include $(OBJ:.o=.d)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lpthread

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c -o $@ $< -MMD

clean:
	rm -rf $(OBJ)
# rm -rf $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ:.o=.d)

re: fclean all

bonus: $(BONUS_OBJ)
	$(CC) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus