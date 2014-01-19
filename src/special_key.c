/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 16:50:46 by abrault           #+#    #+#             */
/*   Updated: 2014/01/19 18:22:46 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

static void	teleport(t_env *e)
{
	e->data->pos_x += SIZE_CASE * 3;
	e->data->map[0][0] = 0;
}

static void	lever_action(t_env *e, int x, int y)
{
	e->data->map[y][x] = 12;
	y = 0;
	while (y < e->data->nbr_line)
	{
		if (e->data->map[y][x] == 5 && e->data->map[0][0] == 1)
			e->data->map[y][x] = 13;
		else if (e->data->map[y][x] == 5)
			e->data->map[y][x] = 14;
		y++;
	}
}

void		on_special_key(t_env *e, int keycode)
{
	int		y;
	int		x;

	x = e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot));
	y = e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->rot));
	if (keycode == MLX_KEY_SPACE)
	{
		if (e->data->map[y][x] == 11)
			lever_action(e, x, y);
		else if (e->data->map[y][x] == 13)
			teleport(e);
	}
}
