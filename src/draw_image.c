/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:26:27 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 17:48:23 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

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
		if (point.x >= 0 && point.x <= WIDTH_WINDOW
				&& point.y >= 0 && point.y <= HEIGHT_WINDOW)
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
	float	dist;

	angle = ft_rad(e->data->rot - FOV / 2 + (rayon * FOV / WIDTH_WINDOW));
	cosa = cos(angle);
	sina = sin(angle);
	angle = (e->data->rot - FOV / 2 + (rayon * e->data->fov / WIDTH_WINDOW));
	new_x = e->data->pos_x;
	new_y = e->data->pos_y;
	while (new_y <= (SIZE_CASE * e->data->nbr_line) && new_y >= 0 && new_x <=
			(SIZE_CASE * e->data->nbr_col) && new_x >= 0)
	{
			new_x += cosa / PRECISION;
			if (e->data->map[(int)(new_y / SIZE_CASE)]
							[(int)(new_x / SIZE_CASE)] == 1)
			{
				if (cosa > 0)
					e->data->direc = 2;
				else
					e->data->direc = 4;
			}
			else
			{
				if (sina > 0)
					e->data->direc = 6;
				else
					e->data->direc = 8;
			}
			new_y += sina / PRECISION;
			if (e->data->map[(int)(new_y / SIZE_CASE)]
							[(int)(new_x / SIZE_CASE)] == 1)
			{
				dist = sqrt((e->data->pos_x - new_x) * (e->data->pos_x - new_x)
						+ (e->data->pos_y - new_y) * (e->data->pos_y - new_y));
				return (dist);
			}
	}
	return (0);
}

void		draw_image(t_env *e)
{
	int		rayon;
	float	dist;

	rayon = 0;
	draw_background(e);
	e->data->dist_ecran = WIDTH_WINDOW / 2 / tan(ft_rad(30));
	while (rayon < WIDTH_WINDOW)
	{
		dist = find_dist(e, rayon);
		dist = SIZE_CASE / dist * e->data->dist_ecran;
		get_color(e, dist);
		if (dist != 0)
			horizontal(e, WIDTH_WINDOW - rayon - 1, HEIGHT_WINDOW / 2 -
					(dist / 2), HEIGHT_WINDOW / 2 + (dist / 2));
		rayon++;
	}
}
