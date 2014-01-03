/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_head.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:53:00 by abrault           #+#    #+#             */
/*   Updated: 2014/01/03 14:21:57 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_HEAD_H
# define WOLF_HEAD_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/Xatom.h>
#include <X11/keysym.h>

#include "libft/libft.h"

typedef struct s_data	t_data;
typedef struct s_player	t_player;

struct					s_data
{
	void	*mlx;
	void	*win;
};

struct					s_player
{
	int		x;
	int		y;
	int		z;
	int		rotation;
};

void	ligne(int xi,int yi,int xf,int yf, t_data *data, int color);

#endif
