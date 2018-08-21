/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:52:46 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/21 14:02:14 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>

t_vec2	*ft_dirVec(t_player *p, t_param *par, t_tables *t)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = par->x_scale * t->t_cos[p->v_angle] + p->pos->x;
		new->y = par->y_scale * t->t_sin[p->v_angle] + p->pos->y;
		return (new);
	}
	return (NULL);
}

t_vec2	*ft_planeVec(t_player *p, t_vec2 *dir)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = dir->x + (1 / sqrt(3)) * (-(p->pos->y - dir->y));
		new->y = dir->y + (1 / sqrt(3)) * (-(p->pos->x - dir->x));
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
		if (!(new->dir = ft_dirVec(p, par, t)))
			return (NULL);
		if (!(new->plane = ft_planeVec(p, new->dir)))
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

int		ft_dda_assign(t_dda **l, t_player *p, double cameraX)
{
	if (!((*l)->rayDir = ft_rayDirVec((*l)->dir, (*l)->plane, cameraX)))
		return (0);
	// if (!(map = ft_pnt_init(floor(p->pos->x / x_scale), floor(p->pos->y / y_scale))))
	if (!((*l)->map = ft_pnt_init(floor(p->pos->x), floor(p->pos->y))))
		return (0);
	if (!((*l)->sideDist = ft_vec2_init(0, 0)))
		return (0);
	if (!((*l)->deltaDist = ft_vec2_init(fabs(1 / (*l)->rayDir->x), fabs(1 / (*l)->rayDir->y))))
		return (0);
	return (1);
}

void		ft_dda_unassign(t_dda **l)
{
	ft_vec2_free((*l)->rayDir);
	ft_pnt_free((*l)->map);
	ft_vec2_free((*l)->sideDist);
	ft_vec2_free((*l)->deltaDist);
}

int		ft_distance(t_param *par, t_player *p, t_tables *t)
{
	//posX and Y are in player->pos
	
	// double	t; //time
	// double	ot; //old_time
	t_dda	*l;
	double	cameraX;
	double	perpWallDist;
	int		x;
	int		i;
	double	dist;
	// int		hit; //was wall hit? h->pos
	// int		side; //which wall was hit h->wall

	printf("distance 1\n");
	if (!(l = ft_dda_init(p, par, t)))
		return (0);
	x = 0;
	printf("distance 2\n");
	while (x < FOV)
	{
		printf("distance 2_1\n");
		cameraX = 2 * x / FOV - 1;	
		if (!(ft_dda_assign(&l, p, cameraX)))
			return (0);	
		printf("distance 2_2\n");
		//Now calculate stepX, stepY, sideDistX and sideDistY
		if (l->rayDir->x < 0)
		{
			l->step->x = -1;
			l->sideDist->x = (p->pos->x - l->map->x) * l->deltaDist->x;
		}
		else
		{
			l->step->x = 1;
			l->sideDist->x = (l->map->x + 1 - p->pos->x) * l->deltaDist->x;
		}
		printf("distance 2_3\n");
		if (l->rayDir->y < 0)
		{
			l->step->y = -1;
			l->sideDist->x = (p->pos->y - l->map->y) * l->deltaDist->y;
		}
		else
		{
			l->step->y = 1;
			l->sideDist->y = (l->map->y + 1 - p->pos->y) * l->deltaDist->y;
		}
		printf("distance 3\n");
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
			i = par->map->max_x * l->map->y + l->map->x;
			if (!(l->pos = vector_get(par->map->ver_vec, i)))
				return (0);
			if ((((t_vec3 *)(l->pos))->z) > 0)
				l->wall = 1;
		}
		printf("distance 4\n");
		//Calculate distance projected on camera direction
		if (l->side == 0)
			perpWallDist = (l->map->x - p->pos->x + (1 - l->step->x) / 2) / l->rayDir->x;
		else
			perpWallDist = (l->map->y - p->pos->y + (1 - l->step->y) / 2) / l->rayDir->y;
		printf("distance 5\n");
		dist = (int)( HEIGHT / perpWallDist);
		draw_col(dist, x, par, 0xFFFF00);
		printf("distance 6\n");
		ft_dda_unassign(&l);
		printf("distance 7\n");
		x++;
	}
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