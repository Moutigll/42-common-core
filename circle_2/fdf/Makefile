NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
MLX_DIR = ./minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -I$(MLX_DIR) -I./libft/include
LIBFT = ./libft/libft.a

SRCS = main.c draw_utils.c parsing.c draw_map.c rotation_matrix.c hooks.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT) -no-pie

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

