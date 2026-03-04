/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 01:17:22 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/20 01:17:22 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_ps *ps)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(ps -> a -> top))
		return ;
	first = ps -> a -> index;
	second = ps -> a -> next -> index;
	third = ps -> a -> next -> next -> index;
	if (first == 0 && second == 2 && third == 1)
	{
		do_op(ps, OP_RRA);
		do_op(ps, OP_SA);
	}
	else if (first == 2 && second == 1 && third == 0)
	{
		do_op(ps, OP_SA);
		do_op(ps, OP_RRA);
	}
	else if (first == 1 && second == 0 && third == 2)
		do_op(ps, OP_SA);
	else if (first == 1 && second == 2 && third == 0)
		do_op(ps, OP_RRA);
	else if (first == 2 && second == 0 && third == 1)
		do_op(ps, OP_RA);
}

void	sort2(t_ps *ps)
{
	if (is_sorted(ps -> a -> top))
		return ;
	do_op(ps, OP_SA);
}
