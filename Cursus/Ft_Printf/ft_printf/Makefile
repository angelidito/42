# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 19:39:06 by angmarti          #+#    #+#              #
#    Updated: 2022/09/01 18:21:37 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	srcs/ft_printf.c \
			srcs/pf_puts_fd.c \
			libft/ft_itoa.c

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