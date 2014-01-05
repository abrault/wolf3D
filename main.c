/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:52:17 by abrault           #+#    #+#             */
/*   Updated: 2014/01/06 00:57:16 by abrault          ###   ########.fr       */
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

int		key_hook(int keycode, t_data *data)
{
	printf("Poke\n");
	if (keycode == MLX_KEY_ESC)
		exit(0);
	if (keycode == MLX_KEY_LEFT)
		on_key_left(data);
	if (keycode == MLX_KEY_RIGHT)
		on_key_right(data);
	if (keycode == MLX_KEY_UP)
		on_key_up(data);
	if (keycode == MLX_KEY_DOWN)
		on_key_down(data);
	printf("Stop\n");
	return (0);
}

int		expose_hook(t_data *data)
{
	(void)data;
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

t_data	*ini_struct(char *file)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 600, "Wolf 3D");
	data->list = NULL;
	data->pos_x = 5;
	data->pos_y = 5;
	data->rot = 90;
	data->map = get_map(file);
	return (data);
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		write(1, "wolfd3D usage : ./wolf3D <map>\n", 31);
		return (0);
	}
	data = ini_struct(av[1]);
	mlx_expose_hook(data->win, expose_hook, &data);
	mlx_hook(data->win, KeyPress, KeyRelease, &key_hook, 0);
	mlx_key_hook(data->win, key_hook, &data);
	mlx_loop(data->mlx);
	return (0);
}
