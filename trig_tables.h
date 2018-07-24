/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 07:04:57 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/24 09:57:11 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIG_TABLES_H
# define TRIG_TABLES_H

# include "wolf3d.h"

# define ANGLE_60 WIDTH
# define ANGLE_30 round(WIDTH / 2)
# define ANGLE_15 round(ANGLE_30 / 2)
# define ANGLE_90 round(ANGLE_30 * 3)
# define ANGLE_180 round(ANGLE_90 * 2)
# define ANGLE_270 round(ANGLE_90 * 3)
# define ANGLE_360 round(ANGLE_180 * 2)
# define ANGLE_0 0
# define ANGLE_10 round(ANGLE_30 / 10)
# define ANGLE_45 round(ANGLE_15 * 3)

typedef	struct	s_tables
{
	int			t_sin[ANGLE_360 + 1];
	int			t_cos[ANGLE_360 + 1];
	int			t_tan[ANGLE_360 + 1];
	int			t_isin[ANGLE_360 + 1];
	int			t_icos[ANGLE_360 + 1];
	int			t_itan[ANGLE_360 + 1];
	int			t_fish[ANGLE_360 + 1];
	int			t_step_x[ANGLE_360 + 1];
	int			t_step_y[ANGLE_360 + 1];
}				t_tables;

void	init_step_tables(t_tables *tables);
void	init_fish_table(t_tables *tables);
void	init_trig_tables(t_tables *tables);

#endif
