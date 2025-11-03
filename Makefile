NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

SRCS = ft_printf.c print_func.c print_unsigned_int.c print_hex.c

OBJ = ${SRCS:%.c=%.o}

RM = rm -f

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# -lft library named libft
# -C change directory
# -L./libft look for libraries, search inside libft directory

# for testing:
# cc main.c libftprintf.a libft/libft.a
# cc main.c -L. -L./libft -lftprintf -lft
