/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:15:30 by v                 #+#    #+#             */
/*   Updated: 2024/12/23 15:36:18 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// reload the image without updating the map parameters
int	reload_img(t_app *app)
{
	mlx_destroy_image(app->mlx, app->img);
	app->img = mlx_new_image(app->mlx, WIN_X, WIN_Y);
	print_map(app, app->points, app->map);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	return (0);
}

// reload the image and update the map parameters
int	update_img(t_app *app)
{
	clear(app);
	fill_points(app);
	print_map(app, app->points, app->map);
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	return (0);
}

// clear the window / image
int	clear(t_app *app)
{
	mlx_destroy_image(app->mlx, app->img);
	mlx_clear_window(app->mlx, app->win);
	app->img = mlx_new_image(app->mlx, WIN_X, WIN_Y);
	app->data = mlx_get_data_addr(app->img, &app->bpp, &app->sl, &app->endian);
	return (0);
}

int	print_line(t_app *app, t_point p1, t_point p2)
{
	double	dx;
	double	dy;
	float	len;

	dx = p2.win_x - p1.win_x;
	dy = p2.win_y - p1.win_y;
	len = sqrtf(dx * dx + dy * dy);
	dx /= len;
	dy /= len;
	while (len > 0)
	{
		add_pixel(app, p1.win_x += dx, p1.win_y += dy);
		len--;
	}
	return (0);
}

int	print_map(t_app *app, t_point **points, t_map *map)
{
	int	i;
	int	j;

	j = -1;
	if (map->x == 1 && map-> y == 1)
		add_pixel(app, points[0][0].win_x, points[0][0].win_y);
	while (++j < map->y)
	{
		i = -1;
		while (++i < map->x - 1)
			print_line(app, points[j][i], points[j][i + 1]);
	}
	j = -1;
	while (++j < map->y - 1)
	{
		i = -1;
		while (++i < map->x)
			print_line(app, points[j][i], points[j + 1][i]);
	}
	return (0);
}
