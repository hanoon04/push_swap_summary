/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabuhamm <kabuhamm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:05:50 by kabuhamm          #+#    #+#             */
/*   Updated: 2026/02/14 13:06:53 by kabuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node -> value = value;
	node -> next = NULL;
	node -> index = 0;
	return (node);
}

t_node	*node_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}

int	node_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack -> next;
	}
	return (i);
}

void	node_add_back(t_node **stack, t_node *new_node)
{
	t_node	last;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = node_last(*stack);
	last -> next = new_node;
}

void	node_clear(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)-> next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
