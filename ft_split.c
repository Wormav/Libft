/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:27:31 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/25 00:43:22 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	ft_free_all(char **result, int words)
{
	while (words >= 0)
	{
		lp_free(result[words]);
		words--;
	}
	lp_free(result);
}

static void	ft_search_index(char const *s, char c, int *start, int *end)
{
	while (s[*end] == c)
		(*end)++;
	*start = *end;
	while (s[*end] && s[*end] != c)
		(*end)++;
}

static int	ft_write_word(char const *s, char **word,
int start_index, int end_index)
{
	int	i;

	*word = lp_alloc(sizeof(char) * (end_index - start_index + 1));
	if (!*word)
		return (0);
	i = 0;
	while (start_index < end_index)
	{
		(*word)[i] = s[start_index];
		start_index++;
		i++;
	}
	(*word)[i] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = lp_alloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	end = 0;
	while (i < words)
	{
		ft_search_index(s, c, &start, &end);
		if (!ft_write_word(s, &result[i], start, end))
			return (ft_free_all(result, i - 1), NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
