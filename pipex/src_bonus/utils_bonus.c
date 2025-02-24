/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:19:41 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/15 09:42:59 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	is_valid_quote(char *str)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (str[i])
		if (str[i++] == 39)
			++index;
	return (index % 2);
}

char	*cut_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	if (str[0] == 39 && str[i - 1] == 39)
	{
		str[i - 1] = '\0';
		++str;
	}
	return (str);
}

void	error(int status, char *s)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(status);
}
