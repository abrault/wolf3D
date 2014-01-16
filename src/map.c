/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 13:05:00 by abrault           #+#    #+#             */
/*   Updated: 2014/01/16 10:47:02 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

int		get_map(char *file, t_env *e)
{
	int		x;
	int		y;
	char	*line;
	char	*tok;
	int		fd;

	y = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		x = 0;
		tok = ft_strtok(line, ' ');
		while (tok)
		{
			e->data->map[y][x] = ft_atoi(tok);
			tok = ft_strtok(NULL, ' ');
			x++;
		}
		y++;
	}
	return (0);
}
