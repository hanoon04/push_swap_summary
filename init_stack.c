/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 00:24:54 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/06 00:24:54 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_stack(t_ps *ps)
{
	int	i;

	if (!ps)
		return ;
	ps -> a = malloc(sizeof(t_stack));
	ps -> b = malloc(sizeof(t_stack));
	if (!ps -> a || !ps -> b)
		error_exit(ps);
	ps -> a -> top = NULL;
	ps -> a -> size = 0;
	ps -> b -> top = NULL;
	ps -> b -> size = 0;
	ps -> strategy = STRAT_ADAPTIVE;
	ps -> flag_bench = 0;
	ps -> disorder = 0.0;
	ps -> op_total = 0;
	i = 0;
	while (i < 11)
		ps -> op_count[i++] = 0;
}
