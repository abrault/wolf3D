/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:32:35 by abrault           #+#    #+#             */
/*   Updated: 2014/01/06 23:26:20 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"
#include <stdio.h>

int		on_key_up(t_env *e)
{
	(void)e;
	return (0);
}

int		on_key_down(t_env *e)
{
	(void)e;
	return (0);
}

int		on_key_left(t_env *e)
{
	printf("%d", e->data->pos_x);
	return (0);
}

int		on_key_right(t_env *e)
{
	(void)e;
	return (0);
}