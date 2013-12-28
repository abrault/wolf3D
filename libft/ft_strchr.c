/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:11:26 by abrault           #+#    #+#             */
/*   Updated: 2013/11/29 11:36:39 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char    *ft_strchr(const char *str, int c_ascii)
{
    if (str == NULL)
        return (NULL);
	char	n;
    int     i;

    i = 0;
	n = c_ascii;
    while (str[i] != '\0')
	{
		if (str[i] == n)
			return ((char*) str + i);
        i++;
    }
	if (c_ascii == 0)
		return ((char *) str + i);
    return (NULL);
}
