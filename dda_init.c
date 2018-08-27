/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:27:01 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/27 10:14:24 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

t_vec2	*ft_dir_vec(t_player *p, t_tables *t)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = t->t_cos[p->v_angle * 10];
		new->y = t->t_sin[p->v_angle * 10];
		return (new);
	}
	return (NULL);
}

t_vec2	*ft_plane_vec(t_player *p, t_tables *t)
{
	t_vec2	*new;
	double	c;
	double	s;
	double	x;
	double	y;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		if (!p)
			return (NULL);
		x = 0;
		y = (1 / sqrt(3));
		c = t->t_cos[p->v_angle * 10];
		s = t->t_sin[p->v_angle * 10];
		new->x = (x * c) + (y * (-s));
		new->y = (x * s) + (y * c);
		return (new);
	}
	return (NULL);
}

t_vec2	*ft_ray_dir_vec(t_vec2 *dir, t_vec2 *plane, double cam_x)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = dir->x + plane->x * cam_x;
		new->y = dir->y + plane->y * cam_x;
		return (new);
	}
	return (NULL);
}

t_dda	*ft_dda_init(t_player *p, t_param *par, t_tables *t)
{
	t_dda	*new;

	if (!(new = (t_dda *)malloc(sizeof(t_dda))))
		return (NULL);
	if (!(new->p = ft_vec2_init(0, (p->pos->y / par->y_scale))))
		return (NULL);
	new->p->x = (p->pos->x / par->x_scale);
	if (!(new->dir = ft_dir_vec(p, t)))
		return (NULL);
	if (!(new->plane = ft_plane_vec(p, t)))
		return (NULL);
	new->ray_dir = NULL;
	new->side_dist = NULL;
	new->delta_dist = NULL;
	new->map = NULL;
	new->step = NULL;
	new->wall = 0;
	new->side = 0;
	new->col = 0;
	new->pos = NULL;
	return (new);
}

t_vec2	*ft_init_delta_dist(t_vec2 *ray_dir)
{
	t_vec2	*delta_dist;
	double	x;
	double	y;

	x = (ray_dir->x * ray_dir->x);
	y = (ray_dir->y * ray_dir->y);
	if (!(delta_dist = ft_vec2_init(0, 0)))
		return (NULL);
	if (ray_dir->x == 0)
		delta_dist->x = 0;
	else
		delta_dist->x = sqrt(1 + y / x);
	if (ray_dir->y == 0)
		delta_dist->y = 0;
	else
		delta_dist->y = sqrt(1 + x / y);
	return (delta_dist);
}
