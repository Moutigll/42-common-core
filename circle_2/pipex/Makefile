CC = cc
CFLAGS = -Wall -Werror -Wextra -I include -I libft/include
NAME = pipex


PIPEX = pipex.c
PIPEX_OBJ = $(PIPEX:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(PIPEX_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(PIPEX_OBJ) $(LIBFT)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(PIPEX_OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
