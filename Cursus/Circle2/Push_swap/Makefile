# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:09:09 by angmarti          #+#    #+#              #
#    Updated: 2022/11/15 16:32:04 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRC			=	\
			src/errors_check.c \
			src/errors_exit.c \
			src/lists.c \
			src/main.c \
			src/numbers.c \
			src/order.c \
			src/order_algorithm.c \
			src/push.c \
			src/rotate.c \
			src/rrotate.c \
			src/swap.c 
#  src/check_leaks.c

SRCO		=	$(SRC:.c=.o)
LIB_DIR		=   mylibft
LIBINCS		=	$(LIB_DIR)/incs
LIB			=	$(LIB_DIR)/libft.a
INCS		=	incs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror #-g3 -fsanitize=address

all: $(NAME)

re: fclean all

%.o: %.c
	@echo "\033[32mPushSwap:\033[0m [Compilation:\033[33m $@\033[0m]\033[30m"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(LIBINCS) -I $(INCS)

$(NAME): $(SRCO)
	@echo
	@make -C $(LIB_DIR)/
	@echo
	@echo "\033[32mPushSwap:\033[0m [Compilation:\033[33m $@\033[0m]\033[30m"
	@$(CC)  $(CFLAGS) -o $@ $^ $(LIB)
	@echo
	@echo 
	@echo "\033[0m[\033[32m--------------------------\033[0m]"
	@echo "[\033[32m----- \033[36mPushSwap - OK \033[32m------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"
	@echo
	@echo
	@echo
	@echo "\033[32mUsage: ./$(NAME) [numbers...]\033[0m"
	@echo
	@echo

clean:
	@echo
	@echo "\033[32mPushSwap:\033[0m [\033[31mRemoving \033[34m*.o\033[0m]"
#@echo "\033[30mfrom $(LIB_DIR)\033[31m"
	@make clean -C $(LIB_DIR)/
#@echo "\033[30mfrom src\033[31m"
	@rm -f $(SRCO)
	@echo

fclean:
	@echo
	@echo "\033[32mPushSwap:\033[0m [\033[31mRemoving \033[34m*.o\033[0m]"
#@echo "\033[30mfrom $(LIB_DIR)\033[31m"
	@make fclean -C $(LIB_DIR)/
#@echo "\033[30mfrom src\033[31m"
	@rm -f $(SRCO)
	@echo "\033[32mPushSwap:\033[0m [\033[31mRemoving \033[34m$(NAME)\033[0m]\033[31m"
	@rm -f $(NAME)
	@echo

.PHONY: re clean fclean all