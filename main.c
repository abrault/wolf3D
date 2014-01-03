/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:52:17 by abrault           #+#    #+#             */
/*   Updated: 2014/01/03 17:43:40 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MLX_KEY_ESC		65307
#define MLX_KEY_UP		65362
#define MLX_KEY_DOWN	65364
#define MLX_KEY_LEFT	65363
#define MLX_KEY_RIGHT	65361

#include "wolf_head.h"
#include <stdio.h>
#include <math.h>

t_player	g_player;
int		map[10][10] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 0, 0},
	{ 0, 0, 0, 1, 0, 0, 1, 0, 0},
	{ 0, 0, 0, 1, 0, 0, 1, 0, 0},
	{ 0, 0, 0, 1, 0, 0, 1, 0, 0},
	{ 0, 0, 0, 1, 0, 0, 1, 0, 0},
	{ 0, 0, 0, 1, 1, 0, 1, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int		key_hook(int keycode, t_data *data)
{
	mlx_pixel_put(data->mlx, data->win, 400, 300, 0xFF00FF);
	if (keycode == MLX_KEY_ESC)
		exit(0);
	else if (keycode == MLX_KEY_LEFT)
	{
		if (g_player.rotation == 0)
			g_player.rotation = 360;
		g_player.rotation = g_player.rotation - 5;
	}
	else if (keycode == MLX_KEY_RIGHT)
	{
		if (g_player.rotation == 360)
			g_player.rotation = 0;
		g_player.rotation = g_player.rotation + 5;
	}
	else if (keycode == MLX_KEY_UP)
		g_player.y = g_player.y + 1;
	else if (keycode == MLX_KEY_DOWN)
		g_player.y = g_player.y - 1;
	printf("Y: %d\n", g_player.y);
	return (0);
}

int		expose_hook(t_data *data)
{
	(void)data;
	return (0);
}

int		main(void)
{
	t_data		data;

	g_player.x = 50;
	g_player.y = 60;
	g_player.z = 2;
	g_player.rotation = 90;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 800, 600, "Wolf 3D");

	void	*img;
	char	*ptr_img;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;

	img = mlx_new_image(data.mlx, 16, 16);
	ptr_img = mlx_get_data_addr(img, &bpp, &size_l, &endian);
	img = mlx_xpm_file_to_image(data.mlx, "images/wood.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx, data.win, img, 15, 15);
	mlx_destroy_image(data.mlx, img);
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
