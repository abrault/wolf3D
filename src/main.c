/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:52:17 by abrault           #+#    #+#             */
/*   Updated: 2014/01/19 18:25:12 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>
#include <stdio.h>

static float	get_intensity(t_env *e, t_point *draw)
{
	float	m;

	(void)e;
	if (draw->dist < MAX_DISTANCE)
		m = 0;
	else if (draw->dist > MIN_DISTANCE)
		m = 1;
	else
		m = ((float)draw->dist - MAX_DISTANCE) / (MIN_DISTANCE - MAX_DISTANCE);
	if (draw->dist > 0)
	{
		draw->red = draw->red * m;
		draw->green = draw->green * m;
		draw->blue = draw->blue * m;
	}
	return (m);
}

void			mlx_pixel_put_to_image(t_env *e, t_point *draw)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = draw->x * e->data->img->bpp / 8;
	y = draw->y * e->data->img->size_line;
	if (draw->red < 0)
		draw->red = 255 - ft_abs(draw->red);
	if (draw->green < 0)
		draw->green = 255 - ft_abs(draw->green);
	if (draw->blue < 0)
		draw->blue = 255 - ft_abs(draw->blue);
	if (e->data->map[0][0] == 1)
		get_intensity(e, draw);
	if (draw->red < 10 && draw->green > 240 && draw->blue < 10)
		return ;
	draw->red = draw->red * e->data->lum;
	draw->green = draw->green * e->data->lum;
	draw->blue = draw->blue * e->data->lum;
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->blue);
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->green);
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->red);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == MLX_KEY_ESC)
		exit(0);
	else if (keycode == MLX_KEY_LEFT)
		on_key_left(e);
	else if (keycode == MLX_KEY_RIGHT)
		on_key_right(e);
	else if (keycode == MLX_KEY_UP)
		on_key_up(e);
	else if (keycode == MLX_KEY_DOWN)
		on_key_down(e);
	else
		on_special_key(e, keycode);
	draw_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->data->img, 0, 0);
	return (0);
}

int				expose_hook(t_env *e)
{
	draw_image(e);
	draw_stage(e);
	mlx_put_image_to_window(e->mlx, e->win, e->data->img, 0, 0);
	return (0);
}

int				main(int ac, char **av)
{
	t_env	*e;

	e = NULL;
	if (ac != 2)
		write(1, "usage : ./wolf3D <map>\n", 23);
	else
	{
		e = ini_env(e);
		ini_data_and_img(e, av[1]);
		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, KeyPress, KeyRelease, &key_hook, e);
		mlx_loop(e->mlx);
	}
	return (0);
}
