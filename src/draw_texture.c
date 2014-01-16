/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:50:42 by abrault           #+#    #+#             */
/*   Updated: 2014/01/16 10:58:19 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>
#include <stdio.h>

void	cpy_img(t_env *e, int x, int dist, t_img *img)
{
	t_point		p;
	int			i;
	int			y_img;

	p.x = x;
	p.y = H_WIN / 2 - (dist / 2);;
	e->data->col = 2 * (e->data->col) * img->bpp / 8;
	if (e->data->id == 0 || e->data->id > NB_TEXTURE)
		e->data->id++;
	while (p.y < H_WIN / 2 + (dist / 2))
	{
		i = 0;
		y_img = (p.y - (H_WIN / 2 - (dist / 2))) * SIZE_CASE / dist * 2 *
			img->size_line;
		p.blue = img->data[e->data->col + i++ + y_img];
		p.green = img->data[e->data->col + i++ + y_img];
		p.red = img->data[e->data->col + i++ + y_img];
		if (p.x >= 0 && p.x <= W_WIN && p.y >= 0 && p.y <=
				H_WIN && p.red != 0 &&
				p.green != 0 && p.blue != 0)
			mlx_pixel_put_to_image(e, &p);
		p.y++;
	}
}

void	cpy_all_img(t_env *e, t_img *img, int x, int y)
{
	t_point		p;
	int			pas_x;
	int			pas_y;
	int			i;

	p.y = y;
	while (p.y - y < img->height)
	{
		i = 0;
		p.x = x;
		pas_y = (p.y - y) * img->size_line;
		while (p.x - x < img->width)
		{
			pas_x = (p.x - x) / 4 * img->bpp / 8;
			p.blue = img->data[pas_x + i++ + pas_y];
			p.green = img->data[pas_x + i++ + pas_y];
			p.red = img->data[pas_x + i++ + pas_y];
			if (p.x >= 0 && p.x <= W_WIN && p.y >= 0 && p.y <=
					H_WIN && p.red != 0 && p.green != 255 && p.blue != 0)
			mlx_pixel_put_to_image(e, &p);
			p.x++;
		}
		p.y++;
	}
}

t_img	*load_texture(t_env *e, char *file)
{
	t_img		*img;

	img = malloc(sizeof(t_img));
	img = mlx_xpm_file_to_image(e->mlx, file, &(img->width), &(img->height));
	if (img == NULL)
		exit(0);
	img->data = mlx_get_data_addr(img, &(img->bpp), &(img->size_line),
			&(img->endian));
	return (img);
}
