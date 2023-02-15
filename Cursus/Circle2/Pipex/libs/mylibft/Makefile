# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:17:59 by angmarti          #+#    #+#              #
#    Updated: 2023/02/14 18:54:02 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	srcs/ft_bzero.c \
			srcs/ft_isalnum.c \
			srcs/ft_isalpha.c \
			srcs/ft_isascii.c \
			srcs/ft_isdigit.c \
			srcs/ft_isprint.c \
			srcs/ft_memcpy.c \
			srcs/ft_memset.c \
			srcs/ft_memmove.c \
			srcs/ft_memchr.c \
			srcs/ft_memcmp.c \
			srcs/ft_calloc.c \
			srcs/ft_strchr.c \
			srcs/ft_strlcat.c \
			srcs/ft_strlcpy.c \
			srcs/ft_strlen.c \
			srcs/ft_strncmp.c \
			srcs/ft_strnstr.c \
			srcs/ft_atoi.c \
			srcs/ft_strrchr.c \
			srcs/ft_tolower.c \
			srcs/ft_toupper.c \
			srcs/ft_strdup.c \
			srcs/ft_strjoin.c \
			srcs/ft_strtrim.c \
			srcs/ft_substr.c \
			srcs/ft_split.c \
			srcs/ft_itoa.c \
			srcs/ft_putchar_fd.c \
			srcs/ft_putendl_fd.c \
			srcs/ft_putnbr_fd.c \
			srcs/ft_putstr_fd.c \
			srcs/ft_strmapi.c \
			srcs/ft_striteri.c \
			srcs/ft_lstnew_bonus.c \
			srcs/ft_lstadd_back_bonus.c \
			srcs/ft_lstadd_front_bonus.c \
			srcs/ft_lstsize_bonus.c \
			srcs/ft_lstdelone_bonus.c \
			srcs/ft_lstclear_bonus.c \
			srcs/ft_lstiter_bonus.c \
			srcs/ft_lstmap_bonus.c \
			srcs/ft_lstlast_bonus.c \
			srcs/ft_printf.c \
			srcs/ft_printf_puts_fd.c \
			srcs/ft_printf_puts_bases_fd.c \
			srcs/get_next_line_bonus.c \
			srcs/get_next_line_utils_bonus.c \
			srcs/ft_isspace.c \
			srcs/ft_str_replace_dup_whitespaces.c
OBJS	= $(SRCS:.c=.o)

#----------------------------------------------------------COMPILER
NAME	= libft.a
CC 		= @gcc
CFLAGS	= -Wall -Werror -Wextra


#----------------------------------------------------------RULES
%.o: %.c
#	@echo "\033[32mLibft:\033[0m [Compilation:\033[33m $< $@\033[0m]\033[30m"
	-@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@echo "\033[32mLibft:\033[0m [Compilation:\033[33m *.o *.c\033[0m]\033[30m"
# ${CC} ${CFLAGS} -c ${SRCS}
	@echo "\033[32mLibft:\033[0m [Compilation:\033[33m $@\033[0m]\033[30m"
	@ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	@echo "\033[32mLibft:\033[0m [\033[31mRemoving \033[34m*.o\033[0m]\033[31m"
	@rm -f ${OBJS}

fclean: clean
	@echo "\033[32mLibft:\033[0m [\033[31mRemoving \033[34m$(NAME)\033[0m]\033[31m"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
