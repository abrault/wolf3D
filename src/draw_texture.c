/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:50:42 by abrault           #+#    #+#             */
/*   Updated: 2014/01/16 07:03:00 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>
#include <stdio.h>

void	cpy_img(t_env *e, int x, int first_y, int second_y)
{
	t_point		point;
	int			i;
	int			size;
	int			y_img;

	if (e->data->id == 0 || e->data->id > NB_TEXTURE)
		e->data->id++;
	point.x = x;
	e->data->col = 2 * (e->data->col) * e->data->texture->
		id[e->data->id]->bpp / 8;
	size = second_y - first_y;
	point.y = first_y;
	while (point.y < second_y)
	{
		i = 0;
		y_img = (point.y - first_y) * SIZE_CASE / size * 2
			* e->data->texture->id[e->data->id]->size_line;
		point.blue = e->data->texture->id[e->data->id]->
			data[e->data->col + i++ + y_img];
		point.green = e->data->texture->id[e->data->id]->
			data[e->data->col + i++ + y_img];
		point.red = e->data->texture->id[e->data->id]->data
			[e->data->col + i++ + y_img];
		if (point.x >= 0 && point.x <= W_WIN
				&& point.y >= 0 && point.y <= H_WIN && point.red != 0 &&
				point.green != 0 && point.blue != 0)
			mlx_pixel_put_to_image(e, &point);
		point.y++;
	}
}

void	cpy_all_img(t_env *e, t_img *img, int x, int y)
{
	t_point		point;
	int			pas_x;
	int			pas_y;
	int			i;

	point.y = y;
	while (point.y - y < img->height)
	{
		i = 0;
		point.x = x;
		pas_y = (point.y - y) * img->size_line;
		while (point.x - x < img->width)
		{
			pas_x = (point.x - x) / 4 * img->bpp / 8;
			point.blue = img->data[pas_x + i++ + pas_y];
			point.green = img->data[pas_x + i++ + pas_y];
			point.red = img->data[pas_x + i++ + pas_y];
			if (point.x >= 0 && point.x <= W_WIN
				&& point.y >= 0 && point.y <= H_WIN && point.red != 0
				&& point.green != 255 && point.blue != 0)
			mlx_pixel_put_to_image(e, &point);
			point.x++;
		}
		point.y++;
	}
}

t_img	*load_texture(t_env *e, char *file)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img = mlx_xpm_file_to_image(e->mlx, file,
			&(img->width),
			&(img->height));
	if (img == NULL)
		exit(0);
	img->data = mlx_get_data_addr(
			img,
			&(img->bpp),
			&(img->size_line),
			&(img->endian));
	return (img);
}
