# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 13:44:22 by psegura-          #+#    #+#              #
#    Updated: 2022/07/22 10:55:25 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -pedantic

SRCS	=	ft_putnbr_base.c	\
			utils.c 			\
			ft_printf.c			\

OBJS	= $(SRCS:.c=.o)
NAME	= libftprintf.a
RM		= /bin/rm -f

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	
all:	$(NAME)

$(OBJS):
	gcc $(CFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY: all clean fclean re