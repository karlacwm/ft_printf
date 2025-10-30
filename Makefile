NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_LINK = -L$(LIBFT_DIR) -lft

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

SRCS = ft_printf.c

OBJ = ${SRCS:%.c=%.o}

RM = rm -f

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(NAME): $(LIBFT) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(LIBFT)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# -lft library named libft
# -C change directory
# -L./libft look for libraries, search inside libft directory
