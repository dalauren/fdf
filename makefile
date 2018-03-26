# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalauren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 17:32:37 by dalauren          #+#    #+#              #
#    Updated: 2018/03/23 11:17:02 by dalauren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc -Wall -Werror -Wextra

LIBFT = ./libft/

LIB_M = -Llibft -lft -lmlx -framework OpenGl -framework Appkit

SRC = main.c \
	  parsing.c \

OBJ = $(SRC:.c=.o)

RM = rm -f

all :		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			$(CC) -o $(NAME) $(OBJ) $(LIB_M)

clean:
			$(RM) $(OBJ)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclen re
