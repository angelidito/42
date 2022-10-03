# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 19:39:06 by angmarti          #+#    #+#              #
#    Updated: 2022/10/03 16:18:41 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------------------------SOURCES
SRCS	=	srcs/ft_printf.c \
			srcs/pf_puts_fd.c \
			srcs/pf_puts_bases_fd.c \
			libft/ft_bzero.c \
			libft/ft_isalnum.c \
			libft/ft_isalpha.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_isprint.c \
			libft/ft_memcpy.c \
			libft/ft_memset.c \
			libft/ft_memmove.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_calloc.c \
			libft/ft_strchr.c \
			libft/ft_strlcat.c \
			libft/ft_strlcpy.c \
			libft/ft_strlen.c \
			libft/ft_strncmp.c \
			libft/ft_strnstr.c \
			libft/ft_atoi.c \
			libft/ft_strrchr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \
			libft/ft_strdup.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_substr.c \
			libft/ft_split.c \
			libft/ft_itoa.c \
			libft/ft_putchar_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_strmapi.c \
			libft/ft_striteri.c \
			libft/ft_lstnew_bonus.c \
			libft/ft_lstadd_back_bonus.c \
			libft/ft_lstadd_front_bonus.c \
			libft/ft_lstsize_bonus.c \
			libft/ft_lstdelone_bonus.c \
			libft/ft_lstclear_bonus.c \
			libft/ft_lstiter_bonus.c \
			libft/ft_lstmap_bonus.c \
			libft/ft_lstlast_bonus.c
OBJS		=	$(SRCS:.c=.o)

#----------------------------------------------------------COMPILER
NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#----------------------------------------------------------LIBS
LIB			=	./libft/libft.a
INCLUDES	=	-I ./incs -I ./libft/incs

#----------------------------------------------------------RULES
all: inc_libft $(NAME)

inc_libft:
	@make -C ./libft

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	ar rcs $(NAME) $(OBJS) $(LIB)

clean:
	@rm -rf $(OBJS)
	make clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re