/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:52:46 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/22 20:42:21 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>

int		ft_dda_assign(t_dda **l, t_param *par, double cameraX)
{
	if (!par)
		return (0);
	if (!((*l)->rayDir = ft_rayDirVec((*l)->dir, (*l)->plane, cameraX)))
		return (0);
	if (!((*l)->map = ft_pnt_init(floor((*l)->p->x), floor((*l)->p->y))))
		return (0);
	if (!((*l)->step = ft_pnt_init(0, 0)))
		return (0);
	if (!((*l)->sideDist = ft_vec2_init(0, 0)))
		return (0);
	if (!((*l)->deltaDist = ft_init_deltaDist((*l)->rayDir)))
		return (0);
	printf("deltaDist x = %f y = %f\n", (*l)->deltaDist->x, (*l)->deltaDist->y);
	return (1);
}

void		ft_dda_unassign(t_dda **l)
{
	ft_vec2_free((*l)->rayDir);
	ft_pnt_free((*l)->map);
	ft_vec2_free((*l)->sideDist);
	ft_vec2_free((*l)->deltaDist);
}

void	ft_draw_ray(t_player *p, t_dda *l, double perpWallDist, t_param *par)
{
	t_pnt	*p1;
	t_pnt	*p2;
	int		x2;
	int		y2;

	if (!(p1 = ft_pnt_init(p->pos->x, p->pos->y)))
		exit (0);
	x2 = (((l->rayDir->x) * perpWallDist) + l->p->x) * par->x_scale;
	y2 = (((l->rayDir->y) * perpWallDist) + l->p->y) * par->y_scale;
	if (!(p2 = ft_pnt_init(x2, y2)))
		exit (0);
	printf("pnt1 x = %d y = %d    pnt2 x = %d y = %d\n", p1->x, p1->y, p2->x, p2->y);
	draw_ray(p1, p2, par, 0xFFFFFF);
	ft_pnt_free(p1);
	ft_pnt_free(p2);
}

void		ft_step_calc(t_dda **l)
{
	//Now calculate stepX, stepY, sideDistX and sideDistY
	if ((*l)->rayDir->x < 0)
	{
		printf("raydirx = %f < 0\n", (*l)->rayDir->x);
		(*l)->step->x = -1;
		(*l)->sideDist->x = ((*l)->p->x - (*l)->map->x) * (*l)->deltaDist->x;
		printf("sideDistX [%f] = p->posX [%f] - map->x [%d] * l->deltaDistX [%f]\n", (*l)->sideDist->x, (*l)->p->x, (*l)->map->x, (*l)->deltaDist->x);
	}
	else
	{
		printf("raydirx = %f >= 0\n", (*l)->rayDir->x);
		(*l)->step->x = 1;
		(*l)->sideDist->x = ((*l)->map->x + 1 - (*l)->p->x) * (*l)->deltaDist->x;
		printf("sideDistX [%f] = p->posX [%f] - map->x [%d] * l->deltaDistX [%f]\n", (*l)->sideDist->x, (*l)->p->x, (*l)->map->x, (*l)->deltaDist->x);
	}
	if ((*l)->rayDir->y < 0)
	{
		printf("raydirY = %f < 0\n", (*l)->rayDir->y);
		(*l)->step->y = -1;
		(*l)->sideDist->y = ((*l)->p->y - (*l)->map->y) * (*l)->deltaDist->y;
		printf("sideDistY [%f] = p->posY [%f] - mapY [%d] * l->deltaDistY [%f]\n", (*l)->sideDist->y, (*l)->p->y, (*l)->map->y, (*l)->deltaDist->y);
	}
	else
	{
		printf("raydirY = %f > 0\n", (*l)->rayDir->y);
		(*l)->step->y = 1;
		(*l)->sideDist->y = ((*l)->map->y + 1 - (*l)->p->y) * (*l)->deltaDist->y;
		printf("sideDistY [%f] = p->posY [%f] - mapY [%d] * l->deltaDistY [%f]\n", (*l)->sideDist->y, (*l)->p->y, (*l)->map->y, (*l)->deltaDist->y);
	}
}

int		ft_border(t_dda *l, t_param *par)
{
	if (l->map->x <= 0 && l->map->y <= 0)
		return (0);
	if (l->map->x >= par->map->max_x && l->map->y >= par->map->max_y)
		return (0);
	if ((l->p->x + l->sideDist->x) * par->x_scale <= 0)
		return (0);
	if ((l->p->y + l->sideDist->y) * par->y_scale <= 0)
		return (0);
	if ((l->p->x + l->sideDist->x) * par->x_scale >= par->map->max_x * par->x_scale)
		return (0);
	if ((l->p->y + l->sideDist->y) * par->y_scale <= par->map->max_y * par->y_scale)
		return (0);
	return (1);
}

int		ft_dda(t_dda **l, t_param *par)
{
	int		i;

	printf("start dda\n");
	//Perform DDA
	(*l)->wall = 0;
	// while ((*l)->wall == 0 && ft_border(*l, par))
	while ((*l)->wall == 0)
	{
		if ((*l)->sideDist->x < (*l)->sideDist->y)
		{
			(*l)->sideDist->x += (*l)->deltaDist->x;
			(*l)->map->x += (*l)->step->x;
			(*l)->side = 0;
		}
		else
		{
			(*l)->sideDist->y += (*l)->deltaDist->y;
			(*l)->map->y += (*l)->step->y;
			(*l)->side = 1;
		}
		printf("sideDistX [%f], sideDistY [%f]\n", (*l)->sideDist->x, (*l)->sideDist->y);
		printf("map x [%d], y [%d]\n", (*l)->map->x, (*l)->map->y);
		i = par->map->max_x * (*l)->map->y + (*l)->map->x;
		if (!((*l)->pos = vector_get(par->map->ver_vec, i)))
		{
			printf("Not valid square");
			return (0);
		}
		// printf("square = %f\n", ((t_vec3 *)((*l)->pos))->z);
		if ((((t_vec3 *)((*l)->pos))->z) > 0)
			(*l)->wall = 1;
	}
	printf("exit dda\n");
	return (1);
}

int		ft_distance(t_param *par, t_player *p, t_tables *t)
{
	t_dda	*l;
	double	cameraX;
	double	perpWallDist;
	int		x;
	double	dist;

	// printf("distance 1\n");
	if (!(l = ft_dda_init(p, par, t)))
		return (0);
	x = 0;
	// printf("distance 2\n");
	while (x < FOV)
	{
		printf("x = %d\n", x);
		cameraX = (2 * x) / (double)(FOV) - 1;
		printf("CameraX = %f\n", cameraX);	
		if (!(ft_dda_assign(&l, par, cameraX)))
			return (0);
		ft_step_calc(&l);
		if (!(ft_dda(&l, par)))
			return (0);
		//Calculate distance projected on camera direction
		if (l->side == 0)
			perpWallDist = (l->map->x - l->p->x + (1 - l->step->x) / 2) / l->rayDir->x;
		else
			perpWallDist = (l->map->y - l->p->y + (1 - l->step->y) / 2) / l->rayDir->y;
		printf("perpWallDist = %f\n", perpWallDist);
		ft_draw_ray(p, l, perpWallDist, par);
		dist = (int)( HEIGHT / perpWallDist);
		// draw_col(dist, x, par, 0xFFFF00);
		ft_dda_unassign(&l);
		x++;
	}
	printf("__________________________\n");
	return (1);
}

int     ft_rays(t_param *par, t_player *p)
{
	static t_tables		*t;

	if (!t)
		t = get_tables();
	printf("got to ray casting\n");
	if (!(ft_distance(par, p, t)))
		return (0);
	// if (d->wall == 1)
	// 	draw_col(dist, col, par, 0xFFFF00);
	// else if (d->wall == 2)
	// 	draw_col(dist, col, par, 0xFF00FF);
	// else if (d->wall == 3)
	// 	draw_col(dist, col, par, 0x00FFFF);
	// else if (d->wall == 4)
	// 	draw_col(dist, col, par, 0x5500FF);
	return (1);
}