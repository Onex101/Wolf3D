/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 07:04:57 by xrhoda            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/30 14:34:33 by shillebr         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2018/07/30 09:41:59 by xrhoda           ###   ########.fr       */
=======
/*   Updated: 2018/07/30 09:01:25 by shillebr         ###   ########.fr       */
>>>>>>> 379ff54766860855e531f0c31e8c107ab66e28a9
>>>>>>> 0a51f07c89c16a50f2b274168bb522b55a1df80d
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
	double		t_sin[WIDTH * 6 + 1];
	double		t_cos[WIDTH * 6 + 1];
	double		t_tan[WIDTH * 6 + 1];
	double		t_isin[WIDTH * 6 + 1];
	double		t_icos[WIDTH * 6 + 1];
	double		t_itan[WIDTH * 6 + 1];
	double		t_fish[WIDTH * 6 + 1];
	double		t_step_x[WIDTH * 6 + 1];
	double		t_step_y[WIDTH * 6 + 1];
}				t_tables;

void			init_step_tables(t_tables *tables);
void			init_fish_table(t_tables *tables);
void			init_trig_tables(t_tables *tables);
void			init_tables(t_tables *tables);
t_tables		*get_tables(void);
//
t_vec2			*ft_hori_check(t_player *p, t_tables *t, t_param *par, double theta);
t_vec2			*ft_vert_check(t_player *p, t_tables *t, t_param *par, double theta);
double			ft_get_distance(t_player *p, double theta, t_param *par);
int				ft_rays(t_param *par);

#endif
