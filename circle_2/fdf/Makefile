NAME = program
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -I$(MLX_DIR)

SRCS = main.c draw_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
