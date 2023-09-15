# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdhaussy <tdhaussy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 03:42:25 by tdhaussy          #+#    #+#              #
#    Updated: 2023/07/30 03:36:39 by tdhaussy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = cub3D

SRC =		srcs/cub3d.c \
			srcs/utils.c \
			srcs/parsing/parsing_handler.c \
			srcs/parsing/get_textures.c \
			srcs/parsing/get_textures_utils.c \
			srcs/parsing/get_colors.c \
			srcs/parsing/get_colors_utils.c \
			srcs/parsing/get_map.c \
			srcs/parsing/parsing_utils.c \
			srcs/parsing/check_map.c \
			srcs/errors/error_parsing.c \
			srcs/game/game.c \
			srcs/game/moves.c \
			srcs/game/display.c \
			srcs/game/raycast.c \
			srcs/game/pixel.c \
			srcs/game/draw.c \
			srcs/segments/find_segments.c \
			srcs/segments/segment.c \
			srcs/segments/vec_utils.c

SRC_BONUS =	srcs_bonus/cub3d.c \
			srcs_bonus/utils.c \
			srcs_bonus/parsing/parsing_handler.c \
			srcs_bonus/parsing/get_textures.c \
			srcs_bonus/parsing/get_textures_utils.c \
			srcs_bonus/parsing/get_colors.c \
			srcs_bonus/parsing/get_colors_utils.c \
			srcs_bonus/parsing/get_map.c \
			srcs_bonus/parsing/parsing_utils.c \
			srcs_bonus/parsing/check_map.c \
			srcs_bonus/errors/error_parsing.c \
			srcs_bonus/game/game.c \
			srcs_bonus/game/doors_loop.c \
			srcs_bonus/game/moves.c \
			srcs_bonus/game/rotation.c \
			srcs_bonus/game/display.c \
			srcs_bonus/game/raycast.c \
			srcs_bonus/game/pixel.c \
			srcs_bonus/game/draw.c \
			srcs_bonus/game/draw_utils.c \
			srcs_bonus/game/interact.c \
			srcs_bonus/segments/find_segments.c \
			srcs_bonus/segments/segment.c \
			srcs_bonus/segments/doors_segments.c \
			srcs_bonus/segments/vec_utils.c

RM = rm -rf

MAKEFLAGS =	--no-print-directory

HEADERS = -I./srcs/include/ -I MLX42/include

ifdef	BONUS
			SRC = $(SRC_BONUS)
			HEADERS = -I./srcs_bonus/include/ -I MLX42/include
endif

NUM_SRC = $(words $(SRC))
CURRENT_SRC = 0

OBJ =	$(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

LIBS	:= libft/libft.a MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

CFLAGS = -Wall -Wextra -Werror -g3 -Ofast

all:	libmlx $(NAME)

libmlx:
	@cmake MLX42 -B MLX42/build && make -C MLX42/build -j4

%.o: %.c
	$(eval CURRENT_SRC=$(shell echo $$(($(CURRENT_SRC)+1))))
	@echo "\033[1;34m[$(shell echo $$(($(CURRENT_SRC)*100/$(NUM_SRC))))%]\033[1;0m Compiling $<"
	@$(CC) $(CFLAGS) $(HEADERS) -c $^ -o $(<:%.c=%.o)

$(NAME):	$(OBJ)
		@echo "**********************"
		@echo "*     \033[1;33mCOMPILING\033[1;0m      *"
		@echo "**********************\n"
		@make -C libft
		@$(CC) $(CFLAGS) $(HEADERS) $(OBJ) $(LIBS) -o $@
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

bonus:
		@make BONUS=true

clean:
		@$(RM) $(OBJ) $(OBJ_BONUS)
		@$(RM) MLX42/build
		@make clean -C libft
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"

fclean:
		@$(RM) $(OBJ) $(OBJ_BONUS) $(NAME)
		@$(RM) MLX42/build
		@make fclean -C libft
		@echo "**********************"
		@echo "*     \033[1;32mCLEANED ALL\033[1;0m    *"
		@echo "**********************"

re:		fclean	all

run:	bonus
		@./$(NAME) $(ARG)

vrun:	bonus
		@valgrind ./$(NAME) $(ARG)

.PHONY:	all clean fclean re libmlx bonus
