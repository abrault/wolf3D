/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 12:19:22 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 12:48:47 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

int		ini_data_and_img(t_env *e, char *file)
{
	e->data->pos_x = SIZE_CASE * 5;
	e->data->pos_y = SIZE_CASE * 5;
	e->data->rot = 90;
	e->data->red = 0;
	e->data->green = 0;
	e->data->blue = 0;
	e->data->nbr_col = 17;
	e->data->nbr_line = 10;
	e->data->dist_ecran = WIDTH_WINDOW / 2 / tan(rad(FOV / 2));
	e->data->map = get_map(file, e);
	e->data->img->width = WIDTH_WINDOW;
	e->data->img->height = HEIGHT_WINDOW;
	e->data->img = mlx_new_image(e->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	e->data->img->data = mlx_get_data_addr(
			e->data->img,
			&(e->data->img->bpp),
			&(e->data->img->size_line),
			&(e->data->img->endian));
	return (0);
}

t_env	*ini_env(t_env *e)
{
	e = malloc(sizeof(t_env));
	e->data = malloc(sizeof(t_data));
	e->mlx = malloc(sizeof(t_xvar));
	e->win = malloc(sizeof(t_win_list));
	e->data->img = malloc(sizeof(t_img));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH_WINDOW, HEIGHT_WINDOW, "Wolf 3D");
	return (e);
}
