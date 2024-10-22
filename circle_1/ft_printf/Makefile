CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

PART_PRINTF_SRCS = ft_printf.c utils.c print_args.c print_argsbis.c manage_flags.c

PART_PRINTF_OBJS = $(PART_PRINTF_SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

makelibft:
	@make -C libft
	@cp libft/libft.a .

$(NAME): makelibft $(PART_PRINTF_OBJS)
	cp	libft.a $(NAME)
	@ar rcs $(NAME) $(PART_PRINTF_OBJS)
	ranlib $(NAME)


clean:
	@rm -f $(PART_PRINTF_OBJS)
	@cd libft && make clean
	
fclean: clean
	@rm -f $(NAME) libft.a
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
