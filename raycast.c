/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/30 17:05:50 by xrhoda           ###   ########.fr       */
=======
/*   Updated: 2018/07/31 09:37:27 by shillebr         ###   ########.fr       */
>>>>>>> 6ede7e854fb8ab4a94ad5849c63e48c6172bbfdc
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

	while ((((t_vec3 *)(vector_get(par->map->ver_vec, (par->x_scale * inter->y + inter->x))))->z) == 0)
	{
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
	printf("Where at a x = %f and y = %f\n", a->x, a->y);
	return (a);
}

t_vec2	*ft_vert_check(t_player *p, t_tables *t, t_param *par, double theta)
{
	t_vec2	*a;
	t_pnt	*inter;
	int		ya;
	int		xa;

	// ft_putendl("v test1");
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

	while ((((t_vec3 *)(vector_get(par->map->ver_vec, (par->x_scale * inter->y + inter->x))))->z) == 0)
	{
		// ft_putendl("Entered vert loop");
		a->x = a->x + xa;
		inter->x = a->x / 64;
		a->y = a->y + ya;
		inter->y = a->y / 64;
		// printf("Vert Inter x = %d\ny = %d\n", inter->x, inter->y);
		if (inter->x < 0 || inter->x > par->x_scale || inter->y < 0 || inter->y > par->y_scale)
			return (NULL);
	}
	printf("Found vertical collision at x = %d and y = %d\n", inter->x, inter->y);
	printf("Where at a x = %f and y = %f\n", a->x, a->y);
	return (a);
}

double		ft_diff(t_player *p, double theta)
{
	if (p->v_angle >= theta)
		return (-1 * (p->v_angle - theta));
	else
		return (theta - p->v_angle);
}

double		ft_get_distance(t_player *p, double theta, t_param *par)
{
	t_tables	*t;
	t_vec2		*h_dist;
	t_vec2		*v_dist;
	t_pnt		*p1;
	t_pnt		*p2;
	double		distance;
	double		h_distance;
	double		v_distance;
	int			n;

	t = get_tables();
	n = 1;
	if (theta < 0)
		n = -1;
	theta = fabs(theta);
	if (!(p1 = ft_pnt_init(0, 0)) || !(p2 = ft_pnt_init(0, 0)))
		exit (0);
	p1->x = (p->pos).x;
	p1->y = (p->pos).y;
	if(!(h_dist = ft_vec2_init(0, 0)) && !(v_dist = ft_vec2_init(0, 0)))
		exit (0);
	v_distance = 0;
	h_distance = 0;
	if ((h_dist = ft_hori_check(p, t, par, n * theta)) != NULL)
	{
		// printf("before fisheye h dist x = %f, y = %f\n", h_dist->x, h_dist->y);
		h_distance = sqrt(((((p->pos).x - h_dist->x) * (p->pos).x - h_dist->x)) + (((p->pos).y - h_dist->y) * ((p->pos).y - h_dist->y)));
		// printf("horizontal distance = %f", h_distance);
	}
	if ((v_dist = ft_vert_check(p, t, par, n * theta)) != NULL)
	{
		// printf("before fisheye v dist x = %f, y = %f\n", v_dist->x, v_dist->y);
		v_distance = sqrt(((((p->pos).x - v_dist->x) * (p->pos).x - v_dist->x)) + (((p->pos).y - v_dist->y) * ((p->pos).y - v_dist->y)));
		// printf("vertical distance = %f\n", v_distance);
	}
	// ft_putendl("gd test3");
	//Now get the distance
	if (v_dist != NULL && h_dist != NULL)
	{
		// ft_putendl("v_dist and h_dist are valid");
		if (h_distance >= v_distance)
		{
			printf("h_dist x = %f, y = %f\n", h_dist->x, h_dist->y);
			p2->x = (int)h_dist->x;
			p2->y = (int)h_dist->y;
			distance = h_distance / (n * t->t_cos[a_ind(ft_diff(p, theta))]);
		}
		else
		{
			printf("v_dist x = %f, y = %f\n", v_dist->x, v_dist->y);
			p2->x = (int)v_dist->x;
			p2->y = (int)v_dist->y;
			distance = v_distance / (n * t->t_cos[a_ind(ft_diff(p, theta))]);
		}
	}
	else if (v_dist == NULL && h_dist != NULL)
	{
		// ft_putendl("h_dist is valid");
		p2->x = (int)h_dist->x;
		p2->y = (int)h_dist->y;
		distance = h_distance / (n * t->t_cos[a_ind(ft_diff(p, theta))]);
	}
	else if (v_dist != NULL && h_dist == NULL)
	{
		// ft_putendl("v_dist is valid");
		p2->x = (int)v_dist->x;
		p2->y = (int)v_dist->y;
		distance = v_distance / (n * t->t_cos[a_ind(ft_diff(p, theta))]);
	}
	else
	{
		ft_putendl("Exiting!");
		exit (0);
<<<<<<< HEAD
	}
	printf("p1 x = %d (%d)\np1 y = %d (%d)\np2 x = %d\np2 y = %d\n", p1->x, (p1->x / 64), p1->y, (p1->y / 64), p2->x, p2->y);
	ft_putendl("gd test4");
	draw_line(p1, p2, par, SQR_COL);
	ft_putendl("gd test4_1");
	distance = distance * t->t_cos[a_ind(theta)];
	ft_putendl("gd test5");
=======

	}
	printf("p1 x = %d (%d)\np1 y = %d (%d)\np2 x = %d (%d)\np2 y = %d (%d)\n", p1->x, (p1->x / 64), p1->y, (p1->y / 64), p2->x, (p2->x / 64), p2->y, (p2->y / 64));
	// ft_putendl("gd test4");
	p1->x = p1->x;
	p1->y = p1->y;
	p2->x = p2->x;
	p2->y = p2->y;
	draw_line(p1, p2, par, 0xFFFFFF);
	distance = distance * (n * t->t_cos[a_ind(theta)]);
	// distance = distance * t->t_cos[a_ind(theta)];
	// ft_putendl("gd test5");
>>>>>>> 6ede7e854fb8ab4a94ad5849c63e48c6172bbfdc
	return (distance);
}

void	ft_draw_player(t_player *p, t_param *par)
{
	t_pnt		*p1;

	if (!(p1 = ft_pnt_init((p->pos).x, (p->pos).y)))
		exit (0);
	draw_f_square(p1, par, 0xFFFF00);
	// draw_line(p1, p2, par, 0xFFFF00);
	free(p1);
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
	// ft_draw_player(p, par);
	// (p->pos).x = (p->pos).x / 2.55;
	// (p->pos).y = (p->pos).y / 2.55;
	ft_putendl("ray test2");
	while (angle <= (p->v_angle + (FOV / 2)))
	{
		distance = ft_get_distance(p, angle, par);
		printf("distance = %f for angle = %f\n", distance, angle);
		angle = angle + 0.166666667;
		printf("angle = %f\n", angle);
	}
	ft_putendl("ray test3");
	return (1);
}
