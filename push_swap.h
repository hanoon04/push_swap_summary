/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:24:26 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/04 15:24:26 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;

}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

typedef struct s_ps
{
	t_stack		*a;
	t_stack		*b;

	t_strategy	strategy;
	int			flag_bench;
	double		disorder;

	long		op_total;
	long		op_count[11];
}	t_ps;

int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_sorted(t_node *stack);
int		node_size(t_node *stack);
int		get_max_bits(t_ps *ps);
int		find_max_pos_index(t_stack *stack);
int		find_min_pos_index(t_stack *stack);
int		parse_flags(t_ps *ps, int argc, char **argv, int *start_i);
int		is_all_spaces(const char *s);
int		is_space(char c);
long	ft_atol(const char *str);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
void	assign_index(t_stack *a);
void	node_clear(t_node **stack);
void	node_add_back(t_node **stack, t_node *new_node);
t_node	*node_last(t_node *stack);
t_node	*node_new(int value);
void	push(t_stack *src, t_stack *dst);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	swap_printer(t_stack *s, char c);
void	ss(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	rotate_printer(t_stack *s, char c);
void	rr(t_stack *a, t_stack *b);
void	rev_rotate(t_stack *s);
void	rev_rotate_printer(t_stack *s, char c);
void	rrr(t_stack *a, t_stack *b);
void	op_dispatch(char *op, t_stack *a, t_stack *b);
void	do_op(t_ps *ps, t_op op);
void	sort2(t_ps *ps);
void	sort3(t_ps *ps);
void	insertion_sort(t_ps *ps);
void	radix_sort(t_ps *ps);
void	error_exit(t_ps *ps);
void	free_all(t_ps *ps);
void	init_stack(t_ps *ps);
void	parse_input(t_ps *ps, int argc, char **argv, int start_i);
void	print_bench(t_ps *ps);
void	rotate_b_to_top(t_ps *ps, int pos);

#endif
