/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:04:56 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/06 16:04:56 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static long	count_inversions(t_node *head)
{
	t_node	*i;
	t_node	*j;
	long	inv;

	inv = 0;
	i = head;
	while (i)
	{
		j = i -> next;
		while (j)
		{
			if (i -> value > j -> value)
				inv++;
			j = j -> next;
		}
		i = i -> next;
	}
	return (inv);
}

static long	total_pairs(int n)
{
	return ((long)n * (long)(n - 1) / 2);
}

double	calc_disorder(t_ps *ps)
{
	long	inv;
	long	pairs;

	if (!ps -> a || !ps -> a -> top || ps -> a -> size < 2)
		return (0.0);
	pairs = total_pairs(ps -> a -> size);
	if (pairs == 0)
		return (0.0);
	inv = count_inversions(ps -> a -> top);
	return ((double)inv / (double)pairs);
}
