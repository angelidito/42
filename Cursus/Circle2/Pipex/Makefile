# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:03:08 by angmarti          #+#    #+#              #
#    Updated: 2023/05/23 17:07:58 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# ****************************       FILES       ***************************** #
# **************************************************************************** #

NAME			=	pipex

SRC				=	\
					src/backslashes.c \
					src/case_2_cmds.c \
					src/checking_setting_no_bonus.c \
					src/errors.c \
					src/get_cmd_args.c \
					src/getting_executing.c \
					src/ft_functions.c \
					src/ft_split_not_escaped.c \
					src/main_no_bonus.c
OBJS				=	$(SRC:.c=.o)

SRC_B			=	\
					src/backslashes.c \
					src/case_n_cmds.c \
					src/case_2_cmds.c \
					src/checking_setting.c \
					src/errors.c \
					src/get_cmd_args.c \
					src/getting_executing.c \
					src/here_doc.c \
					src/ft_functions.c \
					src/ft_split_not_escaped.c \
					src/main.c
OBJS_B			=	$(SRC_B:.c=.o)

# **************************************************************************** #
# *****************************       LIBS       ***************************** #
# **************************************************************************** #

INCS_DIR		=	incs
LIBS_DIR		=	libs

LIBFT_DIR		=	$(LIBS_DIR)/mylibft
LIBFT_INCS_DIR	=	$(LIBFT_DIR)/$(INCS_DIR)
LIBFT			=	$(LIBFT_DIR)/libft.a

LIBS			=	${LIBFT} 

# **************************************************************************** #
# *****************************      CONFIG      ***************************** #
# **************************************************************************** #

CC				=	@gcc
C_FLAGS			=	-Wall -Wextra -Werror #-g3 -fsanitize=address
C_INCLUDES		=	-Imlx -I$(INCS_DIR) -I$(LIBFT_INCS_DIR)

MAKES			=	make -C $(LIBFT_DIR)/
MAKES_CLEAN		=	make clean -C $(LIBFT_DIR)/
MAKES_FCLEAN	=	make fclean -C $(LIBFT_DIR)/

# **************************************************************************** #
# *****************************      COLORS      ***************************** #
# **************************************************************************** #

GREEN			=	\033[1;32m
RED				=	\033[1;31m
BLUE			=	\033[1;34m
BBLUE			=	\033[7;49;34m
YELLOW			=	\033[1;33m
GRAY			=	\033[1;30m
NOCOLOR			=	\033[0m

# **************************************************************************** #
# *****************************       STUFF      ***************************** #
# **************************************************************************** #

%.o: %.c
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(C_INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@${MAKES}
	@echo
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo
	@echo
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)-------$(BBLUE) PIPEX - OK $(NOCOLOR)$(GREEN)-------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo

all: $(NAME)

re: fclean all

clean:
	@echo
	@${MAKES_CLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
	@rm -f $(OBJS) $(OBJS_B)
	@echo

fclean:
	@echo
	@${MAKES_FCLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
	@rm -f $(OBJS) $(OBJS_B)
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)$(NAME)$(NOCOLOR)]$(RED)"
	@rm -f $(NAME)
	@echo

bonus: $(OBJS_B)
	@${MAKES}
	@echo
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $(NAME) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(OBJS_B) $(LIBFT) -o $(NAME)
	@echo
	@echo
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)-------$(BBLUE) PIPEX - OK $(NOCOLOR)$(GREEN)-------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo

.PHONY:  all bonus clean fclean re
