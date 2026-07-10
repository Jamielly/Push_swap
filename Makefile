NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I include -I libft/include
LFLAGS		= -lm

SRC_DIR		= src
BONUS_DIR	= bonus

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/stack.c \
			  $(SRC_DIR)/operations.c \
			  $(SRC_DIR)/parse.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/disorder.c \
			  $(SRC_DIR)/sort_simple.c \
			  $(SRC_DIR)/sort_medium.c \
			  $(SRC_DIR)/sort_complex.c \
			  $(SRC_DIR)/sort_adaptive.c \
			  $(SRC_DIR)/bench.c

BONUS_SRCS	= $(BONUS_DIR)/checker.c \
			  $(SRC_DIR)/stack.c \
			  $(SRC_DIR)/operations.c \
			  $(SRC_DIR)/parse.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/disorder.c \
			  $(SRC_DIR)/sort_simple.c \
			  $(SRC_DIR)/sort_medium.c \
			  $(SRC_DIR)/sort_complex.c \
			  $(SRC_DIR)/sort_adaptive.c \
			  $(SRC_DIR)/bench.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.bo)

# ── libft ─────────────────────────────────────────────────────────────────────
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# ── Rules ─────────────────────────────────────────────────────────────────────

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(LFLAGS) -o $(BONUS_NAME)

%.bo: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re