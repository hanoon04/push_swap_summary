/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:21:02 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/15 16:21:02 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack *s)
{
	t_node	*last;
	t_node	*first;
	t_node	*prev_last;

	if (!s || s -> size < 2)
		return ;
	prev_last = s -> top;
	while (prev_last -> next -> next)
		prev_last = prev_last -> next;
	last = prev_last -> next;
	prev_last -> next = NULL;
	first = s -> top;
	s -> top = last;
	last -> next = first;
}

void	rev_rotate_printer(t_stack *s, char c)
{
	rev_rotate(s);
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
