/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:50:42 by abrault           #+#    #+#             */
/*   Updated: 2014/01/14 21:25:36 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

void	cpy_img(t_env *e, int x, int first_y, int second_y)
{
	t_point		point;
	int			i;
	int			size;
	int			y_img;

	point.x = x;
	e->data->col = e->data->col * e->data->texture->mur->bpp / 8;
	size = second_y - first_y;
	point.y = first_y;
	while (point.y < second_y)
	{
		i = 0;
		y_img = (point.y - first_y) * SIZE_CASE / size * e->data->texture->mur->size_line;
		point.blue = e->data->texture->mur->data[e->data->col + i++ + y_img];
		point.green = e->data->texture->mur->data[e->data->col + i++ + y_img];
		point.red = e->data->texture->mur->data[e->data->col + i++ + y_img];
		if (point.x >= 0 && point.x <= WIDTH_WINDOW
				&& point.y >= 0 && point.y <= HEIGHT_WINDOW)
			mlx_pixel_put_to_image(e, &point);
		point.y++;
	}
}

void	load_texture(t_env *e, char *file)
{
	e->data->texture->mur = mlx_xpm_file_to_image(e->mlx, file,
			&(e->data->texture->mur->width),
			&(e->data->texture->mur->height));
	if (e->data->texture->mur == NULL)
		exit(0);
	e->data->texture->mur->data = mlx_get_data_addr(
			e->data->texture->mur,
			&(e->data->texture->mur->bpp),
			&(e->data->texture->mur->size_line),
			&(e->data->texture->mur->endian));
}
