/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:23 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/23 16:54:15 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	hooks(t_app *app)
{
	mlx_hook(app->win, 2, 1L << 0, keyboard_act, app);
	mlx_hook(app->win, 3, 1L << 1, keyboard_release, app);
	mlx_hook(app->win, 17, 0L, close_programm, app);
	mlx_mouse_hook(app->win, mouse_act, app);
	return (0);
}

int	keyboard_release(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	app->key[keycode] = 0;
	return (0);
}

static int	keyboard_act2(int keycode, t_app *app)
{
	if (keycode == A)
		app->refx -= 10;
	else if (keycode == KEY_LEFT)
		app->isox += 0.05;
	else if (keycode == D)
		app->refx += 10;
	else if (keycode == KEY_RIGHT)
		app->isox -= 0.05;
	else if (keycode == W)
		app->refy -= 10;
	else if (keycode == S)
		app->refy += 10;
	else if (keycode == SPACE)
	{
		if (app->on_off)
			app->on_off = 0;
		else
			app->on_off = 1;
	}
	return (0);
}

int	keyboard_act(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == ESC)
		close_programm(app);
	else if (keycode == KEY_UP && app->key[CTRL] == 1)
		app->perspective += 1;
	else if (keycode == KEY_UP)
		app->isoy += 0.05;
	else if (keycode == KEY_DOWN && app->key[CTRL] == 1)
		app->perspective -= 1;
	else if (keycode == KEY_DOWN)
		app->isoy -= 0.05;
	else if (keycode == R)
		app->color = 0xFF0000;
	else if (keycode == G)
		app->color = 0x00FF00;
	else if (keycode == B)
		app->color = 0x0000FF;
	keyboard_act2(keycode, app);
	app->key[keycode] = 1;
	update_img(app);
	return (0);
}

int	mouse_act(int button, int x, int y, void *param)
{
	t_app	*app;

	(void)x;
	(void)y;
	app = (t_app *)param;
	if (button == 4 && app->key[CTRL] == 1)
		app->rotation += 0.1;
	else if (button == 4)
		app->zoom += 0.05;
	else if (button == 5 && app->key[CTRL] == 1)
		app->rotation -= 0.1;
	else if (button == 5)
		app->zoom -= 0.05;
	update_img(app);
	return (0);
}
