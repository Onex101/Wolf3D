/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 07:05:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/24 09:59:56 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trig_tables.h"

void	init_trig_tables(t_tables *tables)
{
	int		i;
	double	rad;

	i = 0;
	while (i < ANGLE_360)
	{
		rad = (i * M_PI) / ANGLE_180;
		tables->t_sin[i] = sin(rad);
		tables->t_cos[i] = cos(rad);
		tables->t_tan[i] = tan(rad);
		tables->t_isin[i] = 1 / table->t_sin[i];
		tables->t_icos[i] = 1 / table->t_cos[i];
		tables->t_itan[i] = 1 / table->t_tan[i];
	}
}

void	init_fish_table(t_tables *tables)
{
	int		i;
	double	rad;

	i = -ANGLE_30;
	while (i < ANGLE_30)
	{
		rad = (i * M_PI) / ANGLE_180;
		tables->fish[i + ANGLE_30] = (1 / cos(rad));
	}
}

void	init_step_tables(t_tables *tables)
{
	int i;

	while (i < ANGLE_360)
	{
		if (i >= ANGLE_90 && i <= ANGLE270)
		{
			tables->t_step_x[i] = WALL_HEIGHT / tables->t_tan[i];
			if (tables->t_step_x[i] > 0)
				tables->t_step_x[i] *= -1;
		}
		else
		{
			tables->t_step_x[i] = WALL_HEIGHT / tables->t_tan[i];
			if (tables->t_step_x[i] < 0)
				tables->t_step_x[i] *= -1;
		}
		if (i >= ANGLE_0 && i <= ANGLE_180)
		{
			tables->t_step_y[i] = WALL_HEIGHT / tables->t_tan[i];
			if (tables->t_step_y[i] < 0)
				tables->t_step_y[i] *= -1;
		}
		else
		{
			tables->t_step_y[i] = WALL_HEIGHT / tables->t_tan[i];
			if (tables->t_step_y[i] > 0)
				tables->t_step_y[i] *= -1;
		}
	}
}

void	init_tables(t_tables *tables)
{
	init_step_tables(tables);
	init_fish_table(tables);
	init_trig_tables(tables);
}
