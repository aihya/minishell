# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aihya <aihya@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 16:28:57 by aihya             #+#    #+#              #
#    Updated: 2019/07/09 13:57:53 by aihya            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = src/ft_abs.c \
		src/ft_atoi.c \
		src/ft_begins_with.c \
		src/ft_bzero.c \
		src/ft_chain_cpy.c \
		src/ft_chain_free.c \
		src/ft_chain_push.c \
		src/ft_chain_size.c \
		src/ft_count_words.c \
		src/ft_ctos.c \
		src/ft_intlen.c \
		src/ft_isalnum.c \
		src/ft_isalpha.c \
		src/ft_isalphanumeric.c \
		src/ft_isascii.c \
		src/ft_isdigit.c \
		src/ft_isprint.c \
		src/ft_itoa.c \
		src/ft_memalloc.c \
		src/ft_memccpy.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_memcpy.c \
		src/ft_memdel.c \
		src/ft_memmove.c \
		src/ft_memset.c \
		src/ft_new_chain.c \
		src/ft_next_word.c \
		src/ft_print_chain.c \
		src/ft_putchar.c \
		src/ft_putchar_fd.c \
		src/ft_putendl.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr.c \
		src/ft_putnbr_fd.c \
		src/ft_putstr.c \
		src/ft_putstr_fd.c \
		src/ft_strappend.c \
		src/ft_strcat.c \
		src/ft_strchr.c \
		src/ft_strclr.c \
		src/ft_strcmp.c \
		src/ft_strcount.c \
		src/ft_strcpy.c \
		src/ft_strdel.c \
		src/ft_strdup.c \
		src/ft_strequ.c \
		src/ft_striter.c \
		src/ft_striteri.c \
		src/ft_strjoin.c \
		src/ft_strlcat.c \
		src/ft_strlen.c \
		src/ft_strmap.c \
		src/ft_strmapi.c \
		src/ft_strncat.c \
		src/ft_strncmp.c \
		src/ft_strncpy.c \
		src/ft_strnequ.c \
		src/ft_strnew.c \
		src/ft_strnstr.c \
		src/ft_strojoin.c \
		src/ft_strrchr.c \
		src/ft_strrev.c \
		src/ft_strsjoin.c \
		src/ft_strsplit.c \
		src/ft_strsplit_del.c \
		src/ft_strstr.c \
		src/ft_strsub.c \
		src/ft_strtrim.c \
		src/ft_tolower.c \
		src/ft_toupper.c \
		src/ft_wordlen.c \
		src/ft_words.c

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(SRCS) -I includes/
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
