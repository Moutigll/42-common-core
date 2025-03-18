NAME = phonebook
CC = c++ -Wall -Wextra -Werror -std=c++98

SRC =	PhoneBook.class.cpp \
		Contact.class.cpp \
		main.cpp \

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all