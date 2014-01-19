/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:50:42 by abrault           #+#    #+#             */
/*   Updated: 2014/01/19 15:29:45 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

void	cpy_img(t_env *e, int x, int dist, t_img *img)
{
	t_point		p;
	int			i;
	int			y_img;

	p.x = x;
	p.dist = dist;
	p.y = H_WIN / 2 - (dist / 2);
	e->data->col = (e->data->col) * img->bpp / 8;
	if (e->data->id == 0 || e->data->id > NB_TEXTURE)
		e->data->id++;
	while (p.y < H_WIN / 2 + (dist / 2))
	{
		i = 0;
		y_img = (p.y - (H_WIN / 2 - (dist / 2))) * SIZE_CASE / dist *
			img->size_line;
		p.blue = img->data[e->data->col + i++ + y_img];
		p.green = img->data[e->data->col + i++ + y_img];
		p.red = img->data[e->data->col + i++ + y_img];
		if (p.x >= 0 && p.x <= W_WIN && p.y >= 0 && p.y <= H_WIN)
			mlx_pixel_put_to_image(e, &p);
		p.y++;
	}
}

void	cpy_sky(t_env *e, int x, int dist, t_img *img)
{
	t_point		p;
	int			i;
	int			y_img;

	p.x = x;
	p.dist = dist;
	p.y = 0;
	x = x * img->bpp / 8;
	if (e->data->id == 0 || e->data->id > NB_TEXTURE)
		e->data->id++;
	p.dist = 400;
	while (p.y < dist)
	{
		i = 0;
		y_img = p.y * img->size_line;
		p.blue = img->data[x + i++ + y_img];
		p.green = img->data[x + i++ + y_img];
		p.red = img->data[x + i++ + y_img];
		if (p.x >= 0 && p.x <= W_WIN && p.y >= 0 && p.y <= H_WIN)
			mlx_pixel_put_to_image(e, &p);
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
