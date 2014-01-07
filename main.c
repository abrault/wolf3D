/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:52:17 by abrault           #+#    #+#             */
/*   Updated: 2014/01/07 14:13:41 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MLX_KEY_ESC		65307
#define MLX_KEY_UP		65362
#define MLX_KEY_DOWN	65364
#define MLX_KEY_LEFT	65361
#define MLX_KEY_RIGHT	65363

#include "wolf_head.h"
#include <stdio.h>
#include <math.h>


int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == MLX_KEY_ESC)
		exit(0);
	if (keycode == MLX_KEY_LEFT)
		on_key_left(e);
	if (keycode == MLX_KEY_RIGHT)
		on_key_right(e);
	if (keycode == MLX_KEY_UP)
		on_key_up(e);
	if (keycode == MLX_KEY_DOWN)
		on_key_down(e);
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	return (0);
}

char	**get_map(char *file)
{
	char	**map;
	int		x;
	int		y;
	char	*line;
	char	*tok;
	int		fd;

	x = 0;
	y = 0;
	if ((fd = open(file, O_RDONLY)))
	{
		map = malloc(sizeof(char*) * 10);
		while (x < 10)
		{
			map[x] = malloc(sizeof(char) * 10);
			x++;
		}
		while (get_next_line(fd, &line))
		{
			x = 0;
			tok = ft_strtok(line, ' ');
			while (tok)
			{
				map[y][x] = ft_atoi(tok);
				tok = ft_strtok(NULL, ' ');
			}
			y++;
		}
		close(fd);
		return (map);
	}
	return (NULL);
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

int		ini_data_and_img(t_env *e, char *file)
{
	/* Init Data */
	e->data->pos_x = 0;
	e->data->pos_y = 0;
	e->data->rot = 90;
	e->data->map = get_map(file);
	/* Init image */
	e->data->img->width = WIDTH_WINDOW;
	e->data->img->height = HEIGHT_WINDOW;
	e->data->img->image = mlx_new_image(e->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	e->data->img->data = mlx_get_data_addr(
			e->data->img->image,
			&(e->data->img->bpp),
			&(e->data->img->size_line),
			&(e->data->img->endian));
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*e;

	e = NULL;
	if (ac != 2)
		write(1, "usage : ./wolf3D <map>\n", 31);
	else
	{
		e = ini_env(e);
		ini_data_and_img(e, av[1]);

		mlx_expose_hook(e->win, expose_hook, e);
		mlx_hook(e->win, KeyPress, KeyRelease, &key_hook, e);
		mlx_key_hook(e->win, key_hook, e);
		mlx_loop(e->mlx);
	}
	return (0);
}
