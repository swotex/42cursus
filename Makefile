# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njegat <njegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 03:42:25 by tdhaussy          #+#    #+#              #
#    Updated: 2023/06/09 17:15:18 by njegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = cub3D

SRC =	srcs/cub3d.c \
		srcs/parsing/parsing_handler.c \
		srcs/utils.c

RM = rm -rf

MAKEFLAGS =	--no-print-directory

OBJ =	$(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g3

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $(<:%.c=%.o)

$(NAME):	$(OBJ)
		@echo "**********************"
		@echo "*     \033[1;33mCOMPILING\033[1;0m      *"
		@echo "**********************\n"
		@make -C libft
		$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $@
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

clean:
		$(RM) $(OBJ)
		@make clean -C libft
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"

fclean:
		$(RM) $(OBJ) $(NAME)
		@make fclean -C libft
		@echo "**********************"
		@echo "*     \033[1;32mCLEANED ALL\033[1;0m    *"
		@echo "**********************"

re:		fclean	all

.PHONY:	all clean fclean re
