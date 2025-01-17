/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:35:06 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/09 10:43:26 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all_str(char **strs, int word_nbr)
{
	int	i;

	i = 0;
	while (i < word_nbr)
	{
		free(strs[i++]);
	}
	free(strs);
}
