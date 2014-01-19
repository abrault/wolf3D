/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 12:50:26 by abrault           #+#    #+#             */
/*   Updated: 2014/01/19 12:50:29 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

float		ft_rad(float degre)
{
	return (degre * PI / 180);
}

float		ft_abs(float nbr)
{
	return (nbr < 0 ? -nbr : nbr);
}
