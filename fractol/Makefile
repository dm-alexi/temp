NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
HEADERS = -Iinclude -I$(LIBFT_DIR)/include -I$(MLX_DIR) 
LDFLAGS = -L$(LIBFT_DIR) -L$(MLX_DIR)
SRC_FILES = main.c error.c init.c ui.c image.c threads.c fractals.c draw.c complex.c window.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# OS detection.
ifeq ($(OS),Windows_NT)
	detected_OS = Windows
else
	detected_OS = $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif
# Note: Current version only supports Linux and Mac OS.
ifeq ($(detected_OS),Darwin)
	LDLIBS = -lmlx -framework OpenGL -framework AppKit
else
	LDLIBS = -lft -lmlx -lXext -lX11 -lm -pthread
endif


all: $(NAME)

-include $(OBJ:.o=.d)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< -MMD 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MLX_DIR)/*.a

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(MLX)