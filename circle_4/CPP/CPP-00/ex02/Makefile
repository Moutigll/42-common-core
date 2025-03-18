NAME = ex02
CC = c++ -Wall -Wextra -Werror -std=c++98

SRC =	tests.cpp \
		Account.class.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all