/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:21:42 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/23 19:23:19 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// add the Z variable to the projection
void	apply_perspective(t_app *app)
{
	int	i;
	int	j;

	i = -1;
	while (++i < app->map->y)
	{
		j = -1;
		while (++j < app->map->x)
			app->points[i][j].win_y = app->points[i][j].win_y
				- app->points[i][j].z * app->perspective;
	}
}

// rotating the original rectangle
void	rotate_points(t_app *app)
{
	int		i;
	int		j;
	float	tmp1;
	float	tmp2;

	i = -1;
	while (++i < app->map->y)
	{
		j = -1;
		while (++j < app->map->x)
		{
			tmp1 = app->refx + (app->points[i][j].win_x
					- app->refx) * cos(app->rotation)
				- (app->points[i][j].win_y - app->refy) * sin(app->rotation);
			tmp2 = app->refy + (app->points[i][j].win_x
					- app->refx) * sin(app->rotation)
				+ (app->points[i][j].win_y - app->refy) * cos(app->rotation);
			app->points[i][j].win_x = tmp1;
			app->points[i][j].win_y = tmp2;
		}
	}
}

// zoom function only on Y point
void	iso_viewy(t_app *app)
{
	int		i;
	int		j;

	if (app->isoy >= 3 || app->isoy <= -3)
		app->isoy = 0.75;
	i = -1;
	while (++i < app->map->y)
	{
		j = -1;
		while (++j < app->map->x)
		{
			app->points[i][j].win_y = app->refy
				+ (app->points[i][j].win_y - app->refy) * app->isoy;
		}
	}
}

// zoom function only on X points
void	iso_viewx(t_app *app)
{
	int	i;
	int	j;

	if (app->isox >= 3 || app->isox <= -3)
		app->isox = 0.75;
	i = -1;
	while (++i < app->map->y)
	{
		j = -1;
		while (++j < app->map->x)
			app->points[i][j].win_x = app->refx
				+ (app->points[i][j].win_x - app->refx) * app->isox;
	}
}

// zoom all points from the window's center
void	zoom(t_app *app)
{
	int	i;
	int	j;

	i = -1;
	while (++i < app->map->y)
	{
		j = -1;
		while (++j < app->map->x)
		{
			app->points[i][j].win_y = app->refy
				+ (app->points[i][j].win_y - app->refy) * app->zoom;
			app->points[i][j].win_x = app->refx
				+ (app->points[i][j].win_x - app->refx) * app->zoom;
		}
	}
}
