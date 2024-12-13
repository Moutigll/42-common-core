NAME := fdf

CC := gcc
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast

MLX_DIR := ../../MLX42
LIBFT_DIR := ../../libft
LIBFT := $(LIBFT_DIR)/libft.a

HEADERS := -I$(MLX_DIR)/include -I$(LIBFT_DIR)/include -Iinclude
MLX_FLAGS := $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS := main.c parse_map.c draw_utils.c rotation.c hooks.c draw_map.c
OBJS := $(SRCS:.c=.o)

all: libmlx libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT)
	@echo "Compilation de $(NAME) réussie."

libft:
	@make -C $(LIBFT_DIR)

libmlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build
	@make -C $(MLX_DIR)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "Compilé : $(notdir $<)"

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(MLX_DIR)/build
	@echo "Nettoyage des fichiers objets terminé."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "Nettoyage complet terminé."

re: fclean all

.PHONY: all clean fclean re libmlx libft
