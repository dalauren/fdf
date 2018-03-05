# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/04 13:14:05 by vpoccard          #+#    #+#              #
#    Updated: 2018/02/26 17:18:41 by vpoccard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS =  main.c\
		read.c\
		parse.c\
		init.c\
		bonus.c\
		algo.c

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I libft -I include -I /usr/local/include
LIBS = -L libft/ -lft -lmlx -framework OpenGL -framework Appkit
RM = rm -f
CLEAN = clean
HEAD = fdf.h

all :		$(NAME)

$(NAME) :	$(OBJS) $(HEAD)
			@make -C libft
			@$(CC) -o $(NAME) $(OBJS) $(LIBS)
			@echo "\033[1;36mFDF OK\033[0m"

clean :
			@$(RM) $(OBJS)
			@make -C Libft/ fclean
			@echo "\033[0;93mFDF : -.o  OK\033[0m"

fclean : 	clean
			@$(RM) $(NAME)
			@make -C Libft/ fclean
			@echo "\033[0;93mFDF : -fdf  OK\033[0m"

re :		fclean all
