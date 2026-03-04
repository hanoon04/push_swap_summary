/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 01:05:44 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/02 01:05:44 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_ps *ps)
{
	t_node	*current;
	int		value;
	int		rb_count;

	while (ps -> a -> top)
	{
		current = ps -> a -> top;
		value = current -> value;
		rb_count = 0;
		while (ps -> b -> top && ps -> b -> top -> value > value
			&& rb_count < ps -> b -> size)
		{
			do_op(ps, OP_RB);
			rb_count++;
		}
		do_op(ps, OP_PB);
		while (rb_count--)
			do_op(ps, OP_RRB);
	}
	while (ps -> b -> top)
		do_op(ps, OP_PA);
}
