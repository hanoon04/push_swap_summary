/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:31:48 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/06 23:31:48 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_strategy(t_ps *ps, double dis)
{
	if (!ps)
		return ;
	if (dis < 0.2)
	{
		ps -> used_strategy = USED_SIMPLE;
		insertion_sort(ps);
	}
	else if (dis < 0.5)
	{
		ps -> used_strategy = USED_MEDIUM;
		medium_sort(ps);
	}
	else
	{
		ps -> used_strategy = USED_COMPLEX;
		radix_sort(ps);
	}
}

void	adaptive(t_ps *ps)
{
	double	dis;

	if (is_sorted(ps -> a -> top))
		return ;
	dis = calc_disorder(ps);
	ps -> disorder = dis;
	if (ps -> a -> size == 2)
	{
		ps -> used_strategy = USED_SMALL;
		sort2(ps);
	}
	else if (ps -> a -> size == 3)
	{
		ps -> used_strategy = USED_SMALL;
		sort3(ps);
	}
	else
		choose_strategy(ps, dis);
}
