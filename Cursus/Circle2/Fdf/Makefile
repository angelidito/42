# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:03:08 by angmarti          #+#    #+#              #
#    Updated: 2023/01/25 17:54:45 by angmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# ****************************       FILES       ***************************** #
# **************************************************************************** #

NAME			=	fdf
SRC				=	\
					src/main.c \
					src/colors/channels.c \
					src/colors/color.c \
					src/mapping/data_matrix.c \
					src/mapping/data_matrix_aux.c \
					src/mapping/mapping.c \
					src/mapping/point_matrix.c \
					src/mapping/printing.c \
					src/events/hooks.c \
					src/events/keys.c \
					src/events/mouse.c \
					src/events/moves.c \
					src/events/win.c \
					src/events/render_next_frame.c \
					src/drawing/circle.c \
					src/drawing/line.c \
					src/drawing/sqr.c
OBJ				=	$(SRC:.c=.o)



# **************************************************************************** #
# *****************************       LIBS       ***************************** #
# **************************************************************************** #

INCS_DIR		=	incs
LIBS_DIR		=	libs

LIBFT_DIR		=	$(LIBS_DIR)/mylibft
LIBFT_INCS_DIR	=	$(LIBFT_DIR)/$(INCS_DIR)
LIBFT			=	$(LIBFT_DIR)/libft.a

# GNL_DIR			=	$(LIBS_DIR)/gnl
# GNL_INCS_DIR	=	$(GNL_DIR)/
# GNL				=	$(GNL_DIR)/gnl.a

# MLX_DIR			=	$(LIBS_DIR)/gnl
# MLX_INCS_DIR	=	$(MLX_DIR)/
# MLX				=	$(MLX_DIR)/gnl.a

LIBS			=	${LIBFT} # ${GNL}



# **************************************************************************** #
# *****************************      CONFIG      ***************************** #
# **************************************************************************** #

CC				=	@gcc
C_FLAGS			=	-Wall -Wextra -Werror #-g3 -fsanitize=address
C_INCLUDES		=	-Imlx -I$(INCS_DIR) -I$(LIBFT_INCS_DIR)

MAKES			=	make -C $(LIBFT_DIR)/ ; 
MAKES_CLEAN		=	make clean -C $(LIBFT_DIR)/ ;
MAKES_FCLEAN	=	make fclean -C $(LIBFT_DIR)/ ;



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

$(NAME): $(OBJ)
	@${MAKES}
	@echo
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [Compilation:$(YELLOW) $@$(NOCOLOR)]$(GRAY)"
	$(CC) $(C_FLAGS) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo
	@echo
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------$(BBLUE) FDF - OK $(NOCOLOR)$(GREEN)--------$(NOCOLOR)]"
	@echo "$(NOCOLOR)[$(GREEN)--------------------------$(NOCOLOR)]"
	@echo
	@echo

all: $(NAME)

re: fclean all

clean:
	@echo
	@${MAKES_CLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
	@rm -f $(OBJ)
	@echo

fclean:
	@echo
	@${MAKES_FCLEAN}
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)*.o$(NOCOLOR)]"
	@rm -f $(OBJ)
	@echo "$(GREEN)$(NAME):$(NOCOLOR) [$(RED)Removing $(BLUE)$(NAME)$(NOCOLOR)]$(RED)"
	@rm -f $(NAME)
	@echo


.PHONY: re clean fclean all
