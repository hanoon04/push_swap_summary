/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:58:40 by hal-tawa          #+#    #+#             */
/*   Updated: 2025/12/21 16:58:40 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*get_word(char const *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all_split(char **arr, int j)
{
	while (j > 0)
		free(arr[--j]);
	free(arr);
}

static int	stor_in_array(char const *s, char c, char **arr)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word = get_word(s + i, c);
			if (!word)
			{
				free_all_split(arr, j);
				return (0);
			}
			arr[j++] = word;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (words(s, c) + 1));
	if (!arr)
		return (NULL);
	if (!stor_in_array(s, c, arr))
		return (NULL);
	return (arr);
}
