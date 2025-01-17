/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:45:09 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/17 09:45:11 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	count_line_and_len(char *txt, int *count, int *len_ls)
{
	char	*line;
	int		fd;

	*count = 0;
	fd = open(txt, O_RDONLY);
	line = get_next_line(fd);
	*len_ls = count_word(line, ' ');
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		(*count)++;
	}
	close(fd);
}
