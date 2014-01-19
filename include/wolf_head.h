/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_head.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:53:00 by abrault           #+#    #+#             */
/*   Updated: 2014/01/19 18:15:59 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_HEAD_H
# define WOLF_HEAD_H

/*************************/
/*        Include        */
/*************************/

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# include <X11/X.h>
# include <X11/Xlib.h>

# include "libft/libft.h"

/*************************/
/*         Define        */
/*************************/

# define W_WIN					1100
# define H_WIN					800
# define MLX_MAX_EVENT			LASTEvent
# define SIZE_CASE				64
# define PRECISION				10
# define FOV					60
# define PI						3.14159265359
# define VITESSE				15
# define MLX_KEY_ESC			65307
# define MLX_KEY_UP				65362
# define MLX_KEY_DOWN			65364
# define MLX_KEY_LEFT			65363
# define MLX_KEY_RIGHT			65361
# define MLX_KEY_PLACE_BLOCK	50
# define MLX_KEY_DELETE_BLOCK	51
# define MLX_KEY_SPACE			32
# define MLX_KEY_CUBE_LEFT		49
# define MLX_KEY_CUBE_RIGHT		52
# define NB_TEXTURE				15
# define MAX_DISTANCE			150
# define MIN_DISTANCE			600

/*************************/
/*        Typedef        */
/*************************/

typedef struct s_data		t_data;
typedef struct s_img		t_img;
typedef struct s_env		t_env;
typedef struct s_line		t_line;
typedef struct s_point		t_point;
typedef struct s_texture	t_texture;
typedef struct s_tempvar	t_tempvar;

/*************************/
/*       Structure       */
/*************************/

typedef struct				s_event_list
{
	int						mask;
	void					*param;
}							t_event_list;

typedef struct				s_win_list
{
	Window					window;
	GC						gc;
	struct s_win_list		*next;
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
	int						direc;
	float					dist_ecran;
	t_img					*img;
	char					**map;
	int						id;
	int						col;
	t_texture				*texture;
	int						item_select;
	char					*inv;
	char					in_batiment;
	float					lum;
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
	int						dist;
};

struct						s_texture
{
	t_img					**id;
};

struct						s_tempvar
{
	float					new_x;
	float					new_y;
	float					angle;
	float					cosa;
	float					sina;
};

/*************************/
/*        Prototype      */
/*************************/

/* Keyboard */
int							on_key_up(t_env *e);
int							on_key_down(t_env *e);
int							on_key_left(t_env *e);
int							on_key_right(t_env *e);
void						on_special_key(t_env *e, int keycode);

/* Special Block */
int							use_lever(t_env *e, int id);

/* Tools */
float						ft_rad(float degre);
float						ft_abs(float nbr);

/* Event */
int							expose_hook(t_env *e);
int							key_hook(int keycode, t_env *e);

/* Init */
t_env						*ini_env(t_env *e);
int							ini_data_and_img(t_env *e, char *file);
int							get_map(char *file, t_env *e);
int							get_dim_map(char *file, t_env *e);
int							ini_map(t_env *e, char *file);
void						ini_texture(t_env *e);
int							ini_inv(t_env *e);

/* Image */
void						draw_image(t_env *e);
void						draw_stage(t_env *e);
void						mlx_pixel_put_to_image(t_env *e, t_point *draw);
void						get_color(t_env *e);
t_img						*load_texture(t_env *e, char *file);
void						cpy_img(t_env *e, int x, int dist, t_img *img);
void						cpy_gui_img(t_env *e, t_img *img, int x, int y);
void						cpy_sky(t_env *e, int x, int dist, t_img *img);
void						cpy_all_img(t_env *e, t_img *img, int x, int y);
void						draw_gui(t_env *e);
void						cpy_block_i(t_env *e, int x, int dist, t_img *img);

#endif
