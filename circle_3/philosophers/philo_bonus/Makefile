NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g

SRCS = src/main_bonus.c src/utils_bonus.c src/init_bonus.c src/philo_bonus.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
