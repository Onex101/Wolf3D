/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 07:04:57 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/23 10:06:35 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIG_TABLES_H
# define TRIG_TABLES_H

# include "wolf3d.h"

# define ANGLE_60 WIDTH
# define ANGLE_30 floor(WIDTH / 2)
# define ANGLE_15 floor(ANGLE_30 / 2)
# define ANGLE_90 floor(ANGLE_30 * 3)
# define ANGLE_180 floor(ANGLE_90 * 2)
# define ANGLE_270 floor(ANGLE_90 * 3)
# define ANGLE_360 floor(ANGLE_180 * 2)
# define ANGLE_0 0
# define ANGLE_10 floor(ANGLE_30 / 10)
# define ANGLE_45 floor(ANGLE_15 * 3)

typedef	struct	s_tables
{
	double		t_sin[7200 + 1];
	double		t_cos[7200 + 1];
	double		t_tan[7200 + 1];
	double		t_isin[7200 + 1];
	double		t_icos[7200 + 1];
	double		t_itan[7200 + 1];
	double		t_fish[WIDTH * 6 + 1];
	double		t_step_x[WIDTH * 6 + 1];
	double		t_step_y[WIDTH * 6 + 1];
}					t_tables;

typedef struct		s_dist
{
	t_tables		*t;
	t_vec2			*h_dist;
	t_vec2			*v_dist;
	t_pnt			*p1;
	t_pnt			*p2;
	double			h_distance;
	double			v_distance;
	double			a;
	int				n;
	int				wall;
	int				h_wall;
	int				v_wall;
}					t_dist;

//
void			ft_step_calc(t_dda **l);
int				ft_border(t_dda *l, t_param *par);
int				ft_check_block(t_dda **l, t_param *par);
int				ft_dda(t_dda **l, t_param *par);
void			draw_col(double dist, int col, t_param *p, t_dda *l);
t_vec2			*ft_dir_vec(t_player *p, t_tables *t);
t_vec2			*ft_plane_vec(t_player *p, t_tables *t);
t_vec2			*ft_ray_dir_vec(t_vec2 *dir, t_vec2 *plane, double cameraX);
t_dda			*ft_dda_init(t_player *p, t_param *par, t_tables *t);
t_vec2			*ft_init_delta_dist(t_vec2 *rayDir);
int				ft_dda_assign(t_dda **l, t_param *par, double cam_x);
void			ft_dda_unassign(t_dda **l);
//
void			init_step_tables(t_tables *tables);
void			init_fish_table(t_tables *tables);
void			init_trig_tables(t_tables *tables);
void			init_tables(t_tables *tables);
t_tables		*get_tables(void);

double			cos_d(double i);
double			sin_d(double i);
double			tan_d(double i);
//
void			ft_vec2_free(t_vec2 *p);
void			ft_pnt_free(t_pnt *p);
void			ft_line_free(t_line *p);
void			ft_player_free(t_player *p);
void			ft_tables_free(t_tables *p);
void			ft_dist_free(t_dist *p);
void			ft_check_free(t_check *p);
//
double			ft_tan(t_dist **d);
t_dist			*ft_init_dist(t_player *p, t_tables *t);
t_check			*ft_init_check(void);
double 			ft_dist(t_player *p, t_pnt **p2, t_dist **d, int x);
t_vec2			*ft_find_wall(t_check **h, t_param *par);
int				ft_find_h_col(t_check **ret, t_player *p, t_dist **d, t_param *par);
int				ft_hori_check(t_player *p, t_dist **d, t_param *par);
int				ft_find_v_col(t_check **ret, t_player *p, t_dist **d, t_param *par);
int				ft_vert_check(t_player *p, t_dist **d, t_param *par);
double 			ft_get_dist(t_player *p, t_dist *d, t_param *par);
void			ft_angle(t_dist **d, double angle);
int				ft_rays(t_param *par, t_player *p);

#endif