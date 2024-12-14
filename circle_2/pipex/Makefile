CC = cc
CFLAGS = -Wall -Werror -Wextra -I include -I ../libft/include
NAME = pipex

PIPEX_SRCS = pipex.c clean.c get_cmd.c check_args.c exec_cmd.c
PIPEX_OBJ = $(PIPEX_SRCS:.c=.o)

PIPEX_BONUS_SRCS = pipex_bonus.c clean.c get_cmd.c check_args.c exec_cmd.c
PIPEX_BONUS_OBJ = $(PIPEX_BONUS_SRCS:.c=.o)

LIBFT_PATH = ../../libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(PIPEX_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(PIPEX_OBJ) $(LIBFT)

bonus: $(LIBFT) $(PIPEX_BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(PIPEX_BONUS_OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(PIPEX_OBJ) $(PIPEX_BONUS_OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re bonus
