/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:26:27 by abrault           #+#    #+#             */
/*   Updated: 2014/01/09 23:56:00 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"

#include <stdio.h>
#include <math.h>

void		horizontal(t_env *e, int x, int first_y, int second_y)
{
	t_point		point;

	point.red = 255;
	point.green = 0;
	point.blue = 0;
	point.x = x;
	while (first_y < second_y)
	{
		point.y = first_y;
		if (point.x >= 0 && point.x <= WIDTH_WINDOW && point.y >= 0 && point.y <= HEIGHT_WINDOW)
			mlx_pixel_put_to_image(e, &point);
		first_y++;
	}
}

void		draw_background(t_env *e)
{
	t_point		point;

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
		if (point.y == HEIGHT_WINDOW / 2)
			point.blue = 0;
	}
}

int			find_dist(t_env *e, int rayon)
{
	int		x;
	int		y;
	int		angle;

	angle = e->data->rot - 30 + (rayon * 60 / WIDTH_WINDOW);
	x = cos(angle);
	y = sin(angle);
	return (sqrt((e->data->pos_x - x) * (e->data->pos_x - x) +(e->data->pos_y - y) * (e->data->pos_y - y)));
}

void		draw_image(t_env *e)
{
	int		rayon;
	int		dist;

	rayon = 0;
	//draw_background(e);
	while (rayon < WIDTH_WINDOW)
	{
		dist = find_dist(e, rayon);
		if (dist != 0)
		{
			horizontal(e, rayon, (HEIGHT_WINDOW / 2) - dist,
					(HEIGHT_WINDOW / 2) + dist);
			dist = 0;
		}
		rayon++;
	}
}
