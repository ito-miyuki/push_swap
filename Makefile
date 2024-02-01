NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

SRCS =	init_a_to_b.c \
			init_b_to_a.c \
			push.c \
			rotate.c \
			rev_rotate.c \
			swap.c \
			sort_stacks.c \
			sort_three.c \
			stack_init.c \
			stack_utils.c \
			handle_errors.c \
			min_on_top.c \
			main.c		

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./libft

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
		$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

