/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:26:20 by abrault           #+#    #+#             */
/*   Updated: 2014/01/18 21:10:29 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

void	mlx_pixel_put_to_image_sec(t_env *e, t_point *draw)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = draw->x * e->data->img->bpp / 8;
	y = (draw->y + 340) * e->data->img->size_line;
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->blue);
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->green);
	e->data->img->data[x + i++ + y] = mlx_get_color_value(e->mlx, draw->red);
}

void	draw_gui(t_env *e)
{
	int		i;
	int		x;

	i = 0;
//	cpy_all_img(e, e->data->texture->id[11], 200, H_WIN - 100);
	while (i < 9)
	{
		x = 0;
		while (x < 64)
		{
			e->data->col = x;
//			cpy_block_i(e, 210 + i * 80 + x, 50, e->data->texture->
//					id[(int)e->data->inv[i]]);
			x++;
		}
		i++;
	}
//	cpy_all_img(e, e->data->texture->id[12], 195 + e->data->item_select * 80,
//			H_WIN - 105);
}
