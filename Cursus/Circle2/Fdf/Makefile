# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:03:08 by angmarti          #+#    #+#              #
#    Updated: 2022/11/21 16:02:32 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	myfdf
SRC			= src/main.c \
			src/skill_testing/sqr.c \
			src/skill_testing/circle.c 

OBJ			=	$(SRC:.c=.o)
# LIB_DIR		=   mylibft
# LIBINCS		=	$(LIB_DIR)/incs
# LIB			=	$(LIB_DIR)/libft.a
INCS		=	incs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-g3 -fsanitize=address


# COLORS
GREEN	= \033[0;32m
RED		= \033[0;31m
BLUE	= \033[0;34m
YELLOW	= \033[0;33m
GRAY	= \033[0;30m
NOCOLOR	= \033[0m

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -I$(INCS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(GREEN)Fdf:$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


all: $(NAME)

re: fclean all

clean:
	@echo
	@echo "$(GREEN)Fdf:$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
# @make clean -C $(LIB_DIR)/
	@rm -f $(OBJ)
	@echo

fclean:
	@echo
	@echo "$(GREEN)Fdf:$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
# @make fclean -C $(LIB_DIR)/
	@rm -f $(OBJ)
	@echo "$(GREEN)Fdf:$(NOCOLOR) [$(RED)Removing $(BLUE)$(NAME)$(NOCOLOR)]$(RED)"
	@rm -f $(NAME)
	@echo


.PHONY: re clean fclean all
