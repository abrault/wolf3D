/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:32:35 by abrault           #+#    #+#             */
/*   Updated: 2014/01/16 10:27:44 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

int		on_key_up(t_env *e)
{
	if (e->data->map[(int)((e->data->pos_y +
				sin(ft_rad(e->data->rot)) * (VITESSE + 7)) / SIZE_CASE)]
					[(int)((e->data->pos_x +
				cos(ft_rad(e->data->rot)) * (VITESSE + 7)) / SIZE_CASE)] == 0)
	{
		e->data->pos_y += sin(ft_rad(e->data->rot)) * VITESSE;
		e->data->pos_x += cos(ft_rad(e->data->rot)) * VITESSE;
	}
	return (0);
}

int		on_key_down(t_env *e)
{
	if (e->data->map[(int)((e->data->pos_y -
				sin(ft_rad(e->data->rot)) * (VITESSE + 5)) / SIZE_CASE)]
					[(int)((e->data->pos_x -
				cos(ft_rad(e->data->rot)) * (VITESSE + 5)) / SIZE_CASE)] == 0)
	{
		e->data->pos_y -= sin(ft_rad(e->data->rot)) * VITESSE;
		e->data->pos_x -= cos(ft_rad(e->data->rot)) * VITESSE;
	}
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
