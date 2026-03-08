/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:43:33 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/08 00:43:33 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	putstr_fd(const char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

void	putnbr_fd(long n, int fd)
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

void	put2_fd(int n, int fd)
{
	char	c;

	c = '0' + (n / 10);
	write(fd, &c, 1);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	put_percent_fd(double x, int fd)
{
	int	whole;
	int	frac;

	if (x < 0)
		x = 0;
	whole = (int)x;
	frac = (int)((x - whole) * 100 + 0.5);
	if (frac == 100)
	{
		whole++;
		frac = 0;
	}
	putnbr_fd(whole, fd);
	write(fd, ".", 1);
	put2_fd(frac, fd);
	write(fd, "%", 1);
}

const char	*get_complexity(t_ps *ps)
{
	if (ps -> strategy == STRAT_ADAPTIVE)
		return ("O(n√n)");
	if (ps -> used_strategy == USED_SMALL)
		return ("O(1)");
	if (ps -> used_strategy == USED_SIMPLE)
		return ("O(n^2)");
	if (ps -> used_strategy == USED_MEDIUM)
		return ("O(n√n)");
	if (ps -> used_strategy == USED_COMPLEX)
		return ("O(n log n)");
	return ("unknown");
}
