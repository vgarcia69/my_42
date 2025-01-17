/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:26:56 by vgarcia           #+#    #+#             */
/*   Updated: 2024/11/18 13:28:11 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isinbase(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_reversestr(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	new_str = malloc(sizeof(char) * (i + 1));
	if (!new_str)
		return (NULL);
	new_str[i] = '\0';
	while (i--)
		new_str[j++] = str[i];
	free(str);
	ft_writestr(new_str);
	return (new_str);
}
