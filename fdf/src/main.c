/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:34:28 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/03 11:22:29 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	game(t_app *app, char *txt)
{
	app->map = load_map(txt);
	if (app->map == NULL)
		return (ERROR);
	if (init_point(app) == ERROR)
		return (free_map(app->map->z, app->map->y), free(app->map), ERROR);
	update_img(app);
	hooks(app);
	mlx_loop_hook(app->mlx, trophee_animation, app);
	mlx_loop(app->mlx);
	return (0);
}

static void	init2(t_app *app)
{
	app->perspective = 10;
	app->zoom = 0.5;
	app->rotation = 0.7;
	app->isoy = 0.75;
	app->isox = 1;
	app->refx = WIN_X / 2;
	app->refy = WIN_Y / 2;
	app->t_rota = 1;
	app->on_off = 0;
	app->color = 0xFFFFFF;
}

static int	init1(t_app *app)
{
	int		i;

	i = -1;
	while (i++ <= CTRL)
		app->key[i] = 0;
	app->mlx = mlx_init();
	if (app->mlx == NULL)
		return (ERROR);
	app->win = mlx_new_window(app->mlx, WIN_X, WIN_Y, "fdf");
	if (app->win == NULL)
		return (mlx_destroy_display(app->mlx), free(app->mlx), ERROR);
	app->img = mlx_new_image(app->mlx, WIN_X, WIN_Y);
	if (app->img == NULL)
		return (mlx_destroy_window(app->mlx, app->win),
			mlx_destroy_display(app->mlx), free(app->mlx), ERROR);
	app->data = mlx_get_data_addr(app->img, &app->bpp, &app->sl, &app->endian);
	init2(app);
	return (0);
}

int	main(int ac, char **av)
{
	t_app	app;

	(void)ac;
	if (arg_check(av[1]) == ERROR)
		return (ERROR);
	if (init1(&app) == ERROR)
		return (error("initialisation failed"));
	if (game(&app, av[1]) == ERROR)
		return (close_window(&app), error("map loading failed"));
	return (0);
}
