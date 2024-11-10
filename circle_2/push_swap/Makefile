CC = cc
CFLAGS = -Wall -Werror -Wextra -I include -I libft/include
NAME = push_swap
SRC_DIR = src
TEST_DIR = tests

PUSH_SWAP_SRCS = push_swap.c list_utils.c stack_operations.c get_cost.c sorting_utils.c stack_operations_both.c
PUSH_SWAP_OBJS = $(addprefix $(SRC_DIR)/, $(PUSH_SWAP_SRCS:.c=.o))

TEST_SRCS = main.c push_tests.c swap_tests.c rotate_tests.c
TEST_OBJS = $(addprefix $(TEST_DIR)/, $(TEST_SRCS:.c=.o))

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C libft printf

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) $(TEST_OBJS) $(LIBFT)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

test: CFLAGS += -DTESTING
test: fclean $(LIBFT) $(PUSH_SWAP_OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o push_swap $(PUSH_SWAP_OBJS) $(TEST_OBJS) $(LIBFT)
	@make clean
	./push_swap 1 2 3 4 5

clean:
	@rm -f $(PUSH_SWAP_OBJS) $(TEST_OBJS) tests/main.o
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
