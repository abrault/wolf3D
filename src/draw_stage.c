/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:18:37 by abrault           #+#    #+#             */
/*   Updated: 2014/01/19 16:46:00 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

void	cpy_gui_img(t_env *e, t_img *img, int x, int y)
{
	t_point		p;
	int			pas_x;
	int			pas_y;
	int			i;

	p.y = y;
	while (p.y - y < img->height)
	{
		p.x = x;
		pas_y = (p.y - y) * img->size_line;
		while (p.x - x < img->width)
		{
			i = 0;
			pas_x = (p.x - x) * img->bpp / 8;
			p.blue = img->data[pas_x + i++ + pas_y];
			p.green = img->data[pas_x + i++ + pas_y];
			p.red = img->data[pas_x + i++ + pas_y];
			if (p.x >= 0 && p.x <= W_WIN && p.y >= 0 && p.y <= H_WIN)
			mlx_pixel_put_to_image(e, &p);
			p.x++;
		}
		p.y++;
	}
}

void		draw_stage(t_env *e)
{
	float		i;

	i = 0;
	while (i < 1)
	{
		e->data->lum = i;
		draw_image(e);
		e->data->lum = 1;
		cpy_gui_img(e, e->data->texture->id[10], 450, 400);
		mlx_put_image_to_window(e->mlx, e->win, e->data->img, 0, 0);
		usleep(1000);
		i += 0.1;
	}
	e->data->lum = 1;
	draw_image(e);
}
