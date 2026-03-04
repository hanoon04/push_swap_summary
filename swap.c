/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:20:02 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/15 16:20:02 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a -> size < 2)
		return ;
	first = a -> top;
	second = a -> top -> next;
	first -> next = second -> next;
	second -> next = first;
	a -> top = second;
}

void	swap_printer(t_stack *s, char c)
{
	swap(s);
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
