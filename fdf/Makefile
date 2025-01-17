# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 10:47:05 by vgarcia           #+#    #+#              #
#    Updated: 2025/01/17 09:42:51 by vgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
SRC=src/main.c\
	src/print_map.c\
	src/input_managing.c\
	src/parsing_map.c\
	src/count_functions.c\
	src/geometry.c\
	src/points_managing.c\
	src/utils.c\
	src/input_functions.c\
	src/bonus_rotate.c

LIBFT=ft_isalpha.c\
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
SRCDIR=src
OBJDIR=.obj
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CFLAGS= -Wextra -Wall -Werror -g3
LIB=libft.a
PATH_LIB=./libft/
MLX=libmlx.a
PATH_MLX=./mlx_linux/
NAME=fdf
INC=fdf.h

all : $(NAME)

$(NAME) : $(OBJ) 
	@$(MAKE) --no-print-directory -C $(PATH_LIB)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(PATH_LIB)$(LIB)
	@echo "FDF Compiled !"

$(OBJDIR)/%.o : src/%.c $(INC) Makefile $(PATH_MLX)$(MLX) $(PATH_LIB)$(LIB) | $(OBJDIR)
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "Compiling $<"

$(PATH_LIB)$(LIB) : $(LIBFT_FILES)
	@$(MAKE) --no-print-directory -C $(PATH_LIB)

$(PATH_MLX)$(MLX) :
	@$(MAKE) --no-print-directory -C $(PATH_MLX)

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

clean :
	@rm -rf $(OBJDIR)
	@echo "Objects cleaned"

lclean :
	@$(MAKE) fclean -C $(PATH_LIB)
	@$(MAKE) clean -C $(PATH_MLX)

fclean : lclean clean
	@rm -f $(NAME)
	@echo "FDF Exec cleaned"

flclean : fclean lclean

re : fclean all

.PHONY : fclean clean re all lclean flclean 
