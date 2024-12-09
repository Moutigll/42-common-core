NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
INCLUDES = -I$(MLX_DIR) -I./libft/include -Iinclude

MLX_DIR = ./minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx42 -ldl -lglfw -pthread -lm

LIBFT_DIR = ../../libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c draw_utils.c parsing.c draw_map.c rotation_matrix.c hooks.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT) -no-pie

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
