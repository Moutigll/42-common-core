CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

PART1_DIR = 
PART2_DIR = 
PART_BONUS_DIR = 
INCLUDE_DIR = 

PART1_SRCS = ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c \
             ft_strrchr.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c \
             ft_strlen.c ft_tolower.c ft_calloc.c ft_isdigit.c ft_memcpy.c \
             ft_strdup.c ft_strncmp.c ft_toupper.c ft_isalnum.c ft_isprint.c \
             ft_memmove.c ft_strlcat.c ft_strnstr.c

PART2_SRCS = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			 ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

PART_BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				  ft_lstmap.c

PART1_OBJS = $(addprefix $(PART1_DIR), $(PART1_SRCS:.c=.o))
PART2_OBJS = $(addprefix $(PART2_DIR), $(PART2_SRCS:.c=.o))
PART_BONUS_OBJS = $(addprefix $(PART_BONUS_DIR), $(PART_BONUS_SRCS:.c=.o))

OBJS = $(PART1_OBJS) $(PART2_OBJS)
BONUS_OBJS = $(OBJS) $(PART_BONUS_OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

$(PART1_DIR)/%.o: $(PART1_DIR)/%.c $(INCLUDE_DIR)/libft.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(PART2_DIR)/%.o: $(PART2_DIR)/%.c $(INCLUDE_DIR)/libft.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(PART_BONUS_DIR)/%.o: $(PART_BONUS_DIR)/%.c $(INCLUDE_DIR)/libft.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(PART1_OBJS) $(PART2_OBJS) $(PART_BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
