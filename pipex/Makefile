# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 08:35:32 by vgarcia           #+#    #+#              #
#    Updated: 2025/01/15 10:30:33y vgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

SRC=src/main.c\
	src/utils.c\
	src/exec_managing.c\
	src/check_access.c\
	src/ft_split_quote.c
	
SRC_BONUS=src_bonus/main_bonus.c\
	src_bonus/check_access_bonus.c\
	src_bonus/utils_bonus.c\
	src_bonus/exec_managing_bonus.c\
	src_bonus/here_doc_bonus.c\
	src_bonus/ft_split_quote_bonus.c
	
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

SRCDIR_BONUS=src_bonus
OBJDIR_BONUS=.obj_bonus
OBJ_BONUS=$(SRC_BONUS:$(SRCDIR_BONUS)/%.c=$(OBJDIR_BONUS)/%.o)

CFLAGS= -Wextra -Wall -g3 -Werror

INC=pipex.h

PATH_LIB=./libft/
LIB=libft.a

NAME=pipex
NAME_BONUS=pipex_bonus

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJ) $(PATH_LIB)$(LIB)
	@$(MAKE) --no-print-directory -C $(PATH_LIB)
	@$(CC) $(OBJ) -o $(NAME) $(PATH_LIB)$(LIB)
	@echo "Pipex Compiled !"

$(NAME_BONUS) : $(OBJ_BONUS) $(PATH_LIB)
	@$(MAKE) --no-print-directory -C $(PATH_LIB)
	@$(CC) $(OBJ_BONUS) -o $(NAME_BONUS) $(PATH_LIB)$(LIB)
	@echo "Pipex Bonus Compiled !"

$(PATH_LIB)$(LIB) : $(LIBFT_FILES)
	@$(MAKE) --no-print-directory -C $(PATH_LIB)

$(OBJDIR)/%.o : src/%.c $(INC) Makefile $(PATH_LIB)$(LIB) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"
	
$(OBJDIR_BONUS)/%.o : src_bonus/%.c $(INC) Makefile $(PATH_LIB)$(LIB) | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

$(OBJDIR_BONUS) :
	@mkdir -p $(OBJDIR_BONUS)

clean :
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJDIR_BONUS)
	@echo "Objects cleaned"

lclean :
	@$(MAKE) --no-print-directory fclean -C $(PATH_LIB)

fclean : lclean clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "Exec cleaned"

flclean : fclean lclean

re : fclean all

.PHONY : fclean clean re all lclean flclean bonus 
