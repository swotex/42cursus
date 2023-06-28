# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njegat <njegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 10:20:47 by njegat            #+#    #+#              #
#    Updated: 2023/03/13 16:51:14 by njegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang

FLAGS = -Werror -Wextra -Wall

LINK_LIB = libft/

NAME_LIB = libft.a

SRC = src/pipex.c \
		src/path_handler.c \
		src/commands.c

BSRC = bonus/pipex_bonus.c \
		bonus/path_handler_bonus.c \
		bonus/commands_bonus.c \
		bonus/pipe_utils_bonus.c \
		bonus/dup_handler_bonus.c \
		bonus/commands_file_bonus.c

OBJ = $(SRC:%.c=%.o)
BOBJ = $(BSRC:%.c=%.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -s -C $(LINK_LIB)
	@$(CC) $(OBJ) $(LINK_LIB)$(NAME_LIB) -o $(NAME)
	@echo "\033[4;32m--- executable created ---\n\033[0m"

all: $(NAME)

bonus: $(BOBJ)
	@make -s -C $(LINK_LIB)
	@$(CC) $(BOBJ) $(LINK_LIB)$(NAME_LIB) -o $(NAME)
	@echo "\033[4;32m--- executable created ---\n\033[0m"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(BOBJ)
	@make -s -C $(LINK_LIB) clean

fclean: clean
	@rm -rf $(NAME)
	@make -s -C $(LINK_LIB) fclean
	@echo "\033[4;35m--- all creations have been deleted ---\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
