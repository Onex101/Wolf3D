/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:27:01 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/22 17:27:45 by shillebr         ###   ########.fr       */
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