NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDES = -I include

SRCS	= src/ft_putchar_fd.c \
		  src/ft_putstr_fd.c \
		  src/ft_putnbr_fd.c \
		  src/ft_strlen.c \
		  src/ft_strdup.c \
		  src/ft_itoa.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re