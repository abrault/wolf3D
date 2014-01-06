/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:32:35 by abrault           #+#    #+#             */
/*   Updated: 2014/01/06 02:15:46 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"
#include <stdio.h>

int		on_key_up()
{
	return (0);
}

int		on_key_down()
{
	return (0);
}

int		on_key_left()
{
	g_data.rot++;
	if (g_data.rot == 360)
		g_data.rot = 0;
	printf("Rot : %d\n", g_data.rot);
	return (0);
}

int		on_key_right()
{
	g_data.rot--;
	if (g_data.rot == -1)
		g_data.rot = 359;
	printf("Rot : %d\n", g_data.rot);
	return (0);
}
