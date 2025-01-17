# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 08:59:43 by vgarcia           #+#    #+#              #
#    Updated: 2025/01/17 09:24:03 by vgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wextra -Wall -Werror -g3

SRC= src/stack.c\
		src/solver.c\
		src/ps_func2.c\
		src/ps_func1.c\
		src/main.c\
		src/value_to_index.c\
		src/utils.c\
		src/utils_solver.c\
		src/choose_sort.c

LIBFT=ft_isalpha.c\
	free_all_str.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_printf_utils.c\
	ft_printf_writechars.c\
	ft_printf_writenbrs.c\
	ft_printf.c\
	ft_strcpy.c\
	get_next_line.c\
	libft.h\
	Makefile

LIBFT_FILES=$(addprefix $(PATH_LIB), $(LIBFT))
LIB=libft.a
PATH_LIB=./libft/

SRCDIR=src
OBJDIR=.obj
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
INC=push_swap.h

NAME=push_swap

all : $(NAME)

$(NAME) : $(OBJ) $(PATH_LIB)$(LIB)
	@$(MAKE) --no-print-directory -C $(PATH_LIB)
	@$(CC) -o $(NAME) $(OBJ) $(PATH_LIB)$(LIB)
	@echo "Push_swap compiled !"

$(OBJDIR)/%.o : src/%.c $(INC) Makefile $(PATH_LIB)$(LIB) | $(OBJDIR)
	@$(CC) $(CFLAGS) -I . -c $< -o $@
	@echo "Compiling $<"

$(PATH_LIB)$(LIB) : $(LIBFT_FILES)
	@$(MAKE) --no-print-directory -C $(PATH_LIB)

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

clean :
	@rm -rf $(OBJDIR)
	@echo "Cleaning objects"

lclean :
	@$(MAKE) --no-print-directory fclean -C $(PATH_LIB)

fclean : clean lclean
	@rm -f $(NAME)
	@echo "Cleaning exec"

re : fclean all

.PHONY : re clean fclean all lclean
