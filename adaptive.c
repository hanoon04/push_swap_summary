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

void	adaptive(t_ps *ps)
{
	double	dis;

	if (is_sorted(ps -> a -> top))
		return ;
	dis = calc_disorder(ps);
	ps -> disorder = dis;
	if (ps -> a -> size == 2)
		sort2(ps);
	else if (ps -> a -> size == 3)
		sort3(ps);
	else if (dis < 0.2)
		insertion_sort(ps);
	else if (dis < 0.5)
		medium_sort(ps);
	else
		radix_sort(ps);
}
