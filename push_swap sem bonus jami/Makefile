NAME        = push_swap

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INC_DIR     = include
LIBFT_DIR   = libft

INCLUDES    = -I $(INC_DIR) -I $(LIBFT_DIR)

LIBFT       = $(LIBFT_DIR)/libft.a

HEADER      = $(INC_DIR)/push_swap.h

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

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re