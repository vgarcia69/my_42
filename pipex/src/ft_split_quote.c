/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:21:50 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/17 08:37:46 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	count_word_quote(const char *s, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[j] && s[j] != '\n')
	{
		if (s[j] == c)
			++j;
		else
		{
			if (!j || (s[j - 1] == c && index == 0))
				++i;
			++j;
		}
		if (s[j] == 39 && index == 0)
			++index;
		else if (s[j] == 39 && index == 1)
			--index;
		if (s[j] == 39 && index == 1)
			i++;
	}
	return (i);
}

static int	cut_word(char **s, char c)
{
	int	i;
	int	index;

	index = 0;
	i = 0;
	while (**s)
	{
		if (**s == 39 && index == 0)
			++index;
		else if (**s == 39 && index == 1)
			--index;
		if (**s == c && index == 0)
			break ;
		i++;
		(*s)++;
	}
	while (**s && **s == c)
		(*s)++;
	return (i);
}

static char	*fill_str(char **str, char c, char *result)
{
	int		j;
	int		index;

	j = 0;
	index = 0;
	while (**str != '\0')
	{
		if (**str == 39 && index == 0)
			++index;
		else if (**str == 39 && index == 1)
			--index;
		if (**str == c && index == 0)
			break ;
		result[j++] = *(*str)++;
	}
	result = cut_quote(result);
	return (result);
}

static char	**fill_strs(char **strs, char *str, char c)
{
	int		i;
	int		word_cut;
	char	*to_cut;

	to_cut = str;
	i = 0;
	while (*str != '\0')
	{
		word_cut = cut_word(&to_cut, c);
		strs[i] = malloc(sizeof(char) * (word_cut + 1));
		if (strs[i] == NULL)
		{
			free_tab(strs);
			return (NULL);
		}
		strs[i][word_cut] = '\0';
		strs[i] = fill_str(&str, c, strs[i]);
		while (*str != '\0' && *str == c)
			str++;
		i++;
	}
	return (strs);
}

char	**ft_split_quote(char *str, char c)
{
	char	**strs;
	int		words_count;

	if (!str || *str == c)
		return (NULL);
	words_count = count_word_quote(str, c);
	strs = malloc(sizeof(char *) * (words_count + 1));
	if (strs == NULL)
		return (NULL);
	strs[words_count] = NULL;
	strs = fill_strs(strs, str, c);
	return (strs);
}
