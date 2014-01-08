/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:26:27 by abrault           #+#    #+#             */
/*   Updated: 2014/01/08 17:38:26 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"

void	ligne(t_env *e, t_point *first, t_point *second)
{
	int		x;
	int		y;
	double	a;
	double	b;
	t_point	point;

	point.red = first->red;
	point.green = first->green;
	point.blue = first->blue;
	(void)e;
	a =(double)(second->y - first->y) / (second->x - first->x);
	b = first->y - a * first->x ;
	x = first->x;
	while (x <= second->x)
	{
		y = (int)(a * x + b);
		point.x = x;
		point.y = y;
		if (x >= 0 && x <= WIDTH_WINDOW)
			mlx_pixel_put_to_image(e, &point);
		x++;
	}
}

void		draw_background(t_env *e)
{
	t_point	point;

	point.y = 0;
	point.red = 90;
	point.green = 183;
	point.blue = 255;
	while (point.y < HEIGHT_WINDOW)
	{
		point.x = 0;
		while (point.x < WIDTH_WINDOW)
		{
			mlx_pixel_put_to_image(e, &point);
			point.x++;
		}
		point.y++;
		if (point.y == 300)
			point.blue = 0;
	}
}


void		draw_image(t_env *e)
{
	t_point		first;
	t_point		second;

	first.red = 255;
	first.green = 0;
	first.blue = 0;
	draw_background(e);
	first.y = 300 + (e->data->pos_y - 20) * 3;
	first.x = 400 - (e->data->pos_y - 50) * 20;
	second.x = 400 + (e->data->pos_y - 50) * 20;
	second.y = first.y;
	ligne(e, &first, &second);
	first.y = 300 - (e->data->pos_y - 20) * 3;
	second.y = first.y;
	ligne(e, &first, &second);
	second.x = 400 + (e->data->pos_y - 50) * 20;
	second.y = 300 + (e->data->pos_y - 20) * 3;
	ligne(e, &first, &second);
	first.y = 300 + (e->data->pos_y - 20) * 3;
	first.x = 400 - (e->data->pos_y - 50) * 20;
	second.x = 400 + (e->data->pos_y - 50) * 20;
	second.y = 300 - (e->data->pos_y - 20) * 3;
	ligne(e, &first, &second);
}
