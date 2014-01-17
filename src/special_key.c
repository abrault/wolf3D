/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 14:41:15 by abrault           #+#    #+#             */
/*   Updated: 2014/01/17 17:41:02 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

int			special_key(t_env *e, int keycode)
{
	int		id;

	id = e->data->map[(int)(e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->
		rot)))][(int)(e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot)))];
	if (keycode == MLX_KEY_SPACE)
	{
		if (id == 9 || id == 10)
			use_lever(e, id);
	}
	else if (keycode == MLX_KEY_PLACE_BLOCK)
		e->data->map[(int)(e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->rot
		)))][(int)(e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot)))] =
			e->data->inv[e->data->item_select];
	else if (keycode == MLX_KEY_DELETE_BLOCK)
		e->data->map[(int)(e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->rot
		)))][(int)(e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot)))]
			= 0;
	else if (keycode == MLX_KEY_CUBE_LEFT)
		e->data->item_select = (e->data->item_select > 0) ?
			e->data->item_select - 1 : 8;
	else if (keycode == MLX_KEY_CUBE_RIGHT)
		e->data->item_select = (e->data->item_select < 8) ?
			e->data->item_select + 1 : 0;
	return (0);
}
