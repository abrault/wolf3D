/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:15:50 by abrault           #+#    #+#             */
/*   Updated: 2013/11/29 10:23:23 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *desti, const char *source, size_t size)
{
	int 	i;
	int		lenght;

    if (desti == NULL || source == NULL || size == 0)
        return (desti);
	lenght = ft_strlen(source);
	i = 0;
	while (i < size && (desti[i] =! 0 && source[i] != 0))
	{
		desti[i] = source[i];
		i++;
	}
	return (desti);
}
