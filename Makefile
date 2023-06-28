# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njegat <njegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 12:23:36 by njegat            #+#    #+#              #
#    Updated: 2023/01/25 15:40:24 by njegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNAME = checker

CC = clang

FLAGS = -Werror -Wextra -Wall

SRC = push_swap.c \
		error.c \
		error_suit.c \
		swap.c \
		stack_list.c \
		little_sort.c \
		utils.c \
		utils_suit.c \
		sort_all.c \
		instruction.c

BSRC = checker_bonus/ft_checker.c \
		checker_bonus/error_bonus.c \
		checker_bonus/error_suit_bonus.c \
		checker_bonus/stack_list.c \
		checker_bonus/swap.c \
		checker_bonus/utils.c \
		checker_bonus/gnl/get_next_line.c \
		checker_bonus/gnl/get_next_line_utils.c

LINK_LIB = libft/

NAME_LIB = libft.a

$(NAME):
	@make -s -C $(LINK_LIB)
	@echo "\033[4;32m--- libft archive created ---\n\033[0m"
	@$(CC) $(FLAGS) $(SRC) $(LINK_LIB)$(NAME_LIB) -o $(NAME)
	@echo "\033[4;32m--- executable created ---\n\033[0m"

all: $(NAME)

$(BNAME):
	@make -s -C $(LINK_LIB)
	@echo "\033[4;32m--- libft archive created ---\n\033[0m"
	@$(CC) $(FLAGS) $(BSRC) $(LINK_LIB)$(NAME_LIB) -o $(BNAME)
	@echo "\033[4;32m--- executable bonus created ---\n\033[0m"

bonus: $(BNAME)

clean: 
	@make -s -C $(LINK_LIB) clean
	@echo "\033[4;35m--- -.o files have been deleted ---\n\033[0m"

fclean:
	@make -s -C $(LINK_LIB) fclean
	@rm -rf $(NAME) $(BNAME)
	@echo "\033[4;35m--- all creations have been deleted ---\n\033[0m"

re: fclean all