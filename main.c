/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main (2).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:45:47 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/08 00:45:47 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		start_i;

	if (argc < 2)
		return (0);
	ps.a = NULL;
	ps.b = NULL;
	init_stack(&ps);
	start_i = 1;
	parse_flags(&ps, argc, argv, &start_i);
	parse_input(&ps, argc, argv, start_i);
	if (ps.a -> size < 2)
	{
		free_all(&ps);
		return (0);
	}
	assign_index(ps.a);
	run_strategy(&ps);
	if (ps.flag_bench)
		print_bench(&ps);
	free_all(&ps);
	return (0);
}
