/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_head.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:53:00 by abrault           #+#    #+#             */
/*   Updated: 2014/01/06 02:03:46 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_HEAD_H
# define WOLF_HEAD_H

/*************************/
/*        Include        */
/*************************/

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xos.h>
# include <X11/Xatom.h>
# include <X11/keysym.h>
# include <X11/extensions/XShm.h>
# include <sys/shm.h>

# include "libft/libft.h"

# define MLX_MAX_EVENT LASTEvent

/*************************/
/*        Typedef        */
/*************************/

typedef struct s_data	t_data;
typedef struct s_list	t_list;
typedef struct s_img	t_img;
typedef struct s_env	t_env;

/*************************/
/*       Structure       */
/*************************/

typedef struct			s_event_list
{
	int					mask;
	int					(*hook)();
	void				*param;
}						t_event_list;

typedef struct			s_win_list
{
	Window				window;
	GC					gc;
	struct s_win_list	*next;
	int					(*mouse_hook)();
	int					(*key_hook)();
	int					(*expose_hook)();
	void				*mouse_param;
	void				*key_param;
	void				*expose_param;
	t_event_list		hooks[MLX_MAX_EVENT];
}						t_win_list;

typedef struct			s_xvar
{
	Display				*display;
	Window				root;
	int					screen;
	int					depth;
	Visual				*visual;
	Colormap			cmap;
	int					private_cmap;
	t_win_list			*win_list;
	int					(*loop_hook)();
	void				*loop_param;
	int					use_xshm;
	int					pshm_format;
	int					do_flush;
	int					decrgb[6];
}						t_xvar;

struct					s_img
{
	XImage				*image;
	Pixmap				pix;
	GC					gc;
	int					size_line;
	int					bpp;
	int					width;
	int					height;
	int					type;
	int					format;
	char				*data;
	XShmSegmentInfo		shm;
};

struct					t_list
{
	t_img				*img;
	t_list				*next;
};

struct					s_env
{
	t_xvar				*mlx;
	void				*win;
};

struct					s_data
{
	t_list				*list;
	int					pos_x;
	int					pos_y;
	int					rot;
	char				**map;
};

/*************************/
/*        Prototype      */
/*************************/

t_data	g_data;

int		on_key_up(void);
int		on_key_down(void);
int		on_key_left(void);
int		on_key_right(void);

void	ligne(int xi,int yi,int xf,int yf, t_data *data, int color);

#endif
