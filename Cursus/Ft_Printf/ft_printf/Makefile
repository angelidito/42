# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 19:39:06 by angmarti          #+#    #+#              #
#    Updated: 2022/09/08 14:59:13 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_printf.c \
			srcs/pf_puts_fd.c \
			srcs/pf_putnbr_base_fd.c \
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

# CC		= gcc
# CFLAGS	= -Wall -Wextra -Werror -pedantic


# OBJS	= $(SRCS:.c=.o)
# NAME	= libftprintf.a
# RM		= /bin/rm -f
# # RM		=	rm -rf
# # AR		=	ar rcs

# all: $(NAME)

# # ${NAME}	:	${OBJS} ${AR} ${NAME} ${OBJS}
# $(NAME): $(OBJS) 
# 		ar rc $(NAME) $(OBJS)

# # $(OBJS):	$(CC) $(CFLAGS) -c $(SRCS)
# $(OBJS): gcc 
# 		$(CFLAGS) -c $(SRCS)

# clean:
# 	$(RM) $(OBJS)
	
# fclean:	clean
# 	$(RM) $(NAME)

# re:		fclean $(NAME)

# .PHONY: all clean fclean re

# CC		= gcc
# CFLAGS	= -Wall -Wextra -Werror -pedantic

# OBJS	= $(SRCS:.c=.o)
# NAME	= libftprintf.a
# RM		= /bin/rm -f

# $(NAME): $(OBJS)
# 	ar rc $(NAME) $(OBJS)
	
# all:	$(NAME)

# $(OBJS):
# 	gcc $(CFLAGS) -c $(SRCS)

# clean:
# 	$(RM) $(OBJS)
	
# fclean:	clean
# 	$(RM) $(NAME)

# re:		fclean $(NAME)

# .PHONY: all clean fclean re


#----------------------------------------------------------COMPILER
NAME = libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
#-g3 -fsanitize=address

#----------------------------------------------------------LIBS
LIB			=	./libft/libft.a
INCLUDES	=	-I ./incs -I ./libft/incs

#----------------------------------------------------------SOURCES
# SRCS		=	ft_printf.c ft_printf_tools_flag.c ft_printf_format.c ft_lib_fd.c \
# 				ft_print_1strings.c ft_print_2pointers.c ft_print_3integers.c \
# 				ft_print_4integers_unsigned.c ft_print_5hexa.c
OBJS		=	$(SRCS:.c=.o)

#----------------------------------------------------------RULES
all: lib_submodule $(NAME)

lib_submodule:
	@make -C ./libft

%.o: %.c
	-@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	ar rcs $(NAME) $(OBJS) $(LIB)

clean:
	@rm -rf $(OBJS)
	make clean -C ./libft_submodule

fclean: clean
	@rm -rf $(NAME)
	make fclean -C ./libft_submodule

re: fclean all

.PHONY: all clean fclean re