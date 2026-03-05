/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 00:29:22 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/06 00:29:22 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	putstr_fd(const char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

static void	putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	print_bench(t_ps *ps)
{
	int	i;

	if (!ps)
		return ;
	putstr_fd("Total ops: ", 2);
	putnbr_fd(ps -> op_total, 2);
	putstr_fd("\n", 2);
	i = 0;
	while (i < 11)
	{
		putstr_fd("op[", 2);
		putnbr_fd(i, 2);
		putstr_fd("]: ", 2);
		putnbr_fd(ps -> op_count[i], 2);
		putstr_fd("\n", 2);
		i++;
	}
}
