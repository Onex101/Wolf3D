/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 08:24:10 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/09 14:06:17 by shillebr         ###   ########.fr       */
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
	printf("Col x = %f xa = %f, Col y = %f ya = %f\n", (*h)->col->x, (*h)->xa, (*h)->col->y, (*h)->ya);
	(*h)->col->y =  p->pos.y + (-((*h)->col->y - p->pos.y));
	(*h)->ya = -(*h)->ya;
	printf("Col x = %f xa = %f, Col y = %f ya = %f\n", (*h)->col->x, (*h)->xa, (*h)->col->y, (*h)->ya);
}

double		ft_tan(t_dist **d)
{
	double	a;
	double	ret;

	a = (*d)->n * (*d)->a;
	if (a > 0 && a < 90)
		ret = (*d)->n * (*d)->t->t_tan[(int)((90 - a) * 10)];
	else if (a > 90 && a < 180)
		ret = (*d)->n * (*d)->t->t_tan[(int)((a - 90) * 10)];
	else if (a > 180 && a < 270)
		ret = (*d)->n * (*d)->t->t_tan[(int)((a - 90) * 10)];
	else if (a > 270 && a < 360)
		ret = (*d)->n * (*d)->t->t_tan[(int)((a - 270) * 10)];
	else
		ret = (*d)->n * (*d)->t->t_tan[(int)(a * 10)];
	return (ret);
}

double	ft_dist_calc(t_player *p, t_vec2 *dist)
{
	double	distance;
	double	a;
	double	b;

	a = ((p->pos).x - dist->x) * ((p->pos).x - dist->x);
	b = ((p->pos).y - dist->y) * ((p->pos).y - dist->y);
	distance = sqrt(a + b);
	return (distance);
}