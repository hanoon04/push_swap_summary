/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:55:47 by hal-tawa          #+#    #+#             */
/*   Updated: 2025/12/08 14:55:47 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "psuh_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	if (n == 0)
		return (0);
	while (1)
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (i == n - 1 || s1[i] == '\0' || s2[i] == '\0')
			break ;
		if (res < 0 || res > 0)
			break ;
		i++;
	}
	return (res);
}
