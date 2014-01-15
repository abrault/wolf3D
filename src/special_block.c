/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 14:55:58 by abrault           #+#    #+#             */
/*   Updated: 2014/01/15 17:20:25 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>


int		use_lever(t_env *e, int id)
{
	int		y;
	int		x;

	y = (int)(e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->rot)));
	x = (int)(e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot)));
	if (id == 9)
	{
		e->data->map[y][x] = 10;
		if (e->data->map[y - 1][x] == 2)
			e->data->map[y - 1][x] = 3;
		if (e->data->map[y + 1][x] == 2)
			e->data->map[y + 1][x] = 3;
		if (e->data->map[y][x + 1] == 2)
			e->data->map[y][x + 1] = 3;
		if (e->data->map[y][x - 1] == 2)
			e->data->map[y][x - 1] = 3;
	}
	else
	{
		e->data->map[y][x] = 9;
		if (e->data->map[y - 1][x] == 3)
			e->data->map[y - 1][x] = 2;
		if (e->data->map[y + 1][x] == 3)
			e->data->map[y + 1][x] = 2;
		if (e->data->map[y][x + 1] == 3)
			e->data->map[y][x + 1] = 2;
		if (e->data->map[y][x - 1] == 3)
			e->data->map[y][x - 1] = 2;
	}
	return (0);
}
