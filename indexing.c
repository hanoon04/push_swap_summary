/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:16:55 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/20 20:16:55 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	int		i;
	t_node	*current;
	t_node	*compare;

	current = a -> top;
	while (current)
	{
		compare = a -> top;
		i = 0;
		while (compare)
		{
			if (current -> value > compare -> value)
				i++;
			compare = compare -> next;
		}
		current -> index = i;
		current = current -> next;
	}
}
