# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 17:09:09 by angmarti          #+#    #+#              #
#    Updated: 2022/11/10 14:57:19 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME=push_swap
# SRCS = \
# 		src/errors.c \
# 		src/lists.c \
# 		src/main.c \
# 		src/numbers.c \
# 		src/order.c \
# 		src/order_algorithm.c \
# 		src/push.c \
# 		src/rotate.c \
# 		src/rrotate.c \
# 		src/swap.c

# CC=gcc
# CFLAGS=-c -Wall -Werror -Wextra
# OBJS=$(SRCS:.c=.o)

# MYLIBFT_DIR			=	mylibft
# MYLIBFT				=	$(MYLIBFT_DIR)/libft.a
# INCS_DEFAULT_DIR	=	incs
# INCS				=	-I $(INCS_DEFAULT_DIR) -I $(MYLIBFT)/$(INCS_DEFAULT_DIR)

# make_libft:
# 	@make -C $(MYLIBFT_DIR)

# all: make_libft $(NAME)

# $(NAME): $(OBJS) $(MYLIBFT)
# 		$(CC) $(OBJS) -o $@

# %.o: %.c
# 		$(CC) $(CFLAGS) $(INCS) $< -o $@

# clean:
# 		rm -rf $(OBJS)
# 		make clean -C $(MYLIBFT_DIR)

# fclean: clean
# 		rm -rf  $(OBJS) $(NAME)
# 		make fclean -C $(MYLIBFT_DIR)

# .PHONY: all bonus clean fclean re

############################################################
############################################################
############################################################

NAME		=	push_swap

SRC			=	\
			src/errors.c \
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
CFLAGS		=	-Wall -Wextra -Werror # -g3 -fsanitize=address

all: $(NAME)

re: fclean all

%.o: %.c
	@echo "\033[32mPushSwap:\033[0m [Compilation:\033[33m $@\033[0m]"
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(LIBINCS) -I $(INCS)

$(NAME): $(SRCO)
	@make -C $(LIB_DIR)/
	@$(CC)  $(CFLAGS) -o $@ $^ $(LIB)
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "[\033[36m----- OK - PushSwap ------\033[0m]"
	@echo "[\033[32m--------------------------\033[0m]"
	@echo "\033[32muse: ./$(NAME) [numbers...]\033[0m"

clean:
	@echo "\033[32mPushSwap:\033[0m [\033[31mSuppression des .o\033[0m]"
	@make clean -C $(LIB_DIR)/
	@rm -f $(SRCO)

fclean:
	@echo "\033[32mPushSwap:\033[0m [\033[31mSuppression des .o\033[0m]"
	@rm -f $(SRCO)
	@echo "\033[32mPushSwap:\033[0m [\033[31mSuppression de $(NAME)\033[0m]"
	@make fclean -C $(LIB_DIR)/
	@rm -f $(NAME)

.PHONY: re clean fclean all