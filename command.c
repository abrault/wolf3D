/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:32:35 by abrault           #+#    #+#             */
/*   Updated: 2014/01/11 17:36:25 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"

#include <math.h>

int		on_key_up(t_env *e)
{
	e->data->pos_y += sin(e->data->rot * 3.14159265359 / 180) * 8;
	e->data->pos_x += cos(e->data->rot * 3.14159265359 / 180) * 8;
	return (0);
}

int		on_key_down(t_env *e)
{
	e->data->pos_y -= sin(e->data->rot * 3.14159265359 / 180) * 8;
	e->data->pos_x -= cos(e->data->rot * 3.14159265359 / 180) * 8;
	return (0);
}

int		on_key_left(t_env *e)
{
	e->data->rot += 5;
	if (e->data->rot == 360)
		e->data->rot = 0;
	return (0);
}

int		on_key_right(t_env *e)
{
	e->data->rot -= 5;
	if (e->data->rot == -5)
		e->data->rot = 355;
	return (0);
}
