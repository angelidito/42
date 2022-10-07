# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 17:12:38 by angmarti          #+#    #+#              #
#    Updated: 2022/10/03 17:17:46 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl.a

SRCS	=	get_next_line.c \
			get_next_line_utils.c



OBJS	= $(SRCS:.c=.o)


CFLAGS	= -Wall -Werror -Wextra

CC 		= gcc

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -c ${SRCS}
	ar rcs ${NAME} ${OBJS} 

all: ${NAME} 

clean:
	rm -f ${OBJS} 

fclean: clean
	rm -f $(NAME)

re: fclean all bonus



.PHONY: all bonus clean fclean re

