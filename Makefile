# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfarkas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 18:24:04 by tdhaussy          #+#    #+#              #
#    Updated: 2023/12/22 22:07:52 by jfarkas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

NAME = ircserv

BOT = ircbot

SRC =	srcs/main.cpp \
		srcs/Client.cpp \
		srcs/Server.cpp \
		srcs/Exception.cpp \
		srcs/Channel.cpp \
		srcs/UserConnexion.cpp \
		srcs/CmdResponse.cpp \
		srcs/Parsing.cpp \
		srcs/OperatorCmds.cpp

BOT_SRC =	srcs/bot.cpp

OBJ =	$(SRC:srcs/%.cpp=objs/%.o)

BOT_OBJ = $(BOT_SRC:srcs/%.cpp=objs/%.o)

OBJ_DIR = objs

CPPFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

RM = rm -rf

all:	$(NAME)

objs/%.o: srcs/%.cpp
	$(CC) $(CPPFLAGS) -c $^ -o $(<:srcs/%.cpp=objs/%.o)

$(OBJ_DIR):
		@mkdir $@

$(NAME):	$(OBJ_DIR) $(OBJ)
		@echo "**\033[1;33mInstalling HexChat\033[1;0m**"
		@flatpak install flathub io.github.Hexchat -y
		@echo "**\033[1;32mHexChat installed\033[1;0m***"
		@echo "**********************"
		@echo "*     \033[1;33mCOMPILING\033[1;0m      *"
		@echo "**********************\n"
		$(CC) $(CPPFLAGS) $(OBJ) -o $@
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

bot:	$(OBJ_DIR) $(BOT_OBJ)
		@echo "**********************"
		@echo "*   \033[1;33mCOMPILING BOT\033[1;0m    *"
		@echo "**********************\n"
		$(CC) $(CPPFLAGS) $(BOT_OBJ) -o $(BOT)
		@echo "**********************"
		@echo "*        \033[1;32mDONE\033[1;0m        *"
		@echo "**********************"

clean:
		$(RM) $(OBJ_DIR) answer.json
		@echo "**********************"
		@echo "*    \033[1;32mCLEANED OBJS\033[1;0m    *"
		@echo "**********************"

fclean:
		$(RM) $(OBJ_DIR) $(NAME) $(BOT) answer.json
		@echo "**********************"
		@echo "*     \033[1;32mCLEANED ALL\033[1;0m    *"
		@echo "**********************"

re:		fclean	all

.PHONY:	all clean fclean re
