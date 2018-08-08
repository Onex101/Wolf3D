/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/06 14:01:19 by shillebr         ###   ########.fr       */
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
	void	*pos;
	int		n;

	if (!(a = ft_vec2_init(0, 0)) || !(inter = ft_pnt_init(0, 0)))
		return (NULL);
	n = 1;
	if (theta < 0)
	{
		n = -1;
		theta = fabs(theta);
	}
	if (ft_isup(n * theta))
	{
		// ft_putendl("is up");
		a->y = (int)(p->pos.y / par->y_scale) * par->y_scale - 1;
		ya = -(par->y_scale);
	}
	else if (ft_isdown(n * theta))
	{
		a->y = (int)(p->pos.y / par->y_scale) * par->y_scale + par->y_scale;
		ya = par->y_scale;
	}
	else
		return (NULL);
	inter->y = a->y / par->y_scale;
	if ( (n * t->t_tan[(int)a_ind(theta)]) == 0)
		a->x = 0;
	else
		a->x = p->pos.x + (p->pos.y - a->y) / (n * t->t_tan[(int)a_ind(theta)]);
	inter->x = a->x / par->x_scale;
	xa = par->x_scale / (n * (t->t_tan[(int)a_ind(theta)]));
	if (!(pos = vector_get(par->map->ver_vec, (par->map->max_x * inter->y + inter->x))))
		return (NULL);
	while ((((t_vec3 *)(pos))->z) == 0)
	{
		if (inter->x == 0 || inter->x == par->map->max_x || inter->y == 0 || inter->y == par->map->max_y)
			break ;
		a->x = a->x + xa;
		inter->x = a->x / par->x_scale;
		a->y = a->y + ya;
		inter->y = a->y / par->y_scale;
		if (inter->x < 0 || inter->x >= par->map->max_x + 1 || inter->y < 0 || inter->y >= par->map->max_y + 1)
		{
			ft_putendl("h went out");
			printf("Hori Inter x = %d\ny = %d\n", inter->x, inter->y);
			return (NULL);
		}
	}
	return (a);
}

t_vec2	*ft_vert_check(t_player *p, t_tables *t, t_param *par, double theta)
{
	t_vec2	*a;
	t_pnt	*inter;
	int		ya;
	int		xa;
	void	*pos;
	int		n;

	// ft_putendl("v test1");
	if (!(a = ft_vec2_init(0, 0)) || !(inter = ft_pnt_init(0, 0)))
		return (NULL);
	// ft_putendl("v test2");
	n = 1;
	if (theta < 0)
	{
		n = -1;
		theta = fabs(theta);
	}
	if (ft_isright(n * theta))
	{
		// ft_putendl("is right");
		a->x = (int)(p->pos.x / par->x_scale) * (par->x_scale) + par->x_scale;
		xa = par->x_scale;
	}
	else if (ft_isleft(n * theta))
	{
		// ft_putendl("is right");
		a->x = (int)(p->pos.x / par->x_scale) * par->x_scale - 1;
		xa = -(par->x_scale);
	}
	else
	{
		ft_putendl("not left or right");
		return (NULL);
	}
	// printf("par->x_scale = %d\n", par->x_scale);
	// printf("xa = %d\n", xa);
	// printf("theta = %f\n", t->t_tan[(int)a_ind(theta)]);
	// ft_putendl("v test3");
	inter->x = a->x / par->x_scale;
	// printf("theta = %f\n", t->t_tan[(int)a_ind(theta)]);
	if ( (n * t->t_tan[(int)a_ind(theta)]) == 0)
		a->y = 0;
	else
		a->y = p->pos.y + (p->pos.x - a->x) / (n * t->t_tan[(int)a_ind(theta)]);
	inter->y = a->y / par->y_scale;
	ya = par->y_scale * (n * (t->t_tan[(int)a_ind(theta)]));
	// ft_putstr("xa = ");
	// ft_putnbr(xa);
	// ft_putendl("");
	// ft_putstr("ya = ");
	// ft_putnbr(ya);
	// ft_putendl("");

	// ft_putendl("v test4");
	ft_putstr("inter y = ");
	ft_putnbr(inter->y);
	ft_putendl("");
	ft_putstr("inter x = ");
	ft_putnbr(inter->x);
	ft_putendl("");
	if (!(pos = vector_get(par->map->ver_vec, (par->map->max_x * inter->y + inter->x))))
	{
		ft_putendl("failed vector get");
		return (NULL);
	}
	// ft_putendl("v test5");
	while ((((t_vec3 *)(pos))->z) == 0)
	{
		if (inter->x == 0 || inter->x == par->map->max_x || inter->y == 0 || inter->y == par->map->max_y)
			break ;
		a->x = a->x + xa;
		inter->x = a->x / par->x_scale;
		a->y = a->y + ya;
		inter->y = a->y / par->y_scale;
		// printf("Vert Inter x = %d\ny = %d\n", inter->x, inter->y);
		if (inter->x < 0 || inter->x >= par->x_scale + 1 || inter->y < 0 || inter->y >= par->y_scale + 1)
		{
			ft_putendl("v went out");
			printf("Vert Inter x = %d\ny = %d\n", inter->x, inter->y);
			return (NULL);
		}
	}
	// printf("Found vertical collision at x = %d and y = %d\n", inter->x, inter->y);
	// printf("Where at a x = %f and y = %f\n", a->x, a->y);
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
	// ft_putendl("gd test1");
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
		// ft_putendl("gd test2");
		printf("h dist x = %f, y = %f\n", h_dist->x / par->x_scale, h_dist->y / par->y_scale);
		h_distance = sqrt(((((p->pos).x - h_dist->x) * (p->pos).x - h_dist->x)) + (((p->pos).y - h_dist->y) * ((p->pos).y - h_dist->y)));
		// printf("horizontal distance = %f\n", h_distance);
	}
	if ((v_dist = ft_vert_check(p, t, par, n * theta)) != NULL)
	{
		printf("v dist x = %f, y = %f\n", v_dist->x / par->x_scale, v_dist->y / par->y_scale);
		v_distance = sqrt(((((p->pos).x - v_dist->x) * (p->pos).x - v_dist->x)) + (((p->pos).y - v_dist->y) * ((p->pos).y - v_dist->y)));
		// printf("vertical distance = %f\n", v_distance);
	}
	// return (1);


	// ft_putendl("gd test3");
	//Now get the distance
	if (v_dist != NULL && h_dist != NULL)
	{
		ft_putendl("v_dist and h_dist are valid");
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
		ft_putendl("h_dist is valid");
		p2->x = (int)h_dist->x;
		p2->y = (int)h_dist->y;
		distance = h_distance / (n * t->t_cos[a_ind(ft_diff(p, theta))]);
	}
	else if (v_dist != NULL && h_dist == NULL)
	{
		ft_putendl("v_dist is valid");
		p2->x = (int)v_dist->x;
		p2->y = (int)v_dist->y;
		distance = v_distance / (n * t->t_cos[a_ind(ft_diff(p, theta))]);
	}
	else
	{
		ft_putendl("Exiting!");
		exit (0);
	}
	// printf("p1 x = %d (%d)\np1 y = %d (%d)\np2 x = %d (%d)\np2 y = %d (%d)\n", p1->x, (p1->x / 64), p1->y, (p1->y / 64), p2->x, (p2->x / 64), p2->y, (p2->y / 64));
	// ft_putendl("gd test4");
	draw_line(p1, p2, par, 0xFFFFFF);
	// distance = distance * (n * t->t_cos[a_ind(theta)]);
	distance = distance * t->t_cos[a_ind(theta)];
	// ft_putendl("gd test5");
	return (distance);
}

int		ft_rays(t_param *par)
{
	t_player	*p;
	double		angle;
	double		distance;
	// ft_putendl("ray test1");
	if (!(p = ft_player_init(par)))
		return (0);
	angle = p->v_angle - (FOV / 2);
	// ft_putendl("ray test2");

	while (angle <= (p->v_angle + (FOV / 2)))
	{
		// ft_putendl("ray test2_1");
		printf("Angle: %f\n", angle);
		distance = ft_get_distance(p, angle, par);
		// ft_putendl("ray test2_2");
		// printf("distance = %f for angle = %f\n", distance, angle);
		// printf("Iterations: %f\n", (1 /(ANGLE_360 / 360)));
		// angle = angle + 0.166666667;
		
		angle++;
		// angle = angle + (1 /(ANGLE_360 / 360));

		// printf("angle = %f\n", angle);
		if (distance != 0)
			ft_putendl("____________________________");
	}
	exit (0);
	// ft_putendl("ray test3");
	return (1);
}