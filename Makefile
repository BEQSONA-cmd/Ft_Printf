NAME = libftprintf.a

BONUS = libftprintf.a

SRC = Mandatory/ft_printf.c\
	Mandatory/sources.c\

B_SRC = Bonus/ft_printf.c\
	Bonus/sources.c\
	Bonus/ft_str.c\
	Bonus/ft_char.c\
	Bonus/ft_num.c\
	Bonus/ft_hexl.c\
	Bonus/ft_hexu.c\
	Bonus/ft_uns.c\
	Bonus/ft_ptr.c\

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(B_OBJ)
	ar rc $(BONUS) $(B_OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(B_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean $(NAME)

.PHONY: all clean fclean re
