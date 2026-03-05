/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:41:55 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/05 21:41:55 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	is_flag(const char *s)
{
	return (s && s[0] == '-' && s[1] == '-');
}

static int	streq(const char *a, const char *b)
{
	int	i;

	if (!a || !b)
		return (0);
	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] == '\0' && b[i] == '\0');
}

int	parse_flags(t_ps *ps, int argc, char **argv, int *start_i)
{
	int	i;

	if (!ps || !start_i)
		return (0);
	i = 1;
	while (i < argc && is_flag(argv[i]))
	{
		if (streq(argv[i], "--bench"))
			ps -> flag_bench = 1;
		else if (streq(argv[i], "--simple"))
			ps -> strategy = STRAT_SIMPLE;
		else if (streq(argv[i], "--medium"))
			ps -> strategy = STRAT_MEDIUM;
		else if (streq(argv[i], "--complex"))
			ps -> strategy = STRAT_COMPLEX;
		else if (streq(argv[i], "--adaptive"))
			ps -> strategy = STRAT_ADAPTIVE;
		else
			error_exit(ps);
		i++;
	}
	*start_i = i;
	if (*start_i >= argc)
		error_exit(ps);
	return (1);
}
