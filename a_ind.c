/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 08:24:10 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/20 09:13:54 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>

int		a_ind(double d)
{
	double	a;

	a = d;
	if (d > 0 && d < 90)
		a = 90 - d;
	else if (d > 90 && d < 180)
		a = d - 90;
	else if (d > 180 && d < 270)
		a = d - 90;
	else if (d > 270 && d < 360)
		a = d - 180;
	return (a * 10);
}

void		ft_flip(t_check **h, t_player *p)
{
	(*h)->col->y =  p->pos->y + (-((*h)->col->y - p->pos->y));
	(*h)->ya = -(*h)->ya;
}

double		ft_tan(t_dist **d)
{
	double	a;
	double	ret;

	a = (*d)->a;
	ret = (*d)->n * (*d)->t->t_tan[(int)(a * 10)];
	return (ret);
}

double	ft_dist_calc(t_player *p, t_vec2 *dist, double ang)
{
	double	distance;
	double	a;
	double	b;

	if (ang == 0)
		ft_putendl("Zero the Hero");
	a = (dist->x - (p->pos)->x) * (dist->x - (p->pos)->x);
	b = (dist->y - (p->pos)->y) * (dist->y - (p->pos)->y);
	// a = fabs((p->pos)->x - dist->x) / cos_d(ang);
	// b = fabs((p->pos)->y - dist->y) / sin_d(ang);
	// if (fabs(a) <= fabs(b))
	// 	distance = fabs(a);
	// else
	// 	distance = fabs(b);
	distance = sqrt(a + b);
	return (distance);
}