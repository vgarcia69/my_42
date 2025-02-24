/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:13:01 by vgarcia           #+#    #+#             */
/*   Updated: 2024/11/27 12:07:33 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	last_buf[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!join_update_buf(&str, last_buf))
		return (ft_bzero(last_buf, BUFFER_SIZE + 1), NULL);
	if (check_newline(str) >= 0)
		return (str);
	if (read_and_fill(&str, fd, last_buf) == -1)
		return (free(str), NULL);
	if (*str == 0)
		return (ft_bzero(last_buf, BUFFER_SIZE + 1), free(str), NULL);
	return (str);
}

int	read_and_fill(char **str, int fd, char *l_buf)
{
	char			*buf;
	char			*tmp;
	long int		read_size;

	read_size = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (0);
	buf[0] = '\0';
	while (read_size > 0 && check_newline(buf) < 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (free(buf), ft_bzero(l_buf, BUFFER_SIZE + 1), -1);
		buf[read_size] = '\0';
		tmp = *str;
		*str = ft_strjoin(tmp, buf);
		if (*str == NULL)
			return (ft_bzero(l_buf, BUFFER_SIZE + 1), free(tmp), free(buf), 0);
		free(tmp);
	}
	l_buf = ft_strcpy(l_buf, buf);
	free(buf);
	return (0);
}

long int	check_newline(const char *str)
{
	long int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	join_update_buf(char **str, char *last_buf)
{
	long int	i;

	i = 0;
	while (last_buf[i] && last_buf[i] != '\n')
		i++;
	if (last_buf[i] == '\n')
		i++;
	*str = ft_strjoin("", &last_buf[i]);
	if (*str == NULL)
		return (ft_bzero(last_buf, BUFFER_SIZE + 1), 0);
	while (last_buf[i] && last_buf[i] != '\n')
		i++;
	last_buf = ft_strcpy(last_buf, &last_buf[i]);
	return (1);
}
