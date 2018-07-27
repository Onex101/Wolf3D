/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/27 19:01:21 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec2	*ft_horizontal_check(t_player *p, t_tables *t, t_param *p)
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
		ya = -64
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

	while ((par->map)[inter_y][inter_x] != '0')
	{
		a->x = a->x + xa;
		inter->x = a->x / 64;
		a->y = a->y + ya;
		inter->y = a->y / 64;
		if (inter->x < 0 || inter->x >= WIDTH || inter->y < 0 || inter->y >= HEIGHT);
			return (NULL);
	}
	return (a);
}

t_vec2	*ft_vertical_check(t_player *p, t_tables *t, , t_param *par)
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
	inter_y = a->y / 64;
	a->x = p->pos.x + (p->pos.y - a->y) / t->t_tan[FOV];
	inter_x = a->x / 64;
	ya = 64 / t->t_tan[FOV]; //ya = 36;

	while ((par->map)[inter_y][inter_x] != '0')
	{
		a->x = a->x + xa;
		inter_x = a->x / 64;
		a->y = a->y + ya;
		inter_y = a->y / 64;
		if (inter_x < 0 || inter_x >= WIDTH || inter_y < 0 || inter_y >= HEIGHT);
			return (NULL);
	}
	return (inter);
}

double		ft_get_distance(t_player *p, double theta, t_param *par)
{
	t_tables	*t;
	t_vec2		*h_dist;
	t_vec2		*v_dist;
	t_pnt		*p1;
	t_pnt		*p2;

	t = get_tables();
	if (!(p1 = ft_pnt_init(0, 0)) || !(p2 = ft_pnt_init(0, 0)))
		exit (0);
	if(!(h_dist = ft_vec2_init(0, 0)) && !(v_dist = ft_vec2_init(0, 0)))
		exit (0);
	if ((h_dist = ft_horizontal_check(p, t, par)) != NULL)
	{
		h_dist->x = ft_abs(p->x - h_dist->x / t->t_cos[theta]);
		h_dist->y = ft_abs(p->y - h_dist->y) / t->t_sin[theta];
	}
	if ((v_dist = ft_vertical_check(p, t, par)) != NULL)
	{
		v_dist->x = ft_abs(p->x - v_dist->x / t->t_cos[theta]);
		v_dist->y = ft_abs(p->y - v_dist->y) / t->t_sin[theta];
	}
	if (v_dist != NULL && h_dist != NULL)
	{
		if ((ft_abs(p->x - h_x) / t->t_cos[theta]) >= (ft_abs(p->y - v_y) / t->t_sin[theta]))
		{
			p2->x = (int)
			distance = ft_abs(p->x - h_dist->x) / t->t_cos[theta];
		}
		else
		{
			distance = ft_abs(p->y - v_dist->y) / t->t_sin[theta];
		}
	}
	else if (v_dist == NULL && h_dist != NULL)
	{
		distance = ft_abs(p->x - h_dist->x) / t->t_cos[theta];
	}
	else if (v_dist == NULL && h_dist != NULL)
	{
		draw_line((int)p->x *)
		distance = ft_abs(p->y - v_dist->y) / t->t_sin[theta];
	}
	else
		exit (0);
	distance = distance * t->t_cos[theta];
	return (distance);
}

int		ft_rays(t_param *par)
{
	t_player	*p;
	double		angle;
	double		distance;

	if (!(p = ft_player_init()));
		return (0);
	angle = p->v_angle - (FOV / 2);

	while (anlge <= (p->v_angle + (FOV / 2)))
	{
		distance = ft_get_distance(p, angle, par);
		printf("distance = %f for angle = %f\n", distance, angle);
		angle = angle + (1 / 6);
	}
	return (1);
}
//distance needs to be calculate, check fish eye code already made
//return t_point for where the wall occurs, use tpoint in the declarations