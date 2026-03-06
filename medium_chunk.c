/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:10:18 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/06 16:10:18 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	x;

	x = 0;
	while ((x + 1) * (x + 1) <= n)
		x++;
	return (x);
}

static t_chunk	init_chunks(t_ps *ps)
{
	t_chunk	c;

	c.n = ps -> a -> size;
	c.chunk_count = int_sqrt(c.n);
	if (c.chunk_count < 1)
		c.chunk_count = 1;
	c.chunk_size = c.n / c.chunk_count;
	if (c.chunk_size < 1)
		c.chunk_size = 1;
	c.limit = c.chunk_size - 1;
	c.pushed = 0;
	return (c);
}

static void	run_chunks(t_ps *ps, t_chunk *c)
{
	while (c -> pushed < c -> n)
	{
		if (ps -> a -> top -> index <= c -> limit)
		{
			do_op(ps, OP_PB);
			c -> pushed++;
			if (ps -> b -> top
				&& ps -> b -> top -> index < c -> limit - (c -> chunk_size / 2))
				do_op(ps, OP_RB);
			if (c -> pushed > c -> limit)
				c -> limit += c -> chunk_size;
			if (c -> limit >= c -> n)
				c -> limit = c -> n - 1;
		}
		else
			do_op(ps, OP_RA);
	}
}

static void	rebuild_a(t_ps *ps)
{
	int	pos;

	while (ps -> b -> size > 0)
	{
		pos = find_max_pos_index(ps -> b);
		rotate_b_to_top(ps, pos);
		do_op(ps, OP_PA);
	}
}

void	medium_sort(t_ps *ps)
{
	t_chunk	c;

	if (!ps || !ps -> a || ps -> a -> size < 2)
		return ;
	c = init_chunks(ps);
	run_chunks(ps, &c);
	rebuild_a(ps);
}
