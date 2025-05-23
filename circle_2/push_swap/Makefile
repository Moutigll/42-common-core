CC = cc
CFLAGS = -Wall -Werror -Wextra -I include -I libft/include
NAME = push_swap
CHECKER = checker
SRC_DIR = src
TEST_DIR = tests

PUSH_SWAP_SRCS = list_utils.c sorting_utils.c stack_operations.c \
                  stack_operations_both.c get_cost.c get_cost_utils.c \
                  sort_stacks.c check_args.c
PUSH_SWAP_OBJS = $(addprefix $(SRC_DIR)/, $(PUSH_SWAP_SRCS:.c=.o))

NORMAL_SRCS = push_swap.c
NORMAL_OBJS = $(addprefix $(SRC_DIR)/, $(NORMAL_SRCS:.c=.o))

BONUS_SRCS = checker.c
BONUS_OBJS = $(addprefix $(SRC_DIR)/, $(BONUS_SRCS:.c=.o))

TEST_SRCS = main.c push_tests.c swap_tests.c rotate_tests.c
TEST_OBJS = $(addprefix $(TEST_DIR)/, $(TEST_SRCS:.c=.o))

LIBFT_PATH = ../../libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS) $(NORMAL_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(NORMAL_OBJS) $(PUSH_SWAP_OBJS) $(LIBFT)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(PUSH_SWAP_OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(BONUS_OBJS) $(PUSH_SWAP_OBJS) $(LIBFT)

test: CFLAGS += -DTESTING
test: fclean $(LIBFT) $(PUSH_SWAP_OBJS) $(TEST_OBJS) $(NORMAL_OBJS)
	$(CC) $(CFLAGS) -o push_swap $(NORMAL_OBJS) $(PUSH_SWAP_OBJS) $(TEST_OBJS) $(LIBFT)
	@make clean
	./push_swap 5 4 3 2 1

clean:
	@rm -f $(PUSH_SWAP_OBJS) $(NORMAL_OBJS) $(BONUS_OBJS) $(TEST_OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME) $(CHECKER)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re bonus test
