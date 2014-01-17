/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 12:19:22 by abrault           #+#    #+#             */
/*   Updated: 2014/01/17 17:41:23 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

int		ini_data_and_img(t_env *e, char *file)
{
	e->data->pos_x = SIZE_CASE * 2;
	e->data->pos_y = SIZE_CASE * 2;
	e->data->rot = 90;
	e->data->red = 0;
	e->data->green = 0;
	e->data->blue = 0;
	e->data->item_select = 7;
	if (!get_dim_map(file, e))
	{
		write(1, "Incorrect file ...\n", 19);
		exit(0);
	}
	ini_map(e, file);
	e->data->dist_ecran = W_WIN / 2 / tan(ft_rad(FOV / 2));
	e->data->img = mlx_new_image(e->mlx, W_WIN, H_WIN);
	e->data->img->data = mlx_get_data_addr(e->data->img, &(e->data->img->bpp),
			&(e->data->img->size_line), &(e->data->img->endian));
	ini_texture(e);
	ini_inv(e);
	return (0);
}

void	ini_texture(t_env *e)
{
	e->data->texture->id[1] = load_texture(e, "images/stonebrick.xpm");
	e->data->texture->id[2] = load_texture(e, "images/pumpkinfaceoff.xpm");
	e->data->texture->id[3] = load_texture(e, "images/pumpkinfaceon.xpm");
	e->data->texture->id[4] = load_texture(e, "images/redstonelampe.xpm");
	e->data->texture->id[5] = load_texture(e, "images/wood.xpm");
	e->data->texture->id[6] = load_texture(e, "images/sandstone.xpm");
	e->data->texture->id[7] = load_texture(e, "images/stoneslab.xpm");
	e->data->texture->id[8] = load_texture(e, "images/stonebrickmossy.xpm");
	e->data->texture->id[9] = load_texture(e, "images/leveractif.xpm");
	e->data->texture->id[10] = load_texture(e, "images/leverinactif.xpm");
	e->data->texture->id[11] = load_texture(e, "images/barre.xpm");
	e->data->texture->id[12] = load_texture(e, "images/select.xpm");
}

t_env	*ini_env(t_env *e)
{
	int		y;

	y = -1;
	e = malloc(sizeof(t_env));
	e->data = malloc(sizeof(t_data));
	e->mlx = malloc(sizeof(t_xvar));
	e->win = malloc(sizeof(t_win_list));
	e->data->img = malloc(sizeof(t_img));
	e->data->texture = malloc(sizeof(t_texture));
	e->data->texture->id = malloc(sizeof(t_img*) * NB_TEXTURE);
	while (y++ && y < NB_TEXTURE)
		e->data->texture->id[y] = malloc(sizeof(t_img));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W_WIN, H_WIN, "Wolf 3D");
	return (e);
}

int		get_dim_map(char *file, t_env *e)
{
	char	*line;
	char	*tok;
	int		fd;
	int		i;

	i = 0;
	e->data->nbr_line = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		e->data->nbr_col = 0;
		tok = ft_strtok(line, ' ');
		while (tok)
		{
			tok = ft_strtok(NULL, ' ');
			i++;
		}
		e->data->nbr_col = (i > e->data->nbr_col) ? i : e->data->nbr_col;
		e->data->nbr_line++;
	}
	close(fd);
	return (1);
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
