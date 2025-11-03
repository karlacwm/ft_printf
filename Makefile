NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

SRCS = ft_printf.c print_func.c print_unsigned_int.c print_unsigned_hex.c

OBJ = ${SRCS:%.c=%.o}

# LIBFT_LINK = -L$(LIBFT_DIR) -lft
# TEST_SRC = main.C
# TEST = test

RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

# $(TEST): all $(TEST_SRC)
# 	$(CC) $(CFLAGS) $(TEST_SRC) -L. -lftprintf $(LIBFT_LINK) -o $(TEST)

# test: $(TEST)
# 	./$(TEST)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
# 	$(RM) $(TEST_EXE)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# -lft library named libft
# -C change directory
# -L./libft look for libraries, search inside libft directory
