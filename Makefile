NAME = libftprintf.a

SRC = ft_printf.c\
	sources.c

OBJ = $(SRC:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
