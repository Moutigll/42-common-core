CC = cc
CFLAGS = -Wall -Werror -Wextra -I include -I libft/include
NAME = pushswap
SRC_DIR = src

PUSH_SWAP_SRCS = push_swap.c list_utils.c stack_a_operations.c stack_b_operations.c
PUSH_SWAP_OBJS = $(addprefix $(SRC_DIR)/, $(PUSH_SWAP_SRCS:.c=.o))

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C libft printf

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(LIBFT)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	@rm -f $(PUSH_SWAP_OBJS)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
