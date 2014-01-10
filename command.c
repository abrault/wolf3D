/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:32:35 by abrault           #+#    #+#             */
/*   Updated: 2014/01/10 17:09:33 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"
#include <stdio.h>

int		on_key_up(t_env *e)
{
	e->data->pos_y--;
	return (0);
}

int		on_key_down(t_env *e)
{
	e->data->pos_y++;
	return (0);
}

int		on_key_left(t_env *e)
{
	e->data->rot += 2;
	if (e->data->rot == 360)
		e->data->rot = 0;
	return (0);
}

int		on_key_right(t_env *e)
{
	e->data->rot -= 2;
	if (e->data->rot == -2)
		e->data->rot = 358;
	return (0);
}
