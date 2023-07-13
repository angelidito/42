# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:03:08 by angmarti          #+#    #+#              #
#    Updated: 2023/07/13 19:01:37 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# ******************************     FILES      ****************************** #
# **************************************************************************** #


# ******************************     BONUS      ****************************** #
# ifdef BONUS

# 	NAME		=	philo_bonus

# 	SRCS		=	\
# 					error.c \
# 					main.c
# 	SRC_DIR		=	philo_bonus/srcs/

# ******************************    MANDATORY   ****************************** #
# else

NAME			=	philo
SRCS			=	\
					main.c
SRC_DIR			=	srcs/
	
# endif

# **************************************************************************** #
# ******************************     CONFIG     ****************************** #
# **************************************************************************** #

# ******************************      DIRS      ****************************** #
OBJ_DIR			=	objs/
INCS_DIR		=	incs
LIBS_DIR		=	libs

# ******************************     LIBFT      ****************************** #
LIBFT_DIR		=	#$(LIBS_DIR)/mylibft
LIBFT_INCS_DIR	=	#$(LIBFT_DIR)/$(INCS_DIR)
LIBFT			=	#$(LIBFT_DIR)/libft.a

# ******************************   EXT MAKES    ****************************** #
MAKES			=	#@make -C $(LIBFT_DIR)/
MAKES_CLEAN		=	#@make clean -C $(LIBFT_DIR)/
MAKES_FCLEAN	=	#@make fclean -C $(LIBFT_DIR)/

# ******************************      OBJS      ****************************** #
# OBJS			=	$(SRCS:.c=.o)
OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# ******************************    COMPILE     ****************************** #
CC				=	gcc
C_FLAGS			=	-Wall -Wextra -Werror #-g3 -fsanitize=address
C_INCLUDES		=	-I$(INCS_DIR) #-I$(LIBFT_INCS_DIR)
LINKS			=	#-lreadline

# ******************************     CLEAN      ****************************** #
RM 				= @rm -rf $(OBJS) $(OBJ_DIR) $(SRC_DIR)*o
RM_NAME 		= @rm -f $(NAME)

# ******************************     COLORS     ****************************** #
GREEN			=	\033[1;32m
RED				=	\033[1;31m
BLUE			=	\033[1;34m
BBLUE			=	\033[7;49;34m
YELLOW			=	\033[1;33m
GRAY			=	\033[1;30m
NOCOLOR			=	\033[0m

# **************************************************************************** #
# ******************************      RULES     ****************************** #
# **************************************************************************** #

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(C_INCLUDES) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS)
	${MAKES}
	@echo
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME) ${LINKS}
	@echo
	@echo
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)-----$(BBLUE)    MAKE OK     $(NOCOLOR)$(GREEN)-----$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo

# bonus:
# 	@$(MAKE) BONUS=1


exec:
	@$(MAKE)
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)-----$(BBLUE)   EXECUTING    $(NOCOLOR)$(GREEN)-----$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo
	@./$(NAME)
	@echo "$(NOCOLOR)[$(BLUE)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(BLUE)-----$(BBLUE)    FINISHED    $(NOCOLOR)$(BLUE)-----$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(BLUE)--------------------------$(NOCOLOR)]"


clean:
	@echo
	${MAKES_CLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)$(OBJ_DIR)*$(NOCOLOR)]"
	$(RM) 
	@echo

fclean:
	@echo
	${MAKES_CLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)$(OBJ_DIR)*$(NOCOLOR)]"
	$(RM) 
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)$(NAME)$(NOCOLOR)]$(RED)"
	$(RM_NAME)
	@echo

re: fclean all

.PHONY:  all clean fclean re
