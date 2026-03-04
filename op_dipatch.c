/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dipatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:21:33 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/15 16:21:33 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}

static void	print_op(t_op op)
{
	if (op == OP_SA)
		putstr("sa\n");
	else if (op == OP_SB)
		putstr("sb\n");
	else if (op == OP_SS)
		putstr("ss\n");
	else if (op == OP_PA)
		putstr("pa\n");
	else if (op == OP_PB)
		putstr("pb\n");
	else if (op == OP_RA)
		putstr("ra\n");
	else if (op == OP_RB)
		putstr("rb\n");
	else if (op == OP_RR)
		putstr("rr\n");
	else if (op == OP_RRA)
		putstr("rra\n");
	else if (op == OP_RRB)
		putstr("rrb\n");
	else if (op == OP_RRR)
		putstr("rrr\n");
}

void	do_op(t_ps *ps, t_op op)
{
	if (op == OP_SA)
		swap_printer(ps -> a, 'a');
	else if (op == OP_SB)
		swap_printer(ps -> b, 'b');
	else if (op == OP_SS)
		ss(ps -> a, ps -> b);
	else if (op == OP_PA)
		pa(ps -> a, ps -> b);
	else if (op == OP_PB)
		pb(ps -> a, ps -> b);
	else if (op == OP_RA)
		rotate_printer(ps -> a, 'a');
	else if (op == OP_RB)
		rotate_printer(ps -> b, 'b');
	else if (op == OP_RR)
		rr(ps -> a, ps -> b);
	else if (op == OP_RRA)
		rev_rotate_printer(ps -> a, 'a');
	else if (op == OP_RRB)
		rev_rotate_printer(ps -> b, 'b');
	else if (op == OP_RRR)
		rrr(ps -> a, ps -> b);
	print_op(op);
	ps -> op_total++;
	ps -> op_count[op]++;
}
