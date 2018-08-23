/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:24:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/23 11:31:18 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if defined(__APPLE__) && defined(__MACH__)
#  define OS 1
#elif defined(__linux__)
#  define OS 0
#endif

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "vector.h"

# define M_WIDTH 8
# define M_HEIGHT 8
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

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_pnt
{
	int			x;
	int			y;
}				t_pnt;

typedef struct	s_line
{
	double		x1;
	double		y1;
	double		x2;
	double		y2;
}				t_line;

typedef struct	s_player
{
	t_vec2		*pos;
	t_vec2		*dir;
	t_pnt		m_pos;
	int			v_angle;
	double		hght;
	int			spd;
}				t_player;

typedef struct	s_plane
{
	int			proj_plane;
	t_vec2		centre;
	double		dist_plane;
	double		angl_rays;
}				t_plane;

typedef struct	s_line_p
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			c;
}				t_line_p;

typedef struct	s_map
{
	t_vector	*ver_vec;
	int			max_x;
	int			max_y;
}				t_map;

typedef	struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_param
{
	t_map		*map;
	t_player	*player;
	int			x_scale;
	int			y_scale;
	void		*mlx;
	void		*win;
	int			*buf;
	void		*image;
	int			s_line;
}				t_param;

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


void			draw_line(t_pnt *pnt1, t_pnt *pnt2, t_param *p, int c);
t_vec3			*new_vertex(double x, double y, double z);
t_map			*read_map(int fd);
void			draw_map(t_param *p);
void			draw_f_square(t_pnt *s, t_param *p, int c);
void			draw_player(t_param *p);
void			draw_ray(t_pnt *pnt1, t_pnt *pnt2, t_param *p, int c);
void 			draw_f_circle(t_pnt *s, t_param *p, int radius, int c);
void			draw_back(t_param *p);
void			pixel_put_image(t_param *p, int x, int y, int c);
void			clear_image(t_param *p);
int				key_press(int keycode, t_param *p);
void			mac_key_press(int keycode, t_param *p);
void			linux_key_press(int keycode, t_param *p);
t_vec2  		*ft_vec2_init(double x, double y);
t_pnt  			*ft_pnt_init(int x, int y);
t_line			*ft_line_init(double x1, double y1, double x2, double y2);
t_player		*ft_player_init(t_param *par);
double			ft_dist_calc(t_player *p, t_vec2 *dist, double ang);
int				key_hook(int keycode, t_param *p);

#endif
