/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:36 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 13:54:36 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_ps *ps)
{
	int		count;
	int		max;
	t_node	*current;

	current = ps -> a -> top;
	max = 0;
	while (current)
	{
		if (current -> index > max)
			max = current -> index;
		current = current -> next;
	}
	count = 0;
	while (max > 0)
	{
		max /= 2;
		count++;
	}
	return (count);
}

void	radix_sort(t_ps *ps)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_bits = get_max_bits(ps -> a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = ps -> a -> size;
		while (j < ps -> a -> size)
		{
			if (((ps -> a -> top -> index >> i) & 1) == 0)
				do_op(ps, OP_PB);
			else
				do_op(ps, OP_RA);
			j++;
		}
		while (ps -> b -> size > 0)
			do_op(ps, OP_PA);
		i++;
	}
}
