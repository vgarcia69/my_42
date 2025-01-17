/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:52:25 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/02 13:46:30 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	trophee_rota(t_app *app)
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
			tmp1 = (app->points[i][j].win_x - app->refx) * cos(app->t_rota)
				+ app->points[i][j].z * sin(app->t_rota);
			tmp2 = -(app->points[i][j].win_x - app->refx) * sin(app->t_rota)
				+ app->points[i][j].z * cos(app->t_rota);
			app->points[i][j].win_x = tmp1 + app->refx;
			app->points[i][j].z = tmp2;
		}
	}
}

int	trophee_animation(t_app *app)
{
	if (app->on_off)
	{
		app->t_rota += 0.01;
		if (app->t_rota >= 0.314 / 1.23)
			app->t_rota = -0.314 / 1.23;
		reload_img(app);
		trophee_rota(app);
		usleep(100000);
	}
	return (0);
}
