# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 08:35:32 by vgarcia           #+#    #+#              #
#    Updated: 2025/01/30 07:35:21 by vgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Werror -Wextra -Wall -g3

SRC=src/main.c\
	src/utils.c\
	src/life.c\
	src/routines.c\
	src/time.c\
	src/var.c
	
SRCDIR=src
OBJDIR=.obj
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INC=philo.h

NAME=philo

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "$@ Compiled !"

$(OBJDIR)/%.o : src/%.c $(INC) Makefile | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"
	
$(OBJDIR) :
	@mkdir -p $(OBJDIR)

clean :
	@rm -rf $(OBJDIR)
	@rm -rf $(OBJDIR_BONUS)
	@rm -f .bonus
	@echo "Objects cleaned"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "Exec cleaned"

re : fclean all

.PHONY : fclean clean re all 
