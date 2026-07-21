NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -I $(LIBFT_DIR)

HEADER = include/push_swap.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
	src/main.c \
	src/benchmark.c \
	src/benchmark_utils.c \
	src/parse_input.c \
	src/validators.c \
	src/ft_atol.c \
	src/list_utils.c \
	src/free_utils.c \
	src/adaptive_tools.c \
	src/simple_sort.c \
	src/medium_sort.c \
	src/complex_sort.c \
	operations/operations_base.c \
	operations/swap_commands.c \
	operations/push_commands.c \
	operations/rotate_commands.c \
	operations/reverse_commands.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re