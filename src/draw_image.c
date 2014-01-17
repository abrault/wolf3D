/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:26:27 by abrault           #+#    #+#             */
/*   Updated: 2014/01/17 17:38:32 by abrault          ###   ########.fr       */
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
	horizontal(e, rayon, 0, dist + 1);
	e->data->blue = 0;
	horizontal(e, rayon, H_WIN - dist - 1, H_WIN);
}

static int	find_dist_work(t_env *e, t_tempvar *temp)
{
	if (e->data->map[(int)((temp->new_y - temp->sina) / SIZE_CASE)]
					[(int)(temp->new_x / SIZE_CASE)] != 0)
	{
		e->data->col = (int)temp->new_y % SIZE_CASE;
		e->data->direc = (temp->cosa > 0) ? 6 : 4;
	}
	else
	{
		e->data->col = (int)temp->new_x % SIZE_CASE;
		e->data->direc = (temp->sina > 0) ? 8 : 2;
	}
	e->data->id = e->data->map[(int)((temp->new_y) / SIZE_CASE)]
								[(int)(temp->new_x / SIZE_CASE)];
	return (0);
}

int			find_dist(t_env *e, int rayon)
{
	t_tempvar	temp;

	temp.angle = ft_rad(e->data->rot - FOV / 2 + (rayon * 0.9 * FOV / W_WIN));
	temp.cosa = cos(temp.angle) / PRECISION;
	temp.sina = sin(temp.angle) / PRECISION;
	temp.new_x = e->data->pos_x;
	temp.new_y = e->data->pos_y;
	while (temp.new_y >= 0 && temp.new_y <= (SIZE_CASE * e->data->nbr_line) &&
			temp.new_x <= (SIZE_CASE * e->data->nbr_col) && temp.new_x >= 0)
	{
		if (e->data->map[(int)(temp.new_y / SIZE_CASE)]
						[(int)(temp.new_x / SIZE_CASE)] != 0)
		{
			find_dist_work(e, &temp);
			return (sqrt((e->data->pos_x - temp.new_x) * (e->data->pos_x -
			temp.new_x) + (e->data->pos_y - temp.new_y) * (e->data->pos_y -
			temp.new_y)) * cos(temp.angle - ft_rad(e->data->rot)));
		}
		temp.new_x += temp.cosa;
		temp.new_y += temp.sina;
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
		get_color(e);
		if (dist != 0)
		{
			/*horizontal(e, rayon, H_WIN / 2 - dist / 2, H_WIN / 2 + dist / 2);
			*/cpy_img(e, rayon, dist, e->data->texture->id[e->data->id]);
			draw_background(e, dist, rayon);
		}
		rayon++;
	}
	draw_gui(e);
}
