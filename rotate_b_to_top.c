/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b_to_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:50:23 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/05 17:50:23 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_b_to_top(t_ps *ps, int pos)
{
	int	size;

	if (!ps || !ps->b || pos < 0 || pos >= ps -> b -> size)
		return ;
	size = ps->b->size;
	if (size <= 1)
		return ;
	if (pos <= size / 2)
		while (pos-- > 0)
			do_op(ps, OP_RB);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			do_op(ps, OP_RRB);
	}
}
