/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_head.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:53:00 by abrault           #+#    #+#             */
/*   Updated: 2014/01/07 14:18:22 by abrault          ###   ########.fr       */
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

/*************************/
/*         Define        */
/*************************/

# define WIDTH_WINDOW	800
# define HEIGHT_WINDOW	600
# define MLX_MAX_EVENT	LASTEvent

/*************************/
/*        Typedef        */
/*************************/

typedef struct s_data		t_data;
typedef struct s_img		t_img;
typedef struct s_env		t_env;
typedef struct s_line		t_line;

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
	int					endian;
	XShmSegmentInfo		shm;
};

struct					s_data
{
	int					pos_x;
	int					pos_y;
	int					rot;
	t_img				*img;
	char				**map;
};

struct					s_env
{
	t_xvar				*mlx;
	t_win_list			*win;
	t_data				*data;
};

struct					s_line
{
	int					beg_x;
	int					beg_y;
	int					end_x;
	int					end_y;
};

/*************************/
/*        Prototype      */
/*************************/

int		on_key_up(t_env *e);
int		on_key_down(t_env *e);
int		on_key_left(t_env *e);
int		on_key_right(t_env *e);

void	mlx_destroy_image(t_img *img);
int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e)

t_env	*ini_env(t_env *e, char *file);
int		ini_data_and_img(t_env *e, char *file);

char	**get_map(char *file);
void	ligne(int xi,int yi,int xf,int yf, t_env *e, int color);

#endif
