/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 08:24:10 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/08 08:58:15 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

int		a_ind(double d)
{
	double	a;

	a = d;
	if (d > 0 && d < 90)
		a = 90 - d;
	else if (d > 90 && d < 180)
		a = d - 180;
	else if (d > 180 && d < 270)
		a = d - 270;
	else if (d >270 && d < 360)
		a = d - 360;
	return (a * (ANGLE_360 / 360));
}

double	ft_dist_calc(t_player *p, t_vec2 *dist)
{
	double	distance;
	double	a;
	double	b;

	a = ((p->pos)->x - dist->x) * ((p->pos)->x - dist->x);
	b = ((p->pos)->y - dist->y) * ((p->pos)->y - dist->y);
	distance = sqrt(a + b);
	return (distance);
}