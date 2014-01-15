/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 12:19:22 by abrault           #+#    #+#             */
/*   Updated: 2014/01/14 18:16:13 by abrault          ###   ########.fr       */
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
	if (!get_dim_map(file, e))
		exit(0);
	ini_map(e, file);
	e->data->dist_ecran = WIDTH_WINDOW / 2 / tan(ft_rad(FOV / 2));
	e->data->img->width = WIDTH_WINDOW;
	e->data->img->height = HEIGHT_WINDOW;
	e->data->img = mlx_new_image(e->mlx, WIDTH_WINDOW, HEIGHT_WINDOW);
	e->data->img->data = mlx_get_data_addr(
			e->data->img,
			&(e->data->img->bpp),
			&(e->data->img->size_line),
			&(e->data->img->endian));
	load_texture(e, "images/sandstone.xpm");
	return (0);
}

t_env	*ini_env(t_env *e)
{
	e = malloc(sizeof(t_env));
	e->data = malloc(sizeof(t_data));
	e->mlx = malloc(sizeof(t_xvar));
	e->win = malloc(sizeof(t_win_list));
	e->data->img = malloc(sizeof(t_img));
	e->data->texture = malloc(sizeof(t_texture));
	e->data->texture->mur = malloc(sizeof(t_img));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH_WINDOW, HEIGHT_WINDOW, "Wolf 3D");
	return (e);
}

int		get_dim_map(char *file, t_env *e)
{
	char	*line;
	char	*tok;
	int		fd;

	e->data->nbr_line = 0;
	if ((fd = open(file, O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &line))
		{
			e->data->nbr_col = 0;
			tok = ft_strtok(line, ' ');
			while (tok)
			{
				tok = ft_strtok(NULL, ' ');
				e->data->nbr_col++;
			}
			e->data->nbr_line++;
		}
		close(fd);
		return (1);
	}
	else
		write(1, "Incorrect file ...\n", 19);
	return (0);
}


int		ini_map(t_env *e, char *file)
{
	int		y;

	y = 0;
	e->data->map = malloc(sizeof(char*) * e->data->nbr_line);
	while (y < e->data->nbr_line)
	{
		e->data->map[y] = malloc(sizeof(char) * e->data->nbr_col);
		y++;
	}
	get_map(file, e);
	return (0);
}
