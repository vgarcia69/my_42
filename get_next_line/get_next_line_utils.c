/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:13:42 by vgarcia           #+#    #+#             */
/*   Updated: 2024/11/26 22:12:46 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *s1, const char *s2)
{
	long int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char		*s3;
	long int	i;
	long int	j;

	if (!s1 || !s2)
		return (NULL);
	j = check_newline(s2);
	if (j < 0)
		j = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + j) + 2);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		if (s2[j++] == '\n')
			break ;
	}
	s3[i + j] = '\0';
	return (s3);
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*(char *)s = 0;
		s++;
	}
}
