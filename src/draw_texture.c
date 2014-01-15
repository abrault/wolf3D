/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:50:42 by abrault           #+#    #+#             */
/*   Updated: 2014/01/15 11:33:08 by abrault          ###   ########.fr       */
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

	if (e->data->id == 0)
		e->data->id++;
	point.x = x;
	e->data->col = 2 * e->data->col * e->data->texture->id[e->data->id]->bpp / 8;
	size = second_y - first_y;
	point.y = first_y;
	while (point.y < second_y)
	{
		i = 0;
		y_img = (point.y - first_y) * SIZE_CASE / size * 2
			* e->data->texture->id[e->data->id]->size_line;
		point.blue = e->data->texture->id[e->data->id]->data[e->data->col + i++ + y_img];
		point.green = e->data->texture->id[e->data->id]->data[e->data->col + i++ + y_img];
		point.red = e->data->texture->id[e->data->id]->data[e->data->col + i++ + y_img];
		if (point.x >= 0 && point.x <= WIDTH_WINDOW
				&& point.y >= 0 && point.y <= HEIGHT_WINDOW)
			mlx_pixel_put_to_image(e, &point);
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
