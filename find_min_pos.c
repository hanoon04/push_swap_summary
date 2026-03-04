/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:26:45 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/15 16:26:45 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_node *stack)
{
	int	min;
	int	i;
	int	pos;

	if (!stack)
		return (-1);
	min = stack -> value;
	i = 0;
	pos = 0;
	while (stack)
	{
		if (stack -> value < min)
		{
			min = stack -> value;
			pos = i;
		}
		stack = stack -> next;
		i ++;
	}
	return (pos);
}
