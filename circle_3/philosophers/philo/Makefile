NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g

SRCS = src/main.c src/utils.c src/init.c src/philos.c src/check.c
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
