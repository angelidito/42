NAME = push_swap
LIBFT = libft/libft.a
SRCS = src/push_swap.c src/libstack.c src/algorithms.c src/libstack2.c src/libstack3.c src/error_management.c src/algorithms2.c
OBJS = $(patsubst src/%, obj/%, $(SRCS:.c=.o))
CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIB = -Llibft -lft
INC = -Ilibft -Iinclude
############################
$(NAME): $(OBJS) $(LIBFT)
	$(CC) -g $(CFLAGS) $^ -o $@ $(LIB)

$(LIBFT): 
	make bonus -C libft

all: $(NAME)

obj/%.o: src/%.c
	$(CC) -c -g $(CFLAGS) $< -o $@ $(INC)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)
	make fclean -C libft

re: fclean $(NAME)