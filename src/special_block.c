/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 14:55:58 by abrault           #+#    #+#             */
/*   Updated: 2014/01/16 10:57:54 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

static	int	on_pumpkin(t_env *e, int x, int y)
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
	return (0);
}

static	int	off_pumpkin(t_env *e, int x, int y)
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
	return (0);
}

int			use_lever(t_env *e, int id)
{
	int		y;
	int		x;

	y = (int)(e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->rot)));
	x = (int)(e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot)));
	if (id == 9)
		on_pumpkin(e, x, y);
	else
		off_pumpkin(e, x, y);
	return (0);
}
