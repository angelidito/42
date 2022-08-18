# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 19:39:06 by angmarti          #+#    #+#              #
#    Updated: 2022/08/18 19:41:30 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			printing_utilities.c \
			conversion_utilities.c

OBJS	= 	${SRCS:.c=.o}

CC		= gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -rf

AR		=	ar rcs

all: $(NAME)

${NAME}	:	${OBJS} 
			${AR} ${NAME} ${OBJS}

clean:	
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re