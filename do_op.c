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
	ps -> op_total++;
	ps -> op_count[op]++;
}
