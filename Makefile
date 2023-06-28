GCC = gcc

NAME = libftprintf.a

SRC = ft_printf.c \
      ft_util.c

HEADER = ft_printf.h

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	ar r $(NAME) $(OBJ) $(HEADER)

%.o: %.c
	$(GCC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re