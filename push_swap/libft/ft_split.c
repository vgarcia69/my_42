/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:54:52 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/09 10:43:50 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_strs_one(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c)
			++j;
		else
		{
			if (j == 0 || s[j - 1] == c)
				++i;
			++j;
		}
	}
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	return (strs);
}

static char	**alloc_strs(char const *s, char c, size_t wn, size_t word_size)
{
	char	**strs;

	strs = alloc_strs_one(s, c);
	if (!strs)
		return (NULL);
	while (*s)
	{
		word_size = 0;
		if (*s && *s == c)
			s++;
		else
		{
			while (s[word_size] != c && s[word_size])
				++word_size;
			s += word_size;
			strs[wn] = malloc(sizeof(char) * (word_size + 1));
			if (!strs[wn])
			{
				free_all_str(strs, wn);
				return (NULL);
			}
			++wn;
		}
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	strs = alloc_strs(s, c, i, j);
	if (!strs)
		return (NULL);
	while (*s)
	{
		j = 0;
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				strs[i][j++] = *s++;
			strs[i++][j] = '\0';
		}
	}
	strs[i] = NULL;
	return (strs);
}
