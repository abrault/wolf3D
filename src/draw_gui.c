/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 11:26:20 by abrault           #+#    #+#             */
/*   Updated: 2014/01/19 13:39:23 by abrault          ###   ########.fr       */
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
	(void)e;
}
