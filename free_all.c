/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:15:25 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/05 17:15:25 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_all(t_ps *ps)
{
	if (!ps)
		return ;
	if (ps -> a)
	{
		node_clear(&ps -> a -> top);
		free(ps -> a);
		ps -> a = NULL;
	}
	if (ps -> b)
	{
		node_clear(&ps -> b -> top);
		free(ps -> b);
		ps -> b = NULL;
	}
}
