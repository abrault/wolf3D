/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:26:27 by abrault           #+#    #+#             */
/*   Updated: 2014/01/07 23:51:24 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"

void	ligne(t_env *e, t_point *first, t_point *second)
{
	int		x;
	int		y;
	double	a;
	double	b;

	a =(double)(second->y - first->y) / (second->x - first->x);
	b = first->y - a * first->x ;
	x = first->x;
	while (x <= second->x)
	{
		y = (int)(a * x + b);
		first->x = x;
		first->y = y;
		mlx_pixel_put_to_image(e, first);
		x++;
	}
}

void	draw_image(t_env *e)
{
	t_point		first;
	t_point		second;

	first.red = 255;
	first.green = 0;
	first.blue = 0;
	ligne(e, &first, &second);
}
