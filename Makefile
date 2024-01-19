NAME = push_swap

SRCS =	init_a_to_b.c \
			init_b_to_a.c \
			push.c rotate.c \
			rev_rotate.c \
			swap.c \
			sort_stacks.c \
			sort_three.c \
			stack_init.c \
			stack_utils.c \
			main.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
#		$(AR) $(NAME) $(OBJS)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:
		$(RM) $(OBJS)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re