ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$HOSTTYPE.so
LINKNAME = libft_malloc.so
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD_DIR = include
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_HEAD_DIR = $(LIBFT_DIR)/include
LDFLAGS = -I $(HEAD_DIR) -I $(LIBFT_HEAD_DIR)
SRC_FILES = ft_malloc.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

-include $(OBJ:.o=.d)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lft -pthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(LDFLAGS) -o $@ -c $< -MMD

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT): FAKE
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re FAKE