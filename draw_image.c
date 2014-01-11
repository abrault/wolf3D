/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:26:27 by abrault           #+#    #+#             */
/*   Updated: 2014/01/11 19:11:00 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"

#include <stdio.h>
#include <math.h>

void		horizontal(t_env *e, int x, int first_y, int second_y)
{
	t_point		point;

	point.red = e->data->red;
	point.green = e->data->green;
	point.blue = e->data->blue;
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
	float	new_x;
	float	new_y;
	float	angle;
	float	cosa;
	float	sina;

	angle = (e->data->rot - 30 + (rayon * 60 / WIDTH_WINDOW)) * 3.14159265359 / 180;
	cosa = cos(angle);
	sina = sin(angle);
	angle = (e->data->rot - 30 + (rayon * 60 / WIDTH_WINDOW));

	new_x = e->data->pos_x;
	new_y = e->data->pos_y;
	while (new_y <= 1088 && new_y >= 0 && new_x <= 1088 && new_x >= 0)
	{
			new_x += cosa / 10;
			new_y += sina / 10;
			if (e->data->map[(int)(new_y / 64)][(int)(new_x / 64)] == 1)
			{
				if (angle > 180)
				{
					if (new_y - sina > new_y && (int)((new_x - cosa) / 64) == (int)(new_x / 64))
					{
						e->data->red = 210;
						e->data->green = 210;
						e->data->blue = 210;
					}
					else
					{
						e->data->red = 240;
						e->data->green = 240;
						e->data->blue = 240;
					}
				}
				else
				{
					if (new_y - sina < new_y && (int)((new_x - cosa) / 64) == (int)(new_x / 64))
					{
						e->data->red = 210;
						e->data->green = 210;
						e->data->blue = 210;
					}
					else
					{
						e->data->red = 240;
						e->data->green = 240;
						e->data->blue = 240;
					}

				}
				return (sqrt((e->data->pos_x - new_x) * (e->data->pos_x - new_x)
						+ (e->data->pos_y - new_y) * (e->data->pos_y - new_y)));
			}
	}
	return (0);
}

void		draw_image(t_env *e)
{
	int		rayon;
	float	dist;
	int		dist_ecran;

	rayon = 0;
	draw_background(e);
	dist_ecran = WIDTH_WINDOW / 2 / tan(30 * 3.141592653 / 180);
	while (rayon < WIDTH_WINDOW)
	{
		dist = find_dist(e, rayon);
		dist = 64 / dist * dist_ecran;
		if (dist != 0)
			horizontal(e, WIDTH_WINDOW - rayon - 1, HEIGHT_WINDOW / 2 -
					(dist / 2), HEIGHT_WINDOW / 2 + (dist / 2));
		rayon++;
	}
}
