CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFT_PATH = ../../libft
LIBFT = $(LIBFT_PATH)/libft.a
INCLUDES = -I$(LIBFT_PATH)/include

PART_PRINTF_SRCS = ft_printf.c utils.c print_args.c print_argsbis.c manage_flags.c
PART_PRINTF_OBJS = $(PART_PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): makelibft $(PART_PRINTF_OBJS)
	cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(PART_PRINTF_OBJS)
	ranlib $(NAME)

makelibft:
	@make -C $(LIBFT_PATH)

bonus: all

clean:
	@rm -f $(PART_PRINTF_OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re bonus
