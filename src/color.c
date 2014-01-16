/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 17:37:21 by abrault           #+#    #+#             */
/*   Updated: 2014/01/16 10:26:18 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

void	get_color(t_env *e)
{
	e->data->red = 0;
	e->data->green = 0;
	e->data->blue = 0;
	if (e->data->direc == 2)
		e->data->red = 255;
	else if (e->data->direc == 4)
	{
		e->data->red = 255;
		e->data->green = 255;
	}
	else if (e->data->direc == 8)
		e->data->green = 255;
	else if (e->data->direc == 6)
		e->data->blue = 255;
}
