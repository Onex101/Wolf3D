/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:24:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/25 18:08:28 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "vector.h"

# define M_WIDTH 24
# define M_HEIGHT 24

# define WIDTH 600
# define HEIGHT 400
# define FOV 60
# define WALL_HEIGHT 64
# define SCALE (WIDTH * HEIGHT) / WALL_HEIGHT / 50

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
	t_vec2		pos;
	t_vec2		dir;
	double		v_angle;
	double		hght;
}				t_player;

typedef struct	s_plane
{
	int			proj_plane;
	t_vec2		centre;
	double		dist_plane;
	double		angl_rays;
}				t_plane;

typedef struct	s_window
{
	void		*win;
	void		*mlx;
}				t_window;

typedef struct	s_line_p
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
}				t_line_p;

typedef struct	s_map
{
	t_vector	*ver_vec;
	double		max_x;
	double		max_y;
}				t_map;

typedef	struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

void			draw_line(t_pnt *pnt1, t_pnt *pnt2, t_window *p);
void			draw_square(t_pnt *s, t_window *w);
t_vec3			*new_vertex(double x, double y, double z);
t_map			*read_map(int fd);

#endif
