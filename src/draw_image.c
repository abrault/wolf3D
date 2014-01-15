/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:26:27 by abrault           #+#    #+#             */
/*   Updated: 2014/01/15 17:38:29 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>
#include <stdio.h>

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
		if (point.x >= 0 && point.x <= W_WIN
				&& point.y >= 0 && point.y <= H_WIN)
			mlx_pixel_put_to_image(e, &point);
		first_y++;
	}
}

void		draw_background(t_env *e, float dist, int rayon)
{
	e->data->red = 90;
	e->data->green = 183;
	e->data->blue = 255;
	dist = (H_WIN - dist) / 2;
	horizontal(e, rayon - 1, 0, dist);
	e->data->blue = 0;
	horizontal(e, rayon - 1, H_WIN - dist, H_WIN);
}

int			find_dist(t_env *e, int rayon)
{
	float		new_x;
	float		new_y;
	float		angle;
	float		cosa;
	float		sina;

	angle = ft_rad(e->data->rot - FOV / 2 + (rayon * 0.9 * FOV / W_WIN));
	cosa = cos(angle) / PRECISION;
	sina = sin(angle) / PRECISION;
	new_x = e->data->pos_x;
	new_y = e->data->pos_y;
	while (new_y <= (SIZE_CASE * e->data->nbr_line) && new_y >= 0 && new_x <=
			(SIZE_CASE * e->data->nbr_col) && new_x >= 0)
	{
		new_x += cosa;
		new_y += sina;
		if (e->data->map[(int)(new_y / SIZE_CASE)]
				[(int)(new_x / SIZE_CASE)] != 0)
		{
			if (e->data->map[(int)((new_y - sina) / SIZE_CASE)]
							[(int)(new_x / SIZE_CASE)] != 0)
			{
				e->data->col = (int)new_y % SIZE_CASE;
				e->data->direc = (cosa > 0) ? 6 : 4;
			}
			else
			{
				e->data->col = (int)new_x % SIZE_CASE;
				e->data->direc = (sina > 0) ? 8 : 2;
			}
			e->data->id = e->data->map[(int)((new_y) / SIZE_CASE)]
				[(int)(new_x / SIZE_CASE)];
			return (sqrt((e->data->pos_x - new_x) * (e->data->pos_x - new_x) +
				(e->data->pos_y - new_y) * (e->data->pos_y - new_y)) * cos(angle
				- ft_rad(e->data->rot)));
			}
	}
	e->data->id = 0;
	return (0);
}

void		draw_image(t_env *e)
{
	int		rayon;
	float	dist;

	rayon = 0;
	while (rayon < W_WIN)
	{
		dist = find_dist(e, rayon);
		dist = SIZE_CASE / dist * e->data->dist_ecran;
		get_color(e, dist);
		if (dist != 0)
		{
			cpy_img(e, rayon, H_WIN / 2 - (dist / 2), H_WIN / 2 + (dist / 2));
			draw_background(e, dist, rayon);
		}
		rayon++;
	}
	cpy_all_img(e, e->data->texture->id[11], 0, 0);
}
