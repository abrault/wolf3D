/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 14:41:15 by abrault           #+#    #+#             */
/*   Updated: 2014/01/16 10:49:03 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

int			special_key(t_env *e, int keycode)
{
	int		id;

	id = e->data->map[(int)(e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->rot
			)))][(int)(e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot)))];
	if (keycode == MLX_KEY_SPACE)
	{
		if (id == 9 || id == 10)
			use_lever(e, id);
	}
	else if (keycode == MLX_KEY_PLACE_BLOCK)
		e->data->map[(int)(e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->rot
		)))][(int)(e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot)))] = 1;
	else if (keycode == MLX_KEY_DELETE_BLOCK)
		e->data->map[(int)(e->data->pos_y / SIZE_CASE + sin(ft_rad(e->data->rot
		)))][(int)(e->data->pos_x / SIZE_CASE + cos(ft_rad(e->data->rot)))] = 0;
	return (0);
}
