/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabuhamm <kabuhamm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:55:42 by kabuhamm          #+#    #+#             */
/*   Updated: 2026/02/14 13:09:21 by kabuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack -> next)
	{
		if (stack -> value < stack -> next -> value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
