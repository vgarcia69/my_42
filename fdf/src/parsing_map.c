/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:54:54 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/17 09:43:39 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	init_map(int ***map, int cl, int len_ls)
{
	int	i;

	i = 0;
	*map = malloc(sizeof(int *) * (cl + 1));
	if (*map == NULL)
		return (ERROR);
	while (i < cl)
	{
		(*map)[i] = malloc(sizeof(int) * (len_ls + 1));
		if ((*map)[i] == NULL)
			return (free_map(*map, i), ERROR);
		++i;
	}
	(*map)[i] = NULL;
	return (0);
}

static int	get_line_split(int fd, char ***current_line)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (ERROR);
	*current_line = ft_split(line, ' ');
	free (line);
	if (*current_line == NULL)
		return (free(line), ERROR);
	return (0);
}

static int	fill_map(int ***map, int fd, int count_line)
{
	int		i;
	int		j;
	char	**line_cut;

	i = 0;
	while (i < count_line)
	{
		j = 0;
		if (get_line_split(fd, &line_cut) == ERROR)
			return (ERROR);
		while (line_cut[j] != NULL)
		{
			(*map)[i][j] = ft_atoi(line_cut[j]);
			j++;
		}
		free_tab(line_cut);
		i++;
	}
	close (fd);
	return (0);
}

t_map	*load_map(char *txt)
{
	t_map	*map;
	int		cl;
	int		len_ls;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	count_line_and_len(txt, &cl, &len_ls);
	if (init_map(&map->z, cl, len_ls) == ERROR)
		return (free(map), NULL);
	if (fill_map(&map->z, open(txt, O_RDONLY), cl) == ERROR)
		return (free(map), NULL);
	map->x = len_ls;
	map->y = cl;
	return (map);
}
