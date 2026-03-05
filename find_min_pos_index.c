/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_pos_index.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:48:41 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/05 17:48:41 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min_pos_index(t_stack *stack)
{
	t_node	*cur;
	int		min;
	int		best;
	int		i;

	if (!stack || !stack->top)
		return (-1);
	cur = stack->top;
	min = cur->value;
	best = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			best = i;
		}
		cur = cur->next;
		i++;
	}
	return (best);
}
