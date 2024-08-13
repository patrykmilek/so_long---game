NAME = so_long

SRC = src/main.c src/game.c src/map_validation.c src/map_validation_2.c src/map_utils.c src/map_utils_2.c src/render.c src/utils.c src/get_next_line.c src/utils2.c
OBJ = $(SRC:.c=.o)
MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR)
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX_DIR)

re: fclean all
