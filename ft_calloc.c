/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:51:24 by hal-tawa          #+#    #+#             */
/*   Updated: 2025/12/08 14:51:24 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	new = malloc(nmemb * size);
	if (!new)
		return (NULL);
	while (i < (nmemb * size))
	{
		((unsigned char *)new)[i] = (unsigned char)0;
		i++;
	}
	return (new);
}
