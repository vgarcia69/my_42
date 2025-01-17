/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_managing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:18:11 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/03 11:20:52 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	fill_x(t_map *map, t_point ***points)
{
	float	interval;
	int		i;
	int		j;

	j = 0;
	i = 0;
	interval = WIN_Y / (map->y + 1);
	while (j < map->y)
	{
		(*points)[j][i].win_x = (i + 1) * interval;
		if (++i == map->x)
		{
			++j;
			i = 0;
		}
	}
}

static void	fill_y(t_map *map, t_point ***points)
{
	float	interval;
	int		i;
	int		j;

	j = 0;
	i = 0;
	interval = WIN_Y / (map->y + 1);
	while (i < map->x)
	{
		(*points)[j][i].win_y = (j + 1) * interval;
		if (++j == map->y)
		{
			++i;
			j = 0;
		}
	}
}

static void	fill_z(t_map *map, t_point ***points)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->y)
	{
		(*points)[j][i].z = map->z[j][i];
		if (++i == map->x)
		{
			++j;
			i = 0;
		}
	}
}

// fill points coordinates and apply map parameters
void	fill_points(t_app *app)
{
	fill_x(app->map, &app->points);
	fill_y(app->map, &app->points);
	fill_z(app->map, &app->points);
	rotate_points(app);
	iso_viewx(app);
	iso_viewy(app);
	apply_perspective(app);
	zoom(app);
}

// malloc all points
int	init_point(t_app *app)
{
	int	i;

	i = 0;
	app->points = malloc(sizeof(t_point *) * (app->map->y));
	if (app->points == NULL)
		return (ERROR);
	while (i < app->map->y)
	{
		app->points[i] = malloc(sizeof(t_point) * (app->map->x));
		if (app->points[i++] == NULL)
			return (free_all_t_point(app->points, i - 1), ERROR);
	}
	fill_points(app);
	return (0);
}
