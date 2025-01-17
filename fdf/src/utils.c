/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:11:02 by vgarcia           #+#    #+#             */
/*   Updated: 2024/12/23 16:52:07 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// send an error message and return ERROR
int	error(char *s)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	return (-1);
}

void	free_all_t_point(t_point **point, int ptr_nbr)
{
	int	i;

	i = -1;
	while (++i < ptr_nbr)
		free(point[i]);
	free(point);
}

void	free_map(int **z, int ptr_nbr)
{
	int	i;

	i = -1;
	while (++i < ptr_nbr)
		free(z[i]);
	free(z);
}

// checks the validity of the argument and opens the file
int	arg_check(char *txt)
{
	int	fd;
	int	i;

	if (!txt)
		return (error("no argument"));
	i = ft_strlen(txt);
	if (i < 4)
		return (error("wrong map name"));
	if (txt[i - 3] != 'f' || txt[i - 2] != 'd'
		|| txt[i - 1] != 'f' || txt[i - 4] != '.')
		return (error("wrong map terminator"));
	fd = open(txt, O_RDONLY);
	if (fd == ERROR)
		return (error("map does not exist"));
	close(fd);
	return (0);
}

// adds a pixel to the application's image at the specified coordinates
void	add_pixel(t_app *app, int x, int y)
{
	int	pixel_index;

	if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
	{
		pixel_index = (y * app->sl) + (x * (app->bpp / 8));
		*(unsigned int *)(app->data + pixel_index) = app->color;
	}
}
