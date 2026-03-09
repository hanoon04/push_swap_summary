/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args (1).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:40:07 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/09 23:40:07 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	is_valid_int_token(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	stack_contains(t_node *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	handle_token(t_ps *ps, const char *tok)
{
	long	nb;
	t_node	*n;

	if (!is_valid_int_token(tok))
		return (0);
	nb = ft_atol(tok);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	if (stack_contains(ps->a->top, (int)nb))
		return (0);
	n = node_new((int)nb);
	if (!n)
		return (0);
	node_add_back(&ps->a->top, n);
	ps->a->size++;
	return (1);
}

static void	parse_split_input(t_ps *ps, char *arg)
{
	char	**tokens;
	int		i;

	if (arg[0] == '\0' || is_all_spaces(arg))
		error_exit(ps);
	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		free_split(tokens);
		error_exit(ps);
	}
	i = 0;
	while (tokens[i])
	{
		if (!handle_token(ps, tokens[i]))
		{
			free_split(tokens);
			error_exit(ps);
		}
		i++;
	}
	free_split(tokens);
}

void	parse_input(t_ps *ps, int argc, char **argv, int start_i)
{
	int	i;

	if (!ps || start_i >= argc)
		error_exit(ps);
	if (argc - start_i == 1)
	{
		parse_split_input(ps, argv[start_i]);
		return ;
	}
	i = start_i;
	while (i < argc)
	{
		if (!handle_token(ps, argv[i]))
			error_exit(ps);
		i++;
	}
}
