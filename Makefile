NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = main.c \
		init_stack.c \
		check_argv.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		simple_solution.c \
		presort.c \
		solution.c \
		check_presort.c \
		utils.c \
		push_swap.c \
		last_move.c \
		utils2.c


OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDE = -I $(LIBFT_DIR)
LDFLAGS = -L $(LIBFT_DIR) -lft

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(INCLUDE) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re