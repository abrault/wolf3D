/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:52:17 by abrault           #+#    #+#             */
/*   Updated: 2014/01/06 02:08:42 by abrault          ###   ########.fr       */
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
		on_key_left();
	if (keycode == MLX_KEY_RIGHT)
		on_key_right();
	if (keycode == MLX_KEY_UP)
		on_key_up();
	if (keycode == MLX_KEY_DOWN)
		on_key_down();
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

int		ini_struct(char *file)
{
	g_data.list = NULL;
	g_data.pos_x = 0;
	g_data.pos_y = 0;
	g_data.rot = 90;
	g_data.map = get_map(file);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		write(1, "wolfd3D usage : ./wolf3D <map>\n", 31);
		return (0);
	}
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 800, 600, "Wolf 3D");
	ini_struct(av[1]);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, KeyPress, KeyRelease, &key_hook, 0);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
