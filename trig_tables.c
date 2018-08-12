/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 07:05:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/10 13:21:03 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trig_tables.h"

void	init_trig_tables(t_tables *tables)
{
	int		i;
	double	rad;

	i = 0;
	while (i < 3600)
	{
		rad = (((double)i / 10) * M_PI) / 180;
		tables->t_sin[i] = sin(rad);
		tables->t_cos[i] = cos(rad);
		tables->t_tan[i] = tan(rad);
		tables->t_isin[i] = 1 / tables->t_sin[i];
		tables->t_icos[i] = 1 / tables->t_cos[i];
		tables->t_itan[i] = 1 / tables->t_tan[i];
		i++;
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
		tables->t_fish[(int)ANGLE_30 + i] = (1 / cos(rad));
		i++;
	}
}

void	init_step_tables(t_tables *tables)
{
	int i;

	i = 0;
	while (i < ANGLE_360)
	{
		if (i >= ANGLE_90 && i <= ANGLE_270)
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
		i++;
	}
}

void    init_tables(t_tables *tables)
{
    init_trig_tables(tables);
    init_step_tables(tables);
    init_fish_table(tables);
}

t_tables	*get_tables(void)
{
	static t_tables *t;

	if (!t)
	{
		t = (t_tables *)malloc(sizeof(t_tables));
		if (!t)
			return (NULL);
		init_tables(t);
	}
	return (t);
}
