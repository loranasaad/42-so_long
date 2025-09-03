# =========================
# so_long — Makefile (mac)
# =========================

NAME    := so_long
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iinclude -Ignl -Imlx
MLX_DIR := mlx
LIBS    := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# --- sources (from your tree) ---
SRCS := \
  src/main.c \
  src/debugger.c \
  src/map/map_loader.c \
  src/map/map_check.c \
  src/mlxwrap/mlx_init.c \
  src/mlxwrap/hooks.c \
  src/render/render.c \
  src/render/textures.c \
  src/utils/errors.c \
  gnl/get_next_line.c \
  gnl/get_next_line_utils.c

OBJS := $(SRCS:.c=.o)

# --- rules ---
all: $(NAME)

$(NAME): $(OBJS) $(MLX_DIR)/libmlx.a
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

# Build MiniLibX if needed
$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

# Pattern rule for objects
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re