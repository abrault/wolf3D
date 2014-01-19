/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 13:05:00 by abrault           #+#    #+#             */
/*   Updated: 2014/01/19 12:48:24 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf_head.h>

static int	define_spawn(t_env *e, int x, int y)
{
	e->data->pos_x = x * SIZE_CASE;
	e->data->pos_y = y * SIZE_CASE;
	return (0);
}

int			get_map(char *file, t_env *e)
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
			if (tok[0] == 'S')
				define_spawn(e, x, y);
				e->data->map[y][x] = ft_atoi(tok);
			tok = ft_strtok(NULL, ' ');
			x++;
		}
		y++;
	}
	return (0);
}
