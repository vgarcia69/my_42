/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:59:31 by v                 #+#    #+#             */
/*   Updated: 2024/12/23 16:54:07 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
https://cdn.intra.42.fr/pdf/pdf/135907/fr.subject.pdf
*/

# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>

# define ERROR -1
# define WIN_X 1920
# define WIN_Y 1200

# define ESC 65307
# define CTRL 65507
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define SPACE 32
# define W 119
# define D 100
# define A 97
# define S 115
# define R 114
# define G 103
# define B 98

typedef struct s_point
{
	float	z;
	float	win_x;
	float	win_y;
	int		color;
}	t_point;

typedef struct s_map
{
	int	**z;
	int	x;
	int	y;
}	t_map;

typedef struct s_app
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		endian;
	int		sl;
	float	perspective;
	float	zoom;
	float	rotation;
	int		on_off;
	float	t_rota;
	float	isoy;
	float	isox;
	int		key[65508];
	float	refx;
	float	refy;
	int		color;
	t_point	**points;
	t_map	*map;
}	t_app;

void	free_all_t_point(t_point **point, int ptr_nbr);
int		error(char *s);
void	free_map(int **z, int ptr_nbr);
void	add_pixel(t_app *app, int x, int y);
int		print_line(t_app *app, t_point p1, t_point p2);
int		init_point(t_app *app);
void	fill_points(t_app *app);
int		print_map(t_app *app, t_point **points, t_map *map);
int		clear(t_app *app);
int		update_img(t_app *app);
void	apply_perspective(t_app *app);
void	rotate_points(t_app *app);
void	zoom(t_app *app);
void	iso_viewy(t_app *app);
void	iso_viewx(t_app *app);
int		hooks(t_app *app);
int		keyboard_release(int keycode, void *param);
int		keyboard_act(int keycode, void *param);
int		mouse_act(int button, int x, int y, void *param);
int		close_programm(t_app *app);
int		close_window(t_app *app);
t_app	*move_struct(t_app *app, float move);
int		arg_check(char *txt);
int		count_word(const char *s, char c);
void	count_line_and_len(char *txt, int *count, int *len_ls);
t_map	*load_map(char *txt);
int		trophee_animation(t_app *app);
int		reload_img(t_app *app);

#endif
