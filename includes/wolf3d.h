/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:14:31 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/30 07:07:41 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"
# include "os.h"

# define MAP_SIZE 10
# define WIDTH 640
# define HEIGHT 640
# define FOV 60
# define WALL_HEIGHT 100
# define WALL_COL 0xAAAAAA
# define SPC_COL 0x555555
# define TILE_SIZE 64
# define P_COL 0xFF0000
# define PLANE_DIST 277
# define SKY_COL 0x000055
# define FLOOR_COL 0x550000

typedef struct		s_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct		s_pnt
{
	int				x;
	int				y;
}					t_pnt;

typedef struct		s_ln
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
}					t_ln;

typedef struct		s_player
{
	t_vec2			*pos;
	t_vec2			*dir;
	t_pnt			m_pos;
	int				v_angle;
	double			hght;
	int				spd;
}					t_player;

typedef struct		s_plane
{
	int				proj_plane;
	t_vec2			centre;
	double			dist_plane;
	double			angl_rays;
}					t_plane;

typedef struct		s_line_p
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				c;
}					t_line_p;

typedef struct		s_map
{
	char			**m;
	int				max_x;
	int				max_y;
}					t_map;

typedef	struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct		s_param
{
	t_map			*map;
	t_player		*player;
	int				x_scale;
	int				y_scale;
	void			*mlx;
	void			*win;
	int				*buf;
	void			*image;
	int				s_line;
	int				scrn;
}					t_param;

typedef struct		s_dda
{
	t_vec2			*p;
	t_vec2			*dir;
	t_vec2			*plane;
	t_vec2			*ray_dir;
	t_vec2			*side_dist;
	t_vec2			*delta_dist;
	t_pnt			*map;
	t_pnt			*step;
	int				wall;
	int				side;
	int				col;
	void			*pos;
}					t_dda;

/*
** Wall Check
*/
int					wall_block_check(t_param *par, t_player *p, t_pnt *arr);
int					wall_check(t_param *par, t_player *p, int x_inc, int y_inc);
void				move_forward(t_param *p, double x_change, double y_change);
void				move_back(t_param *p, double x_change, double y_change);
/*
** Inputs
*/
void				mac_rotate(int keycode, t_param *p);
void				mac_key_press(int keycode, t_param *p);
void				linux_rotate(int keycode, t_param *p);
void				linux_key_press(int keycode, t_param *p);
int					key_press(int keycode, t_param *p);
/*
** Struct Free 1
*/
void				ft_vec2_free(t_vec2 *p);
void				ft_vec3_free(t_vec3 *p);
void				ft_pnt_free(t_pnt *p);
void				ft_line_free(t_line *p);
/*
** Struct init
*/
t_vec2				*ft_vec2_init(double x, double y);
t_vec3				*ft_vec3_init(double x, double y, double z);
t_pnt				*ft_pnt_init(int x, int y);
t_ln				*ft_line_init(double x1, double y1, double x2, double y2);
t_player			*ft_player_init(t_param *par);
/*
** Draw Line
*/
void				pnt_check(t_pnt *pnt1);
void				draw_line(t_pnt *pnt1, t_pnt *pnt2, t_param *p, int c);
/*
** Draw Colour
*/
unsigned long		rgb_to_hex(int r, int g, int b);
int					check_wall_color(int c1, int c2, int colour);
int					get_wall_colour(double dis, t_dda *l);
/*
** Draw
*/
void				ft_drawray(t_player *p, t_dda *l, double d, t_param *par);
void				draw_f_square(t_pnt *s, t_param *p, int c);
void				draw_ray(t_pnt *pnt1, t_pnt *pnt2, t_param *p, int c);
void				draw_col(double dist, int col, t_param *p, t_dda *l);
/*
** Image
*/
void				clear_image(t_param *p);
void				pixel_put_image(t_param *p, int x, int y, int c);
/*
** DDA Step
*/
void				ft_step_calc(t_dda **l);
int					ft_border(t_dda *l, t_param *par);
int					ft_check_block(t_dda **l, t_param *par);
int					ft_dda(t_dda **l, t_param *par);
/*
** DDA Assign
*/
int					ft_dda_assign(t_dda **l, t_param *par, double cam_x);
void				ft_dda_unassign(t_dda **l);
/*
** Draw Map
*/
void				draw_map(t_param *p);
/*
** Draw Background
*/
void				draw_sky(int *c, int *l, int *col, t_param *p);
void				draw_floor(int *c, int *l, int *col, t_param *p);
void				draw_back(t_param *p);
/*
** Read Map
*/
void				ft_make_line(char **dest, char *src);
void				ft_arradd(char ***file, char *line, int size);
int					ft_readfile(char ***f, char *av);
/*
** Main File
*/
int					draw_to_screen(t_param *p);
int					map_init(t_param **p, char *str);
int					init_param(t_param **p, char *str);

#endif
