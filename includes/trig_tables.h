/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 07:04:57 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/30 07:47:39 by shillebr         ###   ########.fr       */
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
	double		t_step_x[WIDTH * 6 + 1];
	double		t_step_y[WIDTH * 6 + 1];
}				t_tables;

/*
** Exit
*/
void			free_map(t_param *p);
void			free_map_arr(char **str_arr, int y_max);
int				ft_exit(t_param *p);
/*
** Trig Tables 2
*/
double			cos_d(double i);
double			sin_d(double i);
double			tan_d(double i);
/*
** Trig Tables 1
*/
void			init_trig_tables(t_tables *tables);
void			init_step_up(t_tables *tables, int i);
void			init_step_tables(t_tables *tables);
void			init_tables(t_tables *tables);
t_tables		*get_tables(void);
/*
** Struct Free 2
*/
void			free_str_arr(char **str_arr);
void			ft_player_free(t_player *p);
void			ft_tables_free(t_tables *p);
void			ft_dda_free(t_dda *p);
/*
** DDA Init
*/
t_vec2			*ft_dir_vec(t_player *p, t_tables *t);
t_vec2			*ft_plane_vec(t_player *p, t_tables *t);
t_vec2			*ft_ray_dir_vec(t_vec2 *dir, t_vec2 *plane, double cam_x);
t_dda			*ft_dda_init(t_player *p, t_param *par, t_tables *t);
t_vec2			*ft_init_delta_dist(t_vec2 *ray_dir);
/*
** New Dist
*/
void			ft_d_calc(t_dda *l, t_param *par, t_player *p, int col);
int				ft_distance(t_param *par, t_player *p, t_tables *t);
int				ft_rays(t_param *par, t_player *p);

#endif
