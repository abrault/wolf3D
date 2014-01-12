/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:52:17 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 12:49:13 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

void	mlx_pixel_put_to_image(t_env *e, t_point *draw)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = draw->x * e->data->img->bpp / 8;
	y = draw->y * e->data->img->size_line;
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->blue);
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->green);
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->red);
}

int		key_hook(int keycode, t_env *e)
{
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
	draw_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->data->img, 0, 0);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->data->img, 0, 0);
	return (0);
}

char	**get_map(char *file, t_env *e)
{
	int		x;
	int		y;
	char	*line;
	char	*tok;
	int		fd;

	x = 0;
	y = 0;
	e->data->map = malloc(sizeof(char*) * 100);
	while (x < 100)
	{
		e->data->map[x] = malloc(sizeof(char) * 100);
		x++;
	}
	if ((fd = open(file, O_RDONLY)))
	{
		while (get_next_line(fd, &line))
		{
			x = 0;
			tok = ft_strtok(line, ' ');
			while (tok)
			{
				e->data->map[y][x] = ft_atoi(tok);
				tok = ft_strtok(NULL, ' ');
				x++;
			}
			y++;
		}
		close(fd);
		return (e->data->map);
	}
	else
	{
		write(1, "Incorrect file ...\n", 19);
		exit(0);
	}
	return (NULL);
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
		/*mlx_key_hook(e->win, key_hook, e);*/
		mlx_loop(e->mlx);
	}
	return (0);
}
