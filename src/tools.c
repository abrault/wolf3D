/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 17:02:37 by abrault           #+#    #+#             */
/*   Updated: 2014/01/16 10:49:35 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

float	ft_rad(float degre)
{
	return (degre * PI / 180);
}

float	ft_abs(float nbr)
{
	int		stock;

	stock = nbr;
	return ((nbr * nbr) / stock);
}
