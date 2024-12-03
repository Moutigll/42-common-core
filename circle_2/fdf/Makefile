CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/usr/local/include

NAME = program
SRCS = main.c draw_utils.c 
OBJS = $(SRCS:.c=.o)

LIBS = -L/usr/local/lib -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
