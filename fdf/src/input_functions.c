/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:14:57 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/23 13:41:26 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_programm(t_app *app)
{
	close_window(app);
	free_all_t_point(app->points, app->map->y);
	free_map(app->map->z, app->map->y);
	free(app->map);
	exit(0);
	return (0);
}

int	close_window(t_app *app)
{
	mlx_destroy_image(app->mlx, app->img);
	mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	return (0);
}

t_app	*move_struct(t_app *app, float move)
{
	int	i;
	int	j;

	i = -1;
	while (++i < app->map->y)
	{
		j = -1;
		while (++j < app->map->x)
			app->points[i][j].win_x += move;
	}
	return (app);
}
