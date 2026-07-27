# Nome do executável final
NAME = push_swap

# Compilador e Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes -I./libft

# Caminho da Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Arquivos fonte do Push_swap
SRCS = src/main.c \
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

# Objetos
OBJS = $(SRCS:.c=.o)

# Regra principal
all: $(NAME)

# Regra para compilar o executável (Depende da libft e dos objetos)
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Regra para compilar a Libft automaticamente (Entra na pasta e roda o make de lá)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Regra de limpeza dos arquivos .o
clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

# Regra de limpeza total (Apaga o executável e a biblioteca)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Refaz tudo do zero
re: fclean all

.PHONY: all clean fclean re