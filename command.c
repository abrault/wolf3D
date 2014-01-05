/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:32:35 by abrault           #+#    #+#             */
/*   Updated: 2014/01/06 00:56:30 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"
#include <stdio.h>

int		on_key_up(t_data *data)
{
	data->pos_x = data->pos_x + 1;
	printf("X : %d\n", data->pos_x);
	return (0);
}

int		on_key_down(t_data *data)
{
	(void)data;
	return (0);
}

int		on_key_left(t_data *data)
{
	(void)data;
	return (0);
}

int		on_key_right(t_data *data)
{
	(void)data;
	return (0);
}
