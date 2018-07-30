/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/30 10:06:33 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>

t_vec2	*ft_hori_check(t_player *p, t_tables *t, t_param *par, double theta)
{
	t_vec2	*a;
	t_pnt	*inter;
	int		ya;
	int		xa;

	if (!(a = ft_vec2_init(0, 0)) || !(inter = ft_pnt_init(0, 0)))
		return (NULL);
	if (ft_isup(theta))
	{
		a->y = (p->pos.y/64) * (64) - 1;
		ya = -64;
	}
	else if (ft_isdown(theta))
	{
		a->y = (p->pos.y / 64) * 64 + 64;
		ya = 64;
	}
	inter->y = a->y / 64;
	a->x = p->pos.x + (p->pos.y - a->y) / t->t_tan[FOV];
	inter->x = a->x / 64;
	xa = 64 / t->t_tan[FOV]; //xa = 36;

	while ((((t_vec3 *)(vector_get(par->map->ver_vec, (par->x_scale * inter->y + inter->x))))->z) != 0)
	{
		a->x = a->x + xa;
		inter->x = a->x / 64;
		a->y = a->y + ya;
		inter->y = a->y / 64;
		if (inter->x < 0 || inter->x >= WIDTH || inter->y < 0 || inter->y >= HEIGHT)
			return (NULL);
	}
	return (a);
}

t_vec2	*ft_vert_check(t_player *p, t_tables *t, t_param *par, double theta)
{
	t_vec2	*a;
	t_pnt	*inter;
	int		ya;
	int		xa;

	if (!(a = ft_vec2_init(0, 0)) || !(inter = ft_pnt_init(0, 0)))
		return (NULL);
	if (ft_isright(theta))
	{
		a->y = (p->pos.y/64) * (64) - 1;
		xa = 64;
	}
	else if (ft_isleft(theta))
	{
		a->y = (p->pos.y / 64) * 64 + 64;
		xa = -64;
	}
	inter->y = a->y / 64;
	a->x = p->pos.x + (p->pos.y - a->y) / t->t_tan[FOV];
	inter->x = a->x / 64;
	ya = 64 / t->t_tan[FOV]; //ya = 36;

	while ((((t_vec3 *)(vector_get(par->map->ver_vec, (par->x_scale * inter->y + inter->x))))->z) != 0)
	{
		a->x = a->x + xa;
		inter->x = a->x / 64;
		a->y = a->y + ya;
		inter->y = a->y / 64;
		if (inter->x < 0 || inter->x >= WIDTH || inter->y < 0 || inter->y >= HEIGHT)
			return (NULL);
	}
	return (a);
}

double		ft_get_distance(t_player *p, double theta, t_param *par)
{
	t_tables	*t;
	t_vec2		*h_dist;
	t_vec2		*v_dist;
	t_pnt		*p1;
	t_pnt		*p2;
	double		distance;

	t = get_tables();
	if (!(p1 = ft_pnt_init(0, 0)) || !(p2 = ft_pnt_init(0, 0)))
		exit (0);
	p1->x = (p->pos).x;
	p1->y = (p->pos).y;
	if(!(h_dist = ft_vec2_init(0, 0)) && !(v_dist = ft_vec2_init(0, 0)))
		exit (0);
	if ((h_dist = ft_hori_check(p, t, par, theta)) != NULL)
	{
		h_dist->x = fabs((p->pos).x - h_dist->x / t->t_cos[a_ind(theta)]);
		h_dist->y = fabs((p->pos).y - h_dist->y) / t->t_sin[a_ind(theta)];
	}
	if ((v_dist = ft_vert_check(p, t, par, theta)) != NULL)
	{
		v_dist->x = fabs((p->pos).x - v_dist->x / t->t_cos[a_ind(theta)]);
		v_dist->y = fabs((p->pos).y - v_dist->y) / t->t_sin[a_ind(theta)];
	}
	//Now get the distance
	if (v_dist != NULL && h_dist != NULL)
	{
		if ((fabs((p->pos).x - h_dist->x) / t->t_cos[a_ind(theta)]) >= (fabs((p->pos).y - v_dist->y) / t->t_sin[a_ind(theta)]))
		{
			p2->x = (int)h_dist->x;
			p2->y = (int)h_dist->y;
			distance = fabs((p->pos).x - h_dist->x) / t->t_cos[a_ind(theta)];
		}
		else
		{
			p2->x = (int)v_dist->x;
			p2->y = (int)v_dist->y;
			distance = fabs((p->pos).y - v_dist->y) / t->t_sin[a_ind(theta)];
		}
	}
	else if (v_dist == NULL && h_dist != NULL)
	{
		p2->x = (int)h_dist->x;
		p2->y = (int)h_dist->y;
		distance = fabs((p->pos).x - h_dist->x) / t->t_cos[a_ind(theta)];
	}
	else if (v_dist == NULL && h_dist != NULL)
	{
		p2->x = (int)v_dist->x;
		p2->y = (int)v_dist->y;
		distance = fabs((p->pos).y - v_dist->y) / t->t_sin[a_ind(theta)];
	}
	else
		exit (0);
	draw_line(p1, p2, par, WALL_COL);
	distance = distance * t->t_cos[a_ind(theta)];
	return (distance);
}

int		ft_rays(t_param *par)
{
	t_player	*p;
	double		angle;
	double		distance;

	if (!(p = ft_player_init()))
		return (0);
	angle = p->v_angle - (FOV / 2);

	while (angle <= (p->v_angle + (FOV / 2)))
	{
		distance = ft_get_distance(p, angle, par);
		printf("distance = %f for angle = %f\n", distance, angle);
		angle = angle + (1 / 6);
	}
	return (1);
}