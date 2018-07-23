/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:24:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/23 09:35:01 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft.h"

# define M_WIDTH 24
# define M_HEIGHT 24

# define WIDTH 320
# define HEIGHT 200

typedef struct	s_vec2
{
	double 		x;
	double		y;
}				t_vec2;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		fov;
	double		height;
}				t_player;

// typedef struct	s_plane
// {
// 	int			proj_plane;
// 	int			cent_x;
// 	int			cent_y;
// 	double		dist_plane;
// 	double		angle_rays;
// }				t_plane;

typedef struct	s_plane
{
	double		x;
	double		y;
}				t_plane;

typedef struct	s_window
{
	void		*win;
	void		*mlx;
}				t_window;

#endif
