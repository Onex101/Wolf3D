/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06:57:25 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/08 18:38:08 by shillebr         ###   ########.fr       */
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
	// printf("col->x  = %f xa = %f col->y  = %f ya = %f\n_________________\n", a->x, (*h)->xa, a->y, (*h)->ya);
	if (a->x < 0 || a->y < 0)
		return (NULL);
	(*h)->arr->x = (a->x + (*h)->hl) / par->x_scale;
	(*h)->arr->y = (a->y + (*h)->vu) / par->y_scale;
	if (!((*h)->pos = vector_get(par->map->ver_vec, (par->map->max_x * (*h)->arr->y + (*h)->arr->x))))
	{
		// ft_putendl("find wall vec get failed");
		return (NULL);
	}
	while ((((t_vec3 *)((*h)->pos))->z) == 0)
	{
		// printf("col x = %f (%f) xa = %f col->y = %f (%f) ya = %f\n", a->x, a->x / par->x_scale, (*h)->xa, a->y, a->y / par->y_scale, (*h)->ya);
		if ((*h)->arr->x == 0 || (*h)->arr->x == par->map->max_x || (*h)->arr->y == 0 || (*h)->arr->y == par->map->max_y)
			break ;
		a->x = a->x + (*h)->xa;
		(*h)->arr->x = (a->x + (*h)->hl) / par->x_scale;
		a->y = a->y + (*h)->ya;
		(*h)->arr->y = (a->y + (*h)->vu) / par->y_scale;
		if ((*h)->arr->x < 0 || (*h)->arr->x > par->map->max_x || (*h)->arr->y < 0 || (*h)->arr->y > par->map->max_y)
		{
			// ft_putendl("find wall out of range failed");
			return (NULL);
		}
		if (!((*h)->pos = vector_get(par->map->ver_vec, (par->map->max_x * (*h)->arr->y + (*h)->arr->x))))
		{
			// ft_putendl("find wall vec get failed");
			return (NULL);
		}
	}
	// printf("___________________\na x = %f (%f) y = %f (%f)\n_______________________\n", a->x, a->x / par->x_scale, a->y, a->y / par->y_scale);
	return (a);
}

int		ft_find_h_col(t_check **ret, t_player *p, t_dist **d, t_param *par)
{
	double	ang;

	(*ret)->col->y = (int)(p->pos.y / par->y_scale) * par->y_scale;
	if (ft_isup((*d)->n * (*d)->a))
		(*ret)->ya = -(par->y_scale);
	else if (ft_isdown((*d)->n * (*d)->a))
		(*ret)->ya = par->y_scale;
	else
		return (0);
	// ang = ((*d)->n * (*d)->t->t_tan[(int)a_ind((*d)->a)]);
	ang = ft_tan(d);
	// printf("At angle %f, tan = %f\n", (*d)->n * (*d)->a, ang);
	if (ang ==  0 || (*d)->a == 0 || (*d)->a == 180)
	{
		(*ret)->col->x = p->pos.x;
		(*ret)->xa = 0;
	}
	else
	{
		(*ret)->col->x = p->pos.x + (p->pos.y - (*ret)->col->y) / ang;
		(*ret)->xa = fabs((*ret)->ya) / ang;
	}
	return (1);
}

int		ft_hori_check(t_player *p, t_dist **d, t_param *par)
{
	t_check	*h;

	ft_putendl("hori check");
	if (!(h = ft_init_check()))
		return (0);
	if (!(h->col = ft_vec2_init(0, 0)) || !(h->arr = ft_pnt_init(0, 0)))
		return (0);
	if (!(ft_find_h_col(&h, p, d, par)))
	{
		// ft_putendl("h col failed");
		return (0);
	}
	if (h->ya < 0)
		h->vu = -1;
	h->arr->y = (h->col->y + h->vu) / par->y_scale;
	h->arr->x = h->col->x / par->x_scale;
	if (!((*d)->h_dist = ft_find_wall(&h, par)))
	{
		// ft_putendl("h find wall failed");
		return (0);
	}
	(*d)->h_distance = ft_dist_calc(p, (*d)->h_dist);
	// printf("h->distance = %f\n", (*d)->h_distance);
	free(h);
	return (1);
}

int		ft_find_v_col(t_check **ret, t_player *p, t_dist **d, t_param *par)
{
	double	ang;

	(*ret)->col->x = (int)(p->pos.x / par->x_scale) * par->x_scale;
	if (ft_isleft((*d)->n * (*d)->a))
		(*ret)->xa = -(par->x_scale);
	else if (ft_isright((*d)->n * (*d)->a))
		(*ret)->xa = par->x_scale;
	else
		return (0);
	// ang = ((*d)->n * (*d)->t->t_tan[(int)a_ind((*d)->a)]);
	ang = ft_tan(d);
	// printf("At angle %f, tan = %f\n", (*d)->n * (*d)->a, ang);
	// printf("At angle tan = %f\n", (*d)->t->t_tan[(int)1790]);
	if (ang ==  0 || (*d)->a == 90 || (*d)->a == 270)
	{
		(*ret)->col->y = p->pos.y;
		(*ret)->ya = 0;
	}
	else
	{
		// printf("n = %d\npos y (%f) + absolute(pox x(%f) - col x (%f)) * ang (%f)\n", (*d)->n, p->pos.y, p->pos.x, (*ret)->col->x, ang);
		(*ret)->col->y = p->pos.y + (fabs(p->pos.x - (*ret)->col->x) * ang);
		(*ret)->ya = abs(par->y_scale) * ang;
	}
	// printf("Vert col->x  = %f xa = %f col->y  = %f ya = %f\n_________________\n", (*ret)->col->x, (*ret)->xa, (*ret)->col->y, (*ret)->ya);
	return (1);
}

int		ft_vert_check(t_player *p, t_dist **d, t_param *par)
{
	t_check	*h;

	// ft_putendl("vert check");
	if (!(h = ft_init_check()))
		return (0);
	if (!(h->col = ft_vec2_init(0, 0)) || !(h->arr = ft_pnt_init(0, 0)))
		return (0);
	if (!(ft_find_v_col(&h, p, d, par)))
	{
		// ft_putendl("v col failed");
		return (0);
	}
	if (h->xa < 0)
		h->hl = -1;
	// printf("hl = %d\n", h->hl);
	h->arr->y = (h->col->y + h->hl) / par->y_scale;
	h->arr->x = h->col->x / par->x_scale;
	if (!((*d)->v_dist = ft_find_wall(&h, par)))
	{
		// ft_putendl("v find wall failed");
		return (0);
	}
	(*d)->v_distance = ft_dist_calc(p, (*d)->v_dist);
	// printf("v->distance = %f\n", (*d)->v_distance);
	free(h);
	return (1);
}