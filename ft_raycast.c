/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06:57:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/10 13:20:58 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>


double		ft_diff(t_player *p, double theta)
{
	if (p->v_angle >= theta)
		return (-1 * (p->v_angle - theta));
	else
		return (theta - p->v_angle);
}

double  ft_dist(t_player *p, t_pnt **p2, t_vec2 *d_vec, double dist, t_dist *d)
{
	double  distance;

	(*p2)->x = (int)(d_vec->x);
	(*p2)->y = (int)(d_vec->y);
	distance = dist / (d->n * d->t->t_cos[a_ind(ft_diff(p, d->a))]);
	return (distance);
}

double  ft_get_dist(t_player *p, t_dist *d, t_param *par)
{
	double  dist;
	t_pnt	*p1;
	t_pnt	*p2;

	if (!(p1 = ft_pnt_init(p->pos.x, p->pos.y)) || !(p2 = ft_pnt_init(0, 0)))
		exit (0);
	if (!(ft_vert_check(p, &d, par)))
		d->v_dist = NULL;
	if (!(ft_hori_check(p, &d, par)))
		d->h_dist = NULL;
	if (d->v_dist != NULL && d->h_dist != NULL)
	{
		if (d->h_distance <= d->v_distance)
			dist = ft_dist(p, &p2, d->h_dist, d->h_distance, d);
		else
			dist = ft_dist(p, &p2, d->v_dist, d->v_distance, d);
	}
	else if (d->v_dist == NULL && d->h_dist != NULL)
	{
		dist = ft_dist(p, &p2, d->h_dist, d->h_distance, d);
	}
	else if (d->v_dist != NULL && d->h_dist == NULL)
	{
		dist = ft_dist(p, &p2, d->v_dist, d->v_distance, d);
	}
	else
		exit (0);
	ft_putstr("p2 x = ");
	ft_putnbr(p2->x);
	ft_putstr(" (");
	ft_putnbr(p2->x / par->x_scale);
	ft_putstr(") y = ");
	ft_putnbr(p2->y);
	ft_putstr(" (");
	ft_putnbr(p2->y / par->y_scale);
	ft_putendl(")");
	draw_line(p1, p2, par, 0xFFFFFF);
	free(p1);
	free(p2);
	return (dist);
}

void	ft_angle(t_dist **d, double angle)
{
	// while (angle > 180)
	// 	angle = angle - 360;
	(*d)->a = angle;
	if ((*d)->a < 0)
	{
		(*d)->n = -1;
		(*d)->a = fabs((*d)->a);
	}
	else
		(*d)->n = 1;
}

int     ft_rays(t_param *par)
{
	t_player	*p;
	t_dist		*d;
	double     	dist;
	double		angle;

	if (!(p = ft_player_init(par)))
		return (0);
	d = ft_init_dist(p);
	if (!(d))
		return (0);
	// angle = p->v_angle - (FOV / 2);
	angle = p->v_angle;
	ft_angle(&d, angle);
	// while (angle <= p->v_angle + (FOV / 2))
	while (angle <= p->v_angle + (FOV / 2))
	{
		// ft_putstr("_______________\nangle = ");
		// printf("d->a angle = %f\n", d->n * d->a);
		// ft_putchar('\n');
		printf("_________\nangle = %f\n", angle);
		dist = ft_get_dist(p, d, par);
		if (dist > 1)
			ft_putendl("_______________");
		ft_angle(&d, angle);
		// if (d->a == 0 && d->n == -1)
		// 	d->n = 1;
		angle = angle + 1;
		// angle = angle + (1 / 10);
		ft_angle(&d, angle);
	}
	// exit (0);
	free(d);
	return (1);
}