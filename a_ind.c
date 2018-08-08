/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 08:24:10 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/08 18:38:02 by shillebr         ###   ########.fr       */
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
		a = d - 90;
	else if (d > 180 && d < 270)
		a = d - 90;
	else if (d > 270 && d < 360)
		a = d - 180;
	return (a * 10);
}

double		ft_tan(t_dist **d)
{
	double	a;
	double	ret;

	a = (*d)->a;
	if ((*d)->a > 0 && (*d)->a < 90)
		ret = (*d)->n * (*d)->t->t_tan[(int)((90 - (*d)->a) * 10)];
	else if ((*d)->a > 90 && (*d)->a < 180)
		ret = (*d)->n * (*d)->t->t_tan[(int)(((*d)->a - 90) * 10)];
	else if ((*d)->a > 180 && (*d)->a < 270)
		ret = (*d)->n * (*d)->t->t_tan[(int)(((*d)->a - 90) * 10)];
	else if ((*d)->a > 270 && (*d)->a < 360)
		ret = (*d)->n * (*d)->t->t_tan[(int)(((*d)->a - 180) * 10)];
	else
		ret = (*d)->n * (*d)->t->t_tan[(int)(((*d)->a) * 10)];
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