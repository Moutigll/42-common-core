NAME		:= ex01

CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -std=c++98

SRC_DIR		:= src
INC_DIR		:= includes
OBJ_DIR		:= obj

SRCS		:=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Fixed.cpp \

OBJS		:= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

RED			:= \033[0;31m
GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
BLUE		:= \033[0;34m
RESET		:= \033[0m

TOTAL_FILES	:= $(words $(SRCS))


all: $(NAME)
	@echo -e "$(GREEN)[ALL] Build complete!$(RESET)"

$(NAME): $(OBJS)
	@echo -e "$(BLUE)[Linking]$(RESET) Building executable $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(GREEN)[Linking] Executable $(NAME) successfully built!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo -n -e "$(YELLOW)[Compiling]$(RESET) $< ... "
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@echo -e "$(GREEN)Done$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo -e "$(BLUE)[Info]$(RESET) Created directory $(OBJ_DIR)"

clean:
	@echo -e "$(YELLOW)[Cleaning]$(RESET) Removing object files in $(OBJ_DIR)..."
	@rm -rf $(OBJ_DIR)
	@echo -e "$(GREEN)[Clean]$(RESET) Object files removed."

fclean: clean
	@echo -e "$(YELLOW)[Fclean]$(RESET) Removing executable $(NAME)..."
	@rm -f $(NAME)
	@echo -e "$(GREEN)[Fclean]$(RESET) Executable removed."

re: fclean all

.PHONY: all clean fclean re
