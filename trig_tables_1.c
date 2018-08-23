/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:49:38 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/23 15:00:25 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trig_tables.h"

void		init_trig_tables(t_tables *tables)
{
	int		i;
	double	rad;

	i = 0;
	while (i < 7200)
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

void		init_step_up(t_tables *tables, int i)
{
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

void		init_step_tables(t_tables *tables)
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
		init_step_up(tables, i);
		i++;
	}
}

void		init_tables(t_tables *tables)
{
	init_trig_tables(tables);
	init_step_tables(tables);
}

t_tables	*get_tables(void)
{
	t_tables *t;

	if (!(t = (t_tables *)malloc(sizeof(t_tables))))
		return (NULL);
	init_tables(t);
	return (t);
}
