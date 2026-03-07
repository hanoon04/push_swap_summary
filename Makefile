NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = \
       complex_sort.c \
       do_op.c \
       error_exit.c \
       find_max_pos_index.c \
       find_min_pos_index.c \
       flags.c \
       free_all.c \
       ft_bzero.c \
       ft_calloc.c \
       ft_isdigit.c \
       ft_memcpy.c \
       ft_putchar_fd.c \
       ft_putnbr_fd.c \
       ft_putstr_fd.c \
       ft_split.c \
       ft_strlen.c \
       ft_strncmp.c \
       indexing.c \
       init_stack.c \
       is_all_spaces.c \
       is_sorted.c \
       is_space.c \
       list.c \
       parse_args.c \
       print_bench.c \
       push.c \
       rev_rotate.c \
       rotate_b_to_top.c \
       rotate.c \
       simple_sort.c \
       small_sort.c \
       swap.c \
       ft_atol.c \
       disorder.c \
       medium_chunk.c \
       adaptive.c \
       print_utils.c \
       strategy.c \
       main.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
