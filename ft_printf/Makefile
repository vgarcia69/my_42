# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 18:58:09 by vincentgarc       #+#    #+#              #
#    Updated: 2024/11/18 13:21:13 by vgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
SRC = ./ft_printf.c\
		./ft_itoa.c\
		./ft_putchars.c\
		./ft_utils.c\
		./ft_putnbrs.c
OBJ=$(SRC:.c=.o)
NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -I . -c $< -o $@

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

PHONY.: re all clean fclean
