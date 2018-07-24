/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 07:04:57 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/24 08:07:23 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIG_TABLES_H
# define TRIG_TABLES_H

# include "wolf3d.h"

# define ANGLE_60 WIDTH
# define ANGLE_30 WIDTH / 2
# define ANGLE_15 ANGLE_30 / 2
# define ANGLE_90 ANGLE_30 * 3
# define ANGLE_180 ANGLE_90 * 2
# define ANGLE_270 ANGLE_90 * 3
# define ANGLE_360 ANGLE_180 * 2
# define ANGLE_0 0
# define ANGLE_10 ANGLE_30 / 10
# define ANGLE_45 ANGLE_15 * 3

typedef	struct	s_trig_tab
{
	double		t_sin[ANGLE_360 + 1];
	double		t_cos[ANGLE_360 + 1];
	double		t_tan[ANGLE_360 + 1];
	double		t_isin[ANGLE_360 + 1];
	double		t_icos[ANGLE_360 + 1];
	double		t_itan[ANGLE_360 + 1];
	double		t_fish[ANGLE_360 + 1];
	double		t_step_x[ANGLE_360 + 1];
	double		t_step_y[ANGLE_360 + 1];
}				t_trig_tab;

#endif
