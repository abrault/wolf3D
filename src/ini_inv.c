/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_inv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 16:12:55 by abrault           #+#    #+#             */
/*   Updated: 2014/01/17 16:21:13 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

int		ini_inv(t_env *e)
{
	e->data->inv = malloc(sizeof(char) * 9);
	e->data->inv[0] = 1;
	e->data->inv[1] = 2;
	e->data->inv[2] = 3;
	e->data->inv[3] = 4;
	e->data->inv[4] = 5;
	e->data->inv[5] = 6;
	e->data->inv[6] = 7;
	e->data->inv[7] = 8;
	e->data->inv[8] = 10;
	return (0);
}
