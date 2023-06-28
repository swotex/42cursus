# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njegat <njegat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:01:26 by njegat            #+#    #+#              #
#    Updated: 2023/01/31 07:40:10 by njegat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang

FLAGS = -Werror -Wextra -Wall

LINK_LIB = libft/

NAME_LIB = libft.a

SRC = src/fdf.c \
		src/hooks.c \
		src/draw_line.c \
		src/parse_data.c \
		src/free_utils.c \
		src/utils.c \
		src/matrix_set.c \
		src/display.c \
		src/rotate.c \
		src/utils_suit.c

BSRC = bonus/fdf_bonus.c \
		bonus/hooks_bonus.c \
		bonus/draw_line_bonus.c \
		bonus/parse_data_bonus.c \
		bonus/free_utils_bonus.c \
		bonus/utils_bonus.c \
		bonus/matrix_set_bonus.c \
		bonus/display_bonus.c \
		bonus/rotate_bonus.c \
		bonus/color_set_bonus.c \
		bonus/legend_bonus.c \
		bonus/hooks_suit_bonus.c \
		bonus/utils_suit_bonus.c

OBJ = $(SRC:%.c=%.o)
BOBJ = $(BSRC:%.c=%.o)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -g -c $< -o $@

$(NAME): $(OBJ)
	@make -s -C $(LINK_LIB)
	@make -s -C mlx_linux/
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LINK_LIB)$(NAME_LIB) -o $(NAME)
	@echo "\033[4;32m--- executable created ---\n\033[0m"

all: $(NAME)

bonus: $(BOBJ)
	@make -s -C $(LINK_LIB)
	@make -s -C mlx_linux/
	@$(CC) $(BOBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LINK_LIB)$(NAME_LIB) -o $(NAME)
	@echo "\033[4;32m--- executable created ---\n\033[0m"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(BOBJ)
	@make -s -C $(LINK_LIB) clean

fclean: clean
	@rm -rf $(NAME)
	@make -s -C $(LINK_LIB) fclean
	@make -s -C mlx_linux/ clean
	@echo "\033[4;35m--- all creations have been deleted ---\n\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus
