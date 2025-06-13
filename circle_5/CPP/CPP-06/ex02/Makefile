NAME		:= ex02

CC			:= c++
# Compilation flags:
# -Wall:                 Enable common warnings
# -Wextra:               Enable extra warnings
# -Werror:               Treat warnings as errors
# -std=c++98:            Use C++98 standard (required by 42)
# -g:                    Include debug symbols for debugging (e.g., gdb, lldb, valgrind)
# -Wconversion:          Warn on implicit type conversions (e.g., float to int)
# -Wsign-conversion:     Warn on signed/unsigned conversions
# -Wshadow:              Warn when a variable declaration shadows another
# -Wcast-qual:           Warn when casting away const/volatile qualifiers
CFLAGS		:= \
	-Wall \
	-Wextra \
	-Werror \
	-std=c++98 \
	-g \
	-Wconversion \
	-Wsign-conversion \
	-Wshadow \
	-Wcast-qual


ifeq ($(shell $(CC) --version | grep -c clang), 1)
	CFLAGS += -Wold-style-cast  # Warn on C-style casts if using Clang
endif

SRC_DIR		:= src
INC_DIR		:= includes
OBJ_DIR		:= obj

SRCS		:=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Base.cpp

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
