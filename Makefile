NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = gnl/get_next_line.c src/apply_center.c src/apply_scale.c src/draw.c src/get_point.c src/main.c src/make_grid.c src/make_mlx.c src/relative_center.c src/rot.c src/usage.c src/handle_key.c src/make_line.c src/xy_keys.c src/z_keys.c

FRAMEWORKS = -framework OpenGL -framework Appkit

INCLUDE = -I includes

INCLUDE_MLX = -I mlx
LINK_MLX = -L mlx -lmlx
MLX = $(INCLUDE_MLX) $(LINK_MLX)

INCLUDE_LIBFT = -I libft/includes
LINK_LIBFT = -L libft/ -lft
LIBFT = $(INCLUDE_LIBFT) $(LINK_LIBFT)

GNL = -I gnl

all: $(NAME)

libft.a:
	make -C libft re

mlx.a:
	make -C mlx re

$(NAME): libft.a mlx.a
	$(CC) $(MLX) $(LIBFT) $(GNL) $(INCLUDE) $(FRAMEWORKS) $(SRC) -o $(NAME)

clean:
	make -C libft fclean
	make -C mlx clean

fclean: clean
	rm -rf $(NAME)

re: clean all
