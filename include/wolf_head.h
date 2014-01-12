/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_head.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:53:00 by abrault           #+#    #+#             */
/*   Updated: 2014/01/12 12:44:27 by abrault          ###   ########.fr       */
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

# include <math.h>

# include "libft/libft.h"

/*************************/
/*         Define        */
/*************************/

# define WIDTH_WINDOW	640
# define HEIGHT_WINDOW	400
# define MLX_MAX_EVENT	LASTEvent
# define SIZE_CASE		64
# define PRECISION		5
# define FOV			64
# define PI				3.14159265359
# define VITESSE		15
# define MLX_KEY_ESC	65307
# define MLX_KEY_UP		65362
# define MLX_KEY_DOWN	65364
# define MLX_KEY_LEFT	65361
# define MLX_KEY_RIGHT	65363

/*************************/
/*        Typedef        */
/*************************/

typedef struct s_data		t_data;
typedef struct s_img		t_img;
typedef struct s_env		t_env;
typedef struct s_line		t_line;
typedef struct s_point		t_point;

/*************************/
/*       Structure       */
/*************************/

typedef struct				s_event_list
{
	int						mask;
	int						(*hook)();
	void					*param;
}							t_event_list;

typedef struct				s_win_list
{
	Window					window;
	GC						gc;
	struct s_win_list		*next;
	int						(*mouse_hook)();
	int						(*key_hook)();
	int						(*expose_hook)();
	void					*mouse_param;
	void					*key_param;
	void					*expose_param;
	t_event_list			hooks[MLX_MAX_EVENT];
}							t_win_list;

typedef struct				s_xvar
{
	Display					*display;
	Window					root;
	int						screen;
	int						depth;
	Visual					*visual;
	Colormap				cmap;
	int						private_cmap;
	t_win_list				*win_list;
	int						(*loop_hook)();
	void					*loop_param;
	int						use_xshm;
	int						pshm_format;
	int						do_flush;
	int						decrgb[6];
}							t_xvar;

struct						s_img
{
	XImage					*image;
	Pixmap					pix;
	GC						gc;
	int						size_line;
	int						bpp;
	int						width;
	int						height;
	int						type;
	int						format;
	char					*data;
	int						endian;
	XShmSegmentInfo			shm;
};

struct						s_data
{
	float					pos_x;
	float					pos_y;
	int						rot;
	int						red;
	int						green;
	int						blue;
	int						fov;
	int						nbr_col;
	int						nbr_line;
	float					dist_ecran;
	t_img					*img;
	char					**map;
};

struct						s_env
{
	t_xvar					*mlx;
	void					*win;
	t_data					*data;
};

struct						s_point
{
	int						x;
	int						y;
	int						blue;
	int						green;
	int						red;
};

struct						s_line
{
	int						first_x;
	int						first_y;
	int						second_x;
	int						second_y;
	int						red;
	int						green;
	int						blue;
};

/*************************/
/*        Prototype      */
/*************************/

/* Keyboard */
int							on_key_up(t_env *e);
int							on_key_down(t_env *e);
int							on_key_left(t_env *e);
int							on_key_right(t_env *e);

/* Tools */
float	rad(float degre);

/* Event */
int		expose_hook(t_env *e);
int		key_hook(int keycode, t_env *e);

/* Init */
t_env	*ini_env(t_env *e);
int		ini_data_and_img(t_env *e, char *file);
char	**get_map(char *file, t_env *e);

/* Draw */
void	draw_image(t_env *e);
void	mlx_pixel_put_to_image(t_env *e, t_point *draw);

#endif
