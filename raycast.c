/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/30 14:34:50 by shillebr         ###   ########.fr       */
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
	{
		ft_putendl("Hori check failed to init");
		return (NULL);
	}
	if (ft_isup(theta))
	{
		a->y = (int)(p->pos.y / 64) * (64) - 1;
		ya = -64;
	}
	else if (ft_isdown(theta))
	{
		a->y = (int)(p->pos.y / 64) * 64 + 64;
		ya = 64;
	}
	inter->y = a->y / 64;
	a->x = p->pos.x + (p->pos.y - a->y) / t->t_tan[FOV];
	inter->x = a->x / 64;
	xa = 64 / t->t_tan[FOV]; //xa = 36;

	while ((((t_vec3 *)(vector_get(par->map->ver_vec, (par->x_scale * inter->y + inter->x))))->z) != 0)
	{
		ft_putendl("enter horizontal loop)");
		a->x = a->x + xa;
		inter->x = a->x / 64;
		a->y = a->y + ya;
		inter->y = a->y / 64;
		if (inter->x < 0 || inter->x > par->x_scale || inter->y < 0 || inter->y > par->y_scale)
		{
			ft_putendl("Hori went out of range");
			ft_putstr("inter->x = ");
			ft_putnbr(inter->x);
			ft_putendl("");
			ft_putstr("inter->y = ");
			ft_putnbr(inter->y);
			ft_putendl("");
			return (NULL);
		}
	}
	printf("Found horizontal collision at x = %d and y = %d\n", inter->x, inter->y);
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
		a->x = (int)(p->pos.x / 64) * (64) + 64;
		xa = 64;
	}
	else if (ft_isleft(theta))
	{
		a->x = (int)(p->pos.x / 64) * 64 - 1;
		xa = -64;
	}
	inter->x = a->x / 64;
	a->y = p->pos.y + (p->pos.x - a->x) / t->t_tan[FOV];
	inter->y = a->y / 64;
	ya = 64 / t->t_tan[FOV]; //ya = 36;

	while ((((t_vec3 *)(vector_get(par->map->ver_vec, (par->x_scale * inter->y + inter->x))))->z) != 0)
	{
		ft_putendl("Entered vert loop");
		a->x = a->x + xa;
		inter->x = a->x / 64;
		a->y = a->y + ya;
		inter->y = a->y / 64;
		printf("Vert Inter x = %d\ny = %d\n", inter->x, inter->y);
		if (inter->x < 0 || inter->x > par->x_scale || inter->y < 0 || inter->y > par->y_scale)
			return (NULL);
	}
	printf("Found vertical collision at x = %d and y = %d\n", inter->x, inter->y);
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

	ft_putendl("gd test1");
	t = get_tables();
	if (!(p1 = ft_pnt_init(0, 0)) || !(p2 = ft_pnt_init(0, 0)))
		exit (0);
	p1->x = (p->pos).x;
	p1->y = (p->pos).y;
	ft_putendl("gd test2");
	if(!(h_dist = ft_vec2_init(0, 0)) && !(v_dist = ft_vec2_init(0, 0)))
		exit (0);
	if ((h_dist = ft_hori_check(p, t, par, theta)) != NULL)
	{
		ft_putendl("h_dist valid");
		h_dist->x = fabs((p->pos).x - h_dist->x / t->t_cos[a_ind(theta)]);
		h_dist->y = fabs((p->pos).y - h_dist->y) / t->t_sin[a_ind(theta)];
	}
	if ((v_dist = ft_vert_check(p, t, par, theta)) != NULL)
	{
		ft_putendl("v_dist valid");
		v_dist->x = fabs((p->pos).x - v_dist->x / t->t_cos[a_ind(theta)]);
		v_dist->y = fabs((p->pos).y - v_dist->y) / t->t_sin[a_ind(theta)];
	}
	ft_putendl("gd test3");
	//Now get the distance
	if (v_dist != NULL && h_dist != NULL)
	{
		ft_putendl("v_dist and h_dist are valid");
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
		ft_putendl("h_dist is valid");
		p2->x = (int)h_dist->x;
		p2->y = (int)h_dist->y;
		distance = fabs((p->pos).x - h_dist->x) / t->t_cos[a_ind(theta)];
	}
	else if (v_dist == NULL && h_dist != NULL)
	{
		ft_putendl("v_dist is valid");
		p2->x = (int)v_dist->x;
		p2->y = (int)v_dist->y;
		distance = fabs((p->pos).y - v_dist->y) / t->t_sin[a_ind(theta)];
	}
	else
	{
		ft_putendl("Exiting!");
		exit (0);
	}
	printf("p1 x = %d (%d)\np1 y = %d (%d)\np2 x = %d\np2 y = %d\n", p1->x, (p1->x / 64), p1->y, (p1->y / 64), p2->x, p2->y);
	ft_putendl("gd test4");
	draw_line(p1, p2, par, SQR_COL);
	ft_putendl("gd test4_1");
	distance = distance * t->t_cos[a_ind(theta)];
	ft_putendl("gd test5");
	return (distance);
}

int		ft_rays(t_param *par)
{
	t_player	*p;
	double		angle;
	double		distance;
	ft_putendl("ray test1");
	if (!(p = ft_player_init()))
		return (0);
	angle = p->v_angle - (FOV / 2);
	ft_putendl("ray test2");
	while (angle <= (p->v_angle + (FOV / 2)))
	{
		distance = ft_get_distance(p, angle, par);
		printf("distance = %f for angle = %f\n", distance, angle);
		angle = angle + (1 / 6);
	}
	ft_putendl("ray test3");
	return (1);
}