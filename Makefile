# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/30 10:17:50 by aihya             #+#    #+#              #
#    Updated: 2019/07/03 17:35:08 by aihya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = src/main.c \
	src/ms_env.c \
	src/ms_env_tools.c \
	src/ms_builtins.c \
	src/ms_feed_checker.c \
	src/ms_unsetenv.c \
	src/ms_setenv.c \
	src/ms_cd.c \
	src/ms_cd_tools.c \
	src/ms_parser.c \
	src/ms_echo.c \
	src/ms_expansions.c \
	src/ms_expansions_tools.c \
	src/ms_non_builtins.c \
	src/ms_signals.c \
	src/ms_error.c \
	src/ms_path_checker.c \
	src/get_next_line.c \
	src/get_next_line_free.c

all : $(NAME)

$(NAME) :
	@echo "\033[1;32m===> all :\033[0m"
	make -C libft
	gcc -g -Wall -Werror -Wextra $(SRC) -o $(NAME) libft/libft.a

clean :
	@echo "\033[1;32m===> clean :\033[0m"
	make -C libft clean

fclean :
	@echo "\033[1;32m===> fclean :\033[0m"
	make -C libft fclean
	/bin/rm -f $(NAME)

re : fclean all
