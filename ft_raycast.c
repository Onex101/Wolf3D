/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06:57:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/20 13:51:41 by shillebr         ###   ########.fr       */
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

double  ft_dist(t_player *p, t_pnt **p2, t_dist **d, int x)
{
	double  distance;

	if (x == 1)
	{
		if ((*d)->n * (*d)->a > 127 && (*d)->n * (*d)->a < 129)
			printf("v_dis: x = %f, y = %f\n", (*d)->v_dist->x, (*d)->v_dist->y);
		(*p2)->x = floor((*d)->v_dist->x);
		(*p2)->y = floor((*d)->v_dist->y);
		distance = (*d)->v_distance;
		(*d)->wall = (*d)->v_wall;
	}
	else
	{
		if ((*d)->n * (*d)->a > 127 && (*d)->n * (*d)->a < 129)
			printf("h_dis: x = %f, y = %f\n", (*d)->h_dist->x, (*d)->h_dist->y);
		(*p2)->x = floor((*d)->h_dist->x);
		(*p2)->y = floor((*d)->h_dist->y);
		distance = (*d)->h_distance;
		(*d)->wall = (*d)->h_wall;
	}
	p->hght = (*d)->n;
	
	return (distance);
}

double  ft_get_dist(t_player *p, t_dist *d, t_param *par)
{
	double  dist;
	t_pnt	*p1;
	t_pnt	*p2;

	if (!(p1 = ft_pnt_init(p->pos->x, p->pos->y)) || !(p2 = ft_pnt_init(0, 0)))
		exit (0);
	if (!(ft_vert_check(p, &d, par)))
		d->v_dist = NULL;
	if (!(ft_hori_check(p, &d, par)))
		d->h_dist = NULL;
	//
	if (d->v_dist != NULL && d->h_dist != NULL)
	{
		if (d->h_distance <= d->v_distance)
			dist = ft_dist(p, &p2, &d, 2);
		else
			dist = ft_dist(p, &p2, &d, 1);
	}
	else if (d->v_dist == NULL && d->h_dist != NULL)
		dist = ft_dist(p, &p2, &d, 2);
	else if (d->v_dist != NULL && d->h_dist == NULL)
		dist = ft_dist(p, &p2, &d, 1);
	else
		exit (0);
	//
	if (d->n * d->a > 127 && d->n * d->a < 129)
	{
		printf("Distance = [%f]\n", dist);
		printf("Angle = [%f], p2: x = %d, y = %d\n", d->n * d->a, p2->x, p2->y);
	}
	// printf("new point: x = %d, y = %d\n", p2->x, p2->y);
	draw_ray(p1, p2, par, 0xFFFFFF);
	ft_pnt_free(p1);
	ft_pnt_free(p2);
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
	if (!(d = ft_init_dist(p, t)))
		return (0);
	angle = p->v_angle - (FOV / 2);
	ft_angle(&d, angle);
	col = 0;
	while (angle <= p->v_angle + (FOV / 2) && col < WIDTH)
	{
		// if (angle > 134 && angle < 136)
		if (angle > 127 && angle < 129)
		{
			printf("_________________\n");
			printf("Angle = [%f]\n", angle);
		}
		dist = ft_get_dist(p, d, par);
		// if (angle > 134 && angle < 136)
		if (angle > 127 && angle < 129)
			printf("Wall = %d\n", d->wall);
		// draw_col(dist, col, par, 0xFFFFFF);
		// printf("Wall = %d\n", d->wall);
		if (d->wall == 1)
			draw_col(dist, col, par, 0xFFFF00);
		else if (d->wall == 2)
			draw_col(dist, col, par, 0xFF00FF);
		else if (d->wall == 3)
			draw_col(dist, col, par, 0x00FFFF);
		else if (d->wall == 4)
			draw_col(dist, col, par, 0x5500FF);
		// angle = angle + 0.05;
		angle = angle + 0.1;
		ft_angle(&d, angle);
		col++;
	}
	ft_dist_free(d);
	return (1);
}