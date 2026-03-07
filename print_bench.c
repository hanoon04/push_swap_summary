/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench (1).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:40:19 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/08 00:40:19 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static const char	*get_strategy_name(t_ps *ps)
{
	if (ps -> strategy == STRAT_ADAPTIVE)
		return ("Adaptive");
	if (ps -> used_strategy == USED_SMALL)
		return ("Small");
	if (ps -> used_strategy == USED_SIMPLE)
		return ("Simple");
	if (ps -> used_strategy == USED_MEDIUM)
		return ("Medium");
	if (ps -> used_strategy == USED_COMPLEX)
		return ("Complex");
	return ("Unknown");
}

static void	print_bench_header(t_ps *ps)
{
	putstr_fd("[bench] disorder: ", 2);
	put_percent_fd(ps->disorder * 100.0, 2);
	putstr_fd("\n", 2);
	putstr_fd("[bench] strategy: ", 2);
	putstr_fd(get_strategy_name(ps), 2);
	putstr_fd(" / ", 2);
	putstr_fd(get_complexity(ps), 2);
	putstr_fd("\n", 2);
	putstr_fd("[bench] total_ops: ", 2);
	putnbr_fd(ps -> op_total, 2);
	putstr_fd("\n", 2);
}

static void	print_bench_ops1(t_ps *ps)
{
	putstr_fd("[bench] sa: ", 2);
	putnbr_fd(ps -> op_count[OP_SA], 2);
	putstr_fd(" sb: ", 2);
	putnbr_fd(ps -> op_count[OP_SB], 2);
	putstr_fd(" ss: ", 2);
	putnbr_fd(ps -> op_count[OP_SS], 2);
	putstr_fd(" pa: ", 2);
	putnbr_fd(ps -> op_count[OP_PA], 2);
	putstr_fd(" pb: ", 2);
	putnbr_fd(ps -> op_count[OP_PB], 2);
	putstr_fd("\n", 2);
}

static void	print_bench_ops2(t_ps *ps)
{
	putstr_fd("[bench] ra: ", 2);
	putnbr_fd(ps -> op_count[OP_RA], 2);
	putstr_fd(" rb: ", 2);
	putnbr_fd(ps -> op_count[OP_RB], 2);
	putstr_fd(" rr: ", 2);
	putnbr_fd(ps -> op_count[OP_RR], 2);
	putstr_fd(" rra: ", 2);
	putnbr_fd(ps -> op_count[OP_RRA], 2);
	putstr_fd(" rrb: ", 2);
	putnbr_fd(ps -> op_count[OP_RRB], 2);
	putstr_fd(" rrr: ", 2);
	putnbr_fd(ps -> op_count[OP_RRR], 2);
	putstr_fd("\n", 2);
}

void	print_bench(t_ps *ps)
{
	if (!ps)
		return ;
	print_bench_header(ps);
	print_bench_ops1(ps);
	print_bench_ops2(ps);
}
