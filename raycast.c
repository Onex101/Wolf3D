/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/25 13:51:02 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_horizontal_check(t_player *p)
{
	t_vec2	*a;
	t_pnt	*inter;
	int		ya;
	int		xa;

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
	a->x = p->pos.x + (p->pos.y - a->y) / tan(FOV);
	inter->x = a->x / 64;
	xa = 64 / tan(FOV); //xa = 36;

	while (grid(inter->y)(inter->x) != 'X')
	{
		ax = ax + xa;
		inter->x = ax / 64;
		ay = ay + ya;
		inter->y = ay / 64;
		if (inter->x < 0 || inter->x >= WIDTH || inter->y < 0 || inter->y >= HEIGHT);
			exit (0);
	}
}

int		ft_vertical_check(t_player *p)
{
	int		ya;
	int		xa;
	int		inter_x;
	int		inter_y;

	if (ft_isright(theta))
		ay = (p->pos.y/64) * (64) - 1;
	else if (ft_isleft(theta))
		ay = (p->pos.y / 64) * 64 + 64;
	inter_y = ay / 64;
	ax = p->pos.x + (p->pos.y - ay) / tan(FOV);
	inter_x = ax / 64;

	//Find Xa
	if (ft_isright(theta))
		xa = 64;
	else if (ft_isleft(theta))
		xa = -64;
	ya = 64 / tan(FOV); //ya = 36;

	while (grid(inter_y)(inter_x) != 'X')
	{
		ax = ax + xa;
		inter_x = ax / 64;
		ay = ay + ya;
		inter_y = ay / 64;
		if (inter_x < 0 || inter_x >= WIDTH || inter_y < 0 || inter_y >= HEIGHT);
			exit (0);
	}
}

double		ft_get_distance(t_player *p, double theta)
{
	t_tables	*t;
	t_vec2		*h_dist;
	t_vec2		*v_dist;

	t = get_tables();
	if(!(h_dist = ft_vec2_init(0, 0)) && !(v_dist = ft_vec2_init(0, 0)))
		exit (0);
	if ((h_dist = ft_horizontal_check) != NULL)
	{
		h_dist->x = ft_abs(p->x - h_dist->x / cos(beta));
		h_dist->y = ft_abs(p->y - h_dist->y) / sin(beta);
	}
	if ((v_dist = ft_vertical_check) != NULL)
	{
		v_dist->x = ft_abs(p->x - v_dist->x / cos(beta));
		v_dist->y = ft_abs(p->y - v_dist->y) / sin(beta);
	}
	if (v_dist != NULL && h_dist != NULL)
	{
		if ((ft_abs(p->x - h_x) / cos(beta)) >= (ft_abs(p->y - v_y) / sin(beta)))
			distance = ft_abs(p->x - h_dist->x) / cos(beta);
		else
			distance = ft_abs(p->y - v_dist->y) / sin(beta);
	}
	else if (v_dist == NULL && h_dist != NULL)
		distance = ft_abs(p->x - h_dist->x) / cos(beta);
	else if (v_dist == NULL && h_dist != NULL)
		distance = ft_abs(p->y - v_dist->y) / sin(beta);
	else
		exit (0);
	distance = distance * cos(theta)
	return (distance);
}
//distance needs to be calculate, check fish eye code already made
//return t_point for where the wall occurs, use tpoint in the declarations