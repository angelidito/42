FILES	= ft_bzero \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_memcpy \
			ft_memset \
			ft_memmove \
			ft_memchr \
			ft_memcmp \
			ft_calloc \
			ft_strchr \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strncmp \
			ft_strnstr \
			ft_atoi \
			ft_strrchr \
			ft_tolower \
			ft_toupper \
			ft_strdup \
			ft_strjoin \
			ft_strtrim \
			ft_substr \
			ft_split \
			ft_itoa \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_strmapi \
			ft_striteri


NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
