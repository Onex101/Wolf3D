/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06:57:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/15 13:53:19 by xrhoda           ###   ########.fr       */
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
	//distance = dist * cos(((d->n * d->a) * M_PI) / 180 + 0.0001);
	p->hght = d->n;
	distance = dist;
	return (distance);
}

double  ft_get_dist(t_player *p, t_dist *d, t_param *par)
{
	double  dist;
	t_pnt	*p1;
	t_pnt	*p2;

	// ft_putendl("get dist test 1");
	if (!(p1 = ft_pnt_init(p->pos->x, p->pos->y)) || !(p2 = ft_pnt_init(0, 0)))
		exit (0);
	// ft_putendl("get dist test 2");
	if (!(ft_vert_check(p, &d, par)))
		d->v_dist = NULL;
	// ft_putendl("get dist test 3");
	if (!(ft_hori_check(p, &d, par)))
		d->h_dist = NULL;
	// ft_putendl("get dist test 4");
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
	draw_ray(p1, p2, par, 0xFFFFFF);
	ft_pnt_free(p1);
	ft_pnt_free(p2);
	// free(p1);
	// free(p2);
	return (dist);
}

void	ft_angle(t_dist **d, double angle)
{
	while (angle > 360 && angle > -360)
		angle -= 360;
	while (angle < -360 && angle < 360)
		angle += 360;
	(*d)->a = angle;
	if ((*d)->a < 0)
	{
		(*d)->n = -1;
		(*d)->a = fabs((*d)->a);
	}
	else
		(*d)->n = 1;
}

int     ft_rays(t_param *par, t_player *p)
{
	t_dist				*d;
	double  		   	dist;
	double				angle;
	static t_tables		*t;
	int					col;

	if (!t)
		t = get_tables();
	// ft_putendl("ray test 1");
	if (!(d = ft_init_dist(p, t)))
		return (0);
	// ft_putendl("ray test 1_1");
	angle = p->v_angle - (FOV / 2);
	// ft_putendl("ray test 1_2");
	ft_angle(&d, angle);
	// ft_putendl("ray test 1_3");
	col = 0;
	while (angle <= p->v_angle + (FOV / 2) && col < WIDTH)
	{
		// ft_putendl("ray test 1_4");
		dist = ft_get_dist(p, d, par);
		// ft_putendl("ray test 1_5");
		
		draw_col(dist, col, par, 0xFFFFFF);
		// ft_putendl("ray test 1_6");
		ft_angle(&d, angle);
		// ft_putendl("ray test 1_7");
		// angle = angle + 1;
		//printf("angle = [%f] | col = [%d]\n", angle, col);
		angle = angle + 0.05;
		ft_angle(&d, angle);
		col++;
	}
	// ft_putendl("ray test 2");
	ft_dist_free(d);
	// ft_putendl("ray test 3");
	// free(d);
	// exit (0);
	return (1);
}