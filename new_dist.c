/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:52:46 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/22 16:04:11 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>

t_vec2	*ft_dirVec(t_player *p, t_vec2 *ply, t_tables *t)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		if (!ply)
			return (NULL);
		// new->x = t->t_cos[p->v_angle * 10] + ply->x;
		// new->y = t->t_sin[p->v_angle * 10] + ply->y;
		new->x = t->t_cos[p->v_angle * 10];
		new->y = t->t_sin[p->v_angle * 10];
		printf("Dir x = %f y = %f\n", new->x, new->y);
		return (new);
	}
	return (NULL);
}

t_vec2	*ft_planeVec(t_vec2 *p, t_vec2 *dir)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		if (!p)
			return (NULL);
		// new->x = dir->x + (1 / sqrt(3)) * (-(p->y - dir->y));
		// new->y = dir->y + (1 / sqrt(3)) * (-(p->x - dir->x));
		new->x = dir->x + (1 / sqrt(3)) * (-(0 - dir->y));
		new->y = dir->y + (1 / sqrt(3)) * (-(0 - dir->x));
		//
		new->x = new->x - dir->x;
		new->y = new->y - dir->y;
		
		printf("Plane x = %f y = %f\n", new->x, new->y);
		return (new);
	}
	return (NULL);
}

t_vec2	*ft_rayDirVec(t_vec2 *dir, t_vec2 *plane, double cameraX)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = dir->x + plane->x * cameraX;
		new->y = dir->y + plane->y * cameraX;
		printf("RayDir x = %f y = %f\n", new->x, new->y);
		return (new);
	}
	return (NULL);
}

t_dda	*ft_dda_init(t_player *p, t_param *par, t_tables *t)
{
	t_dda	*new;

	new = NULL;
	if ((new = (t_dda *)malloc(sizeof(t_dda))))
	{
		if (!(new->p = ft_vec2_init((p->pos->x / par->x_scale), (p->pos->y / par->y_scale))))
			return (NULL);
		printf("player pos x = %f y = %f\n", new->p->x, new->p->y);
		if (!(new->dir = ft_dirVec(p, new->p, t)))
			return (NULL);
		if (!(new->plane = ft_planeVec(new->p, new->dir)))
			return (NULL);
		new->rayDir = NULL;
		new->sideDist = NULL;
		new->deltaDist = NULL;
		new->map = NULL;
		new->step = NULL;
		new->wall = 0;
		new->side = 0;
		new->pos = NULL;
		return (new);
	}
	return (NULL);
}

t_vec2	*ft_init_deltaDist(t_vec2 *rayDir)
{
	t_vec2	*deltaDist;

	if (!(deltaDist = ft_vec2_init(0, 0)))
			return (NULL);
	if (rayDir->x == 0)
		deltaDist->x = 0;
	else
		deltaDist->x = sqrt(1 + (rayDir->y * rayDir->y) / (rayDir->x * rayDir->x));
	if (rayDir->y == 0)
		deltaDist->y = 0;
	else
		deltaDist->y = sqrt(1 +  (rayDir->x * rayDir->x)/ (rayDir->y * rayDir->y));
	return (deltaDist);
}

int		ft_dda_assign(t_dda **l, t_param *par, double cameraX)
{
	if (!par)
		return (0);
	if (!((*l)->rayDir = ft_rayDirVec((*l)->dir, (*l)->plane, cameraX)))
		return (0);
	// if (!((*l)->map = ft_pnt_init(floor(p->pos->x / par->x_scale), floor(p->pos->y / par->y_scale))))
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

void	ft_draw_ray(t_player *p, t_pnt *map, t_param *par)
{
	t_pnt	*p1;
	t_pnt	*p2;

	if (!(p1 = ft_pnt_init(p->pos->x, p->pos->y)) || !(p2 = ft_pnt_init(map->x * par->x_scale, map->y * par->y_scale)))
		exit (0);
	draw_ray(p1, p2, par, 0xFFFFFF);
	ft_pnt_free(p1);
	ft_pnt_free(p2);
}

int		ft_distance(t_param *par, t_player *p, t_tables *t)
{	
	// double	t; //time
	// double	ot; //old_time
	t_dda	*l;
	double	cameraX;
	double	perpWallDist;
	int		x;
	int		i;
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
		//Now calculate stepX, stepY, sideDistX and sideDistY
		if (l->rayDir->x < 0)
		{
			printf("raydirx = %f < 0\n", l->rayDir->x);
			l->step->x = -1;
			l->sideDist->x = (l->p->x - l->map->x) * l->deltaDist->x;
			printf("sideDistX [%f] = p->posX [%f] - map->x [%d] * l->deltaDistX [%f]\n", l->sideDist->x, l->p->x, l->map->x, l->deltaDist->x);
		}
		else
		{
			printf("raydirx = %f >= 0\n", l->rayDir->x);
			l->step->x = 1;
			l->sideDist->x = (l->map->x + 1 - l->p->x) * l->deltaDist->x;
			printf("sideDistX [%f] = p->posX [%f] - map->x [%d] * l->deltaDistX [%f]\n", l->sideDist->x, l->p->x, l->map->x, l->deltaDist->x);
		}
		if (l->rayDir->y < 0)
		{
			printf("raydirY = %f < 0\n", l->rayDir->y);
			l->step->y = -1;
			l->sideDist->y = (l->p->y - l->map->y) * l->deltaDist->y;
			printf("sideDistY [%f] = p->posY [%f] - mapY [%d] * l->deltaDistY [%f]\n", l->sideDist->y, l->p->y, l->map->y, l->deltaDist->y);
		}
		else
		{
			printf("raydirY = %f > 0\n", l->rayDir->y);
			l->step->y = 1;
			l->sideDist->y = (l->map->y + 1 - l->p->y) * l->deltaDist->y;
			printf("sideDistY [%f] = p->posY [%f] - mapY [%d] * l->deltaDistY [%f]\n", l->sideDist->y, l->p->y, l->map->y, l->deltaDist->y);
		}
		//Perform DDA
		l->wall = 0;
		while (l->wall == 0)
		{
			if (l->sideDist->x < l->sideDist->y)
			{
				l->sideDist->x += l->deltaDist->x;
				l->map->x += l->step->x;
				l->side = 0;
			}
			else
			{
				l->sideDist->y += l->deltaDist->y;
				l->map->y += l->step->y;
				l->side = 1;
			}
			printf("sideDistX [%f], sideDistY [%f]\n", l->sideDist->x, l->sideDist->y);
			printf("map x [%d], y [%d]\n", l->map->x, l->map->y);
			i = par->map->max_x * l->map->y + l->map->x;
			if (!(l->pos = vector_get(par->map->ver_vec, i)))
			{
				printf("Not valid square");
				return (0);
			}
			printf("square = %f\n", ((t_vec3 *)(l->pos))->z);
			if ((((t_vec3 *)(l->pos))->z) > 0)
				l->wall = 1;
		}
		ft_draw_ray(p, l->map, par);
		//Calculate distance projected on camera direction
		if (l->side == 0)
			perpWallDist = (l->map->x - l->p->x + (1 - l->step->x) / 2) / l->rayDir->x;
		else
			perpWallDist = (l->map->y - l->p->y + (1 - l->step->y) / 2) / l->rayDir->y;
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