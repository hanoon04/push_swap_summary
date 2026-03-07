/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:44:12 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/08 00:44:12 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	run_small(t_ps *ps)
{
	ps -> used_strategy = USED_SMALL;
	if (ps -> a -> size == 2)
		sort2(ps);
	else
		sort3(ps);
}

static void	run_simple(t_ps *ps)
{
	if (ps -> a -> size == 2 || ps -> a -> size == 3)
		run_small(ps);
	else
	{
		ps -> used_strategy = USED_SIMPLE;
		insertion_sort(ps);
	}
}

static void	run_medium(t_ps *ps)
{
	if (ps -> a -> size == 2 || ps -> a -> size == 3)
		run_small(ps);
	else
	{
		ps -> used_strategy = USED_MEDIUM;
		medium_sort(ps);
	}
}

static void	run_complex(t_ps *ps)
{
	if (ps -> a -> size == 2 || ps -> a -> size == 3)
		run_small(ps);
	else
	{
		ps -> used_strategy = USED_COMPLEX;
		radix_sort(ps);
	}
}

void	run_strategy(t_ps *ps)
{
	ps -> disorder = calc_disorder(ps);
	if (ps -> strategy == STRAT_SIMPLE)
		run_simple(ps);
	else if (ps -> strategy == STRAT_MEDIUM)
		run_medium(ps);
	else if (ps -> strategy == STRAT_COMPLEX)
		run_complex(ps);
	else
		adaptive(ps);
}
