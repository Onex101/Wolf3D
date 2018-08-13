/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06:57:25 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/13 08:31:51 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>

t_vec2		*ft_find_wall(t_check **h, t_param *par)
{
	t_vec2	*a;

	if (!(a = ft_vec2_init((*h)->col->x, (*h)->col->y)))
		return (NULL);
	if (a->x < 0 || a->y < 0)
		return (NULL);
	if (!((*h)->pos = vector_get(par->map->ver_vec, (par->map->max_x * (*h)->arr->y + (*h)->arr->x))))
		return (NULL);
	while ((((t_vec3 *)((*h)->pos))->z) == 0)
	{
		if ((*h)->arr->x == 0 || (*h)->arr->x == par->map->max_x || (*h)->arr->y == 0 || (*h)->arr->y == par->map->max_y)
			break ;
		a->x = a->x + (*h)->xa;
		(*h)->arr->x = (a->x ) / par->x_scale;
		a->y = a->y + (*h)->ya;
		(*h)->arr->y = (a->y) / par->y_scale;
		if ((*h)->arr->x < 0 || (*h)->arr->x > par->map->max_x || (*h)->arr->y < 0 || (*h)->arr->y > par->map->max_y)
			return (NULL);
		if (!((*h)->pos = vector_get(par->map->ver_vec, (par->map->max_x * (*h)->arr->y + (*h)->arr->x))))
			return (NULL);
	}
	return (a);
}

int		ft_find_h_col(t_check **ret, t_player *p, t_dist **d, t_param *par)
{
	double	ang;

	if (ft_isup((*d)->n * (*d)->a))
	{
		(*ret)->ya = (par->y_scale);
		(*ret)->col->y = (int)(p->pos->y / par->y_scale) * par->y_scale + par->y_scale;
	}
	else if (ft_isdown((*d)->n * (*d)->a))
	{
		(*ret)->ya = -par->y_scale;
		(*ret)->col->y = (int)(p->pos->y / par->y_scale) * par->y_scale - 1;
	}
	else
		return (0);
	ang = ft_tan(d);
	if (ang ==  0 || (*d)->a == 0 || (*d)->a == 180)
	{
		(*ret)->col->x = p->pos->x;
		(*ret)->xa = 0;
	}
	else
	{
		(*ret)->col->x = p->pos->x + ((*ret)->col->y - p->pos->y) / ang;
		(*ret)->xa = (*ret)->ya / ang;
	}
	return (1);
}

int		ft_hori_check(t_player *p, t_dist **d, t_param *par)
{
	t_check	*h;

	if (!(h = ft_init_check()))
		return (0);
	if (!(h->col = ft_vec2_init(0, 0)) || !(h->arr = ft_pnt_init(0, 0)))
		return (0);
	if (!(ft_find_h_col(&h, p, d, par)))
		return (0);
	h->arr->y = (h->col->y) / par->y_scale;
	h->arr->x = h->col->x / par->x_scale;
	if (!((*d)->h_dist = ft_find_wall(&h, par)))
		return (0);
	(*d)->h_distance = ft_dist_calc(p, (*d)->h_dist);
	ft_check_free(h);
	// free(h);
	return (1);
}

int		ft_find_v_col(t_check **ret, t_player *p, t_dist **d, t_param *par)
{
	double	ang;

	if (ft_isleft((*d)->n * (*d)->a))
	{
		(*ret)->xa = -(par->x_scale);
		(*ret)->col->x = (int)(p->pos->x / par->x_scale) * par->x_scale - 1;
	}
	else if (ft_isright((*d)->n * (*d)->a))
	{
		(*ret)->xa = par->x_scale;
		(*ret)->col->x = (int)(p->pos->x / par->x_scale) * par->x_scale + par->x_scale;
	}
	else
		return (0);
	ang = ft_tan(d);
	if (ang ==  0 || (*d)->a == 90 || (*d)->a == 270)
	{
		(*ret)->col->y = p->pos->y;
		(*ret)->ya = 0;
	}
	else
	{
		(*ret)->col->y = p->pos->y + ((*ret)->col->x - p->pos->x) * ang;
		(*ret)->ya = (*ret)->xa * ang;
	}
	return (1);
}

int		ft_vert_check(t_player *p, t_dist **d, t_param *par)
{
	t_check	*h;

	if (!(h = ft_init_check()))
		return (0);
	if (!(h->col = ft_vec2_init(0, 0)) || !(h->arr = ft_pnt_init(0, 0)))
		return (0);
	if (!(ft_find_v_col(&h, p, d, par)))
		return (0);
	if (h->xa < 0)
		h->hl = -1;
	h->arr->y = (h->col->y) / par->y_scale;
	h->arr->x = h->col->x / par->x_scale;
	if (!((*d)->v_dist = ft_find_wall(&h, par)))
		return (0);
	(*d)->v_distance = ft_dist_calc(p, (*d)->v_dist);
	ft_check_free(h);
	// free(h);
	return (1);
}