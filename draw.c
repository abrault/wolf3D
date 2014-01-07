/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 02:19:03 by abrault           #+#    #+#             */
/*   Updated: 2014/01/06 02:25:46 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"

void	ligne(int xi,int yi,int xf, int yf, t_env *e, int color)
{
	(void)color;
	(void)e;
	int		x;
	int		y;
	double	a;
	double	b;

	a = (double)(yf - yi) / (xf - xi);
	b = yi - a * xi ;
	x = xi;
	while (x <= xf)
	{
		y = (int)(a * x + b) ;
		//allume_pixel(x,y);
		x++;
	}
}
