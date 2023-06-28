# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njegat <njegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 10:20:47 by njegat            #+#    #+#              #
#    Updated: 2023/06/13 13:40:18 by njegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = clang

FLAGS = -Werror -Wextra -Wall -pthread -g

SRC = src/philo_bonus.c \
		src/convert_bonus.c \
		src/utils_bonus.c \
		src/init_bonus.c \
		src/daily_bonus.c \
		src/parsing_bonus.c \
		src/death_handler.c \
		src/ft_itoa.c


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
