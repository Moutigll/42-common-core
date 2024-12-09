CC = cc
CFLAGS = -Wall -Werror -Wextra -I include -I ../libft/include
NAME = pipex

PIPEX_SRCS = pipex.c clean.c get_cmd.c check_args.c exec_cmd.c
PIPEX_OBJ = $(PIPEX_SRCS:.c=.o)

LIBFT_PATH = ../../libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(PIPEX_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(PIPEX_OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(PIPEX_OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
