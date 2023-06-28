# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njegat <njegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 10:20:47 by njegat            #+#    #+#              #
#    Updated: 2023/05/26 18:26:45 by njegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = clang

FLAGS = -Werror -Wextra -Wall -pthread -g

SRC = src/philo.c \
		src/convert.c \
		src/utils.c \
		src/init.c \
		src/daily.c \
		src/parsing.c \
		src/utils_suit.c

OBJ = $(SRC:%.c=%.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
#	@make -s -C $(LINK_LIB)
	@$(CC) $(FLAGS) $(OBJ)  -o $(NAME)
	@echo "\033[4;32m--- executable created ---\n\033[0m"

all: $(NAME)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(BOBJ)
#	@make -s -C $(LINK_LIB) clean

fclean: clean
	@rm -rf $(NAME)
#	@make -s -C $(LINK_LIB) fclean
	@echo "\033[4;35m--- all creations have been deleted ---\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
