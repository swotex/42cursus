# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njegat <njegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 10:20:47 by njegat            #+#    #+#              #
#    Updated: 2023/07/10 23:47:14 by njegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CXX = c++

CXXFLAGS = -Werror -Wextra -Wall -std=c++98

SRC =	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp

OBJ = $(SRC:%.cpp=%.o)

%.o: %.c
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ)  -o $(NAME)
	@echo "\033[4;32m--- executable created ---\n\033[0m"

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[4;35m--- all creations have been deleted ---\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
