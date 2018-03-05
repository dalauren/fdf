# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoccard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 01:47:34 by vpoccard          #+#    #+#              #
#    Updated: 2018/02/19 10:42:04 by vpoccard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c\
	   ft_bzero.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_memccpy.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_strcat.c\
	   ft_strncat.c\
	   ft_strchr.c\
	   ft_strcmp.c\
	   ft_strcpy.c\
	   ft_strdup.c\
	   ft_strlen.c\
	   ft_strncmp.c\
	   ft_strncpy.c\
	   ft_strnstr.c\
	   ft_strrchr.c\
	   ft_strstr.c\
	   ft_tolower.c\
	   ft_toupper.c\
	   ft_memalloc.c\
	   ft_memdel.c\
	   ft_strnew.c\
	   ft_strdel.c\
	   ft_strclr.c\
	   ft_striter.c\
	   ft_striteri.c\
	   ft_strmap.c\
	   ft_strmapi.c\
	   ft_strequ.c\
	   ft_strnequ.c\
	   ft_strsub.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_putchar.c\
	   ft_putstr.c\
	   ft_putchar_fd.c\
	   ft_putendl.c\
	   ft_putendl_fd.c\
	   ft_putnbr.c\
	   ft_putnbr_fd.c\
	   ft_putstr_fd.c\
	   ft_strlcat.c\
	   ft_lstnew.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_lstadd.c\
	   ft_lstiter.c\
	   ft_strsplit.c\
	   ft_itoa.c\
	   ft_lstmap.c\
	   get_next_line.c

OBJS = $(SRCS:.c=.o)
CFLAGS += -Wall -Wextra -Werror
CC = gcc
RM = rm -f

all : $(NAME)

$(NAME) :
	@$(CC) -c $(CFLAGS) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[1;35mLIBFT OK\033[0m"

clean :
	@$(RM) $(OBJS)
	@echo "\033[1;35mLIBFT : -.o OK\033[0m"

fclean : clean
	@$(RM) $(NAME)
	@echo "\033[1;35mLIBFT : -libft.a OK\033[0m"

re : fclean all