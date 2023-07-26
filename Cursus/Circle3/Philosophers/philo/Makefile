# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:03:08 by angmarti          #+#    #+#              #
#    Updated: 2023/07/26 19:23:46 by angmarti         ###   ########.fr        #
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

SRC_DIR			=	srcs/
SRC_libft		=	libft

SRCS			=	\
					$(SRC_libft)/ft_atoi.c \
					$(SRC_libft)/ft_itoa.c \
					data.c \
					death.c \
					eat.c \
					error.c \
					philosopher.c \
					print1.c \
					print2.c \
					sleep.c \
					think.c \
					time.c \
					main.c
	
# endif

# **************************************************************************** #
# ******************************   EXECUTION    ****************************** #
# **************************************************************************** #

# EXEC			=	./philo 1 800 200 200 # muere
EXEC			=	./philo 5 800 200 200 # viven
# EXEC			=	./philo 5 800 200 200 7 # viven y cada uno come 7 veces
# EXEC			=	./philo 4 410 200 200 # viven
# EXEC			=	./philo 5 310 200 100 # mueren
# EXEC			=	./philo 3 310 100 100 # (tienen que vivir)
# EXEC			=	./philo 3 310 103 103 # (tienen que vivir)
# EXEC			=	./philo 3 310 104 104 # (tienen que morir) y si no te lo hace bien te lo tire

# EXEC			=	./philo 50 300 109 109
# EXEC			=	./philo 100 330 200 100
# EXEC			=	./philo 50  500 450 40
# EXEC			=	./philo 5 420 200 200
# EXEC			=	./philo 2 100 50 51
# EXEC			=	./philo 1 800 200 200

# **************************************************************************** #
# ******************************     CONFIG     ****************************** #
# **************************************************************************** #

# ******************************      DIRS      ****************************** #
OBJ_DIR			=	objs/
OBJ_SUBDIRS		=	\
					$(SRC_libft)
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
CC				=	@gcc
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
BGREEN			=	\033[7;49;32m
BBLUE			=	\033[7;49;34m
BRED			=	\033[7;49;31m
BYELLOW			=	\033[7;49;33m
YELLOW			=	\033[1;33m
GRAY			=	\033[1;30m
COLOR_RESET			=	\033[0m

# **************************************************************************** #
# ******************************      RULES     ****************************** #
# **************************************************************************** #

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR), $(OBJ_SUBDIRS))
	@echo "$(GREEN)$(NAME):$(COLOR_RESET) [Compilation:$(YELLOW) $@$(COLOR_RESET)]$(GRAY)"
	$(CC) $(C_FLAGS) $(C_INCLUDES) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS)
	${MAKES}
	@echo
	@echo "$(GREEN)$(NAME):$(COLOR_RESET) [Compilation:$(YELLOW) $@$(COLOR_RESET)]$(GRAY)"
	$(CC) $(C_FLAGS) $(OBJS) $(LIBFT) -o $(NAME) ${LINKS}
	@echo
	@echo "$(COLOR_RESET)$(GREEN)"
	@echo "[--Makefile says...--------]"
	@echo "[-----$(BGREEN)    MAKE DONE   $(COLOR_RESET)$(GREEN)-----]"
	@echo "[--------------------------]"

# bonus:
# 	@$(MAKE) BONUS=1


exec:
	@$(MAKE)
	@echo
	@echo "$(COLOR_RESET)\033[31m$(EXEC) $(RED)" 
	@echo "[--Makefile says...--------]"
	@echo "[-----$(BRED)   EXECUTING!   $(COLOR_RESET)$(RED)-----]"
	@echo "[--------------------------]"
	@echo "$(COLOR_RESET)"
	@$(EXEC)
	@echo "$(COLOR_RESET)$(YELLOW)"
	@echo "[--Makefile says...--------]"
	@echo "[-----$(BYELLOW) EXEC. FINISHED $(COLOR_RESET)$(YELLOW)-----]"
	@echo "[--------------------------]"


clean:
	@echo
	${MAKES_CLEAN}
	@echo "$(GREEN)$(NAME):$(COLOR_RESET) [$(RED)Removing $(BLUE)$(OBJ_DIR)*$(COLOR_RESET)]"
	$(RM) 
	@echo

fclean:
	@echo
	${MAKES_CLEAN}
	@echo "$(GREEN)$(NAME):$(COLOR_RESET) [$(RED)Removing $(BLUE)$(OBJ_DIR)*$(COLOR_RESET)]"
	$(RM) 
	@echo "$(GREEN)$(NAME):$(COLOR_RESET) [$(RED)Removing $(BLUE)$(NAME)$(COLOR_RESET)]$(RED)"
	$(RM_NAME)
	@echo

re: fclean all

.PHONY:  all clean fclean re
