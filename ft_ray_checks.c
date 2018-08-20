/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 06:57:25 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/20 11:15:32 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>

double     ft_db_mod(double a, double b)
{
    double  mod;
    int     dv;

    dv = (int)(a / b);
    mod = a - ((double)dv * b);
    return (mod);
}

int		ft_corner(t_check **h, t_param *par, t_vec2 *a)
{
	void	*s1;
	void	*s2;
	int		i1;
	int		i2;

	if ((*h)->xa >= 0)
		i1 = par->map->max_x * (*h)->arr->y + ((*h)->arr->x - 1);
	else
		i1 = par->map->max_x * (*h)->arr->y + ((*h)->arr->x + 1);
	if ((*h)->ya >= 0)
		i2 = par->map->max_x * ((*h)->arr->y - 1) + ((*h)->arr->x);
	else
		i2 = par->map->max_x * ((*h)->arr->y + 1) + (*h)->arr->x;
	s1 = vector_get(par->map->ver_vec, i1);
	s2 = vector_get(par->map->ver_vec, i2);
	if (ft_db_mod(a->x, par->x_scale) == 0 && ft_db_mod(a->y, par->y_scale) == 0)
	{
		if ((((t_vec3 *)((*h)->pos))->z) != 0)
			return (1);
		else if (((t_vec3 *)s1)->z != 0 && ((t_vec3 *)s2)->z != 0)
			return (1);
	}
	return (0);
}

int		ft_wall_check(t_check **h, t_param *par, t_vec2 *a)
{
	int		i;

	if (a->x == 0 || a->x == par->map->max_x * (par->x_scale + 1) - 1) //find border
		return (1);
	else if (a->y == 0 || a->y == par->map->max_y * (par->y_scale + 1) - 1)
		return (1);
	if (a->x < 0 || a->x >= par->map->max_x * (par->x_scale + 1))
		return (0);
	else if (a->y < 0 || a->y >= par->map->max_y * (par->y_scale + 1))
		return (0);
	(*h)->arr->x = floor(a->x) / par->x_scale;
	(*h)->arr->y = floor(a->y) / par->y_scale;
	
	// if ((*h)->arr->x < 0 || (*h)->arr->x > par->map->max_x)
	// 	return (0);
	// else if ((*h)->arr->y < 0 || (*h)->arr->y > par->map->max_y)
	// 	return (0);
	i = par->map->max_x * (*h)->arr->y + (*h)->arr->x;
	if (!((*h)->pos = vector_get(par->map->ver_vec, i)))
		return (0);
	if ((((t_vec3 *)((*h)->pos))->z) != 0)
		return (1);
	if (ft_corner(h, par, a))
		return (1);
	
	return (2);
}

t_vec2		*ft_find_wall(t_check **h, t_param *par)
{
	t_vec2	*a;
	int		i;

	if (!(a = ft_vec2_init((*h)->col->x, (*h)->col->y)))
		return (NULL);
	if (a->x < 0 || a->y < 0)
		return (NULL);
	if (!((*h)->pos = vector_get(par->map->ver_vec, (par->map->max_x * (*h)->arr->y + (*h)->arr->x))))
		return (NULL);
	printf("h = %f\n", (((t_vec3 *)((*h)->pos))->z));
	while ((((t_vec3 *)((*h)->pos))->z) == 0)
	{
		a->x = a->x + (*h)->xa;
		a->y = a->y + (*h)->ya;
		// printf("h = %f\n", (((t_vec3 *)((*h)->pos))->z));
		i = ft_wall_check(h, par, a);
		printf("h = %f\n", (((t_vec3 *)((*h)->pos))->z));
		if (i == 1)
		{
			printf("Found wall at x = %f, y = %f\n", a->x, a->y);
			break ;
		}
		else if (i == 0)
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
		(*d)->h_wall = 2;
	}
	else if (ft_isdown((*d)->n * (*d)->a))
	{
		(*ret)->ya = -par->y_scale;
		(*ret)->col->y = (int)(p->pos->y / par->y_scale) * par->y_scale - 1;
		(*d)->h_wall = 4;
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
	if ((*d)->n * (*d)->a > 127 && (*d)->n * (*d)->a < 129)
	{
		printf("hori: x = %f, y = %f\n", (*d)->h_dist->x, (*d)->h_dist->y);
		printf("arr: x = %d, y = %d\n", h->arr->x, h->arr->y);
	}
	(*d)->h_distance = ft_dist_calc(p, (*d)->h_dist, (*d)->n * (*d)->a);
	ft_check_free(h);
	return (1);
}

int		ft_find_v_col(t_check **ret, t_player *p, t_dist **d, t_param *par)
{
	double	ang;

	if (ft_isleft((*d)->n * (*d)->a))
	{
		(*ret)->xa = -(par->x_scale);
		(*ret)->col->x = (int)(p->pos->x / par->x_scale) * par->x_scale - 1;
		(*d)->v_wall = 1;
	}
	else if (ft_isright((*d)->n * (*d)->a))
	{
		(*ret)->xa = par->x_scale;
		(*ret)->col->x = (int)(p->pos->x / par->x_scale) * par->x_scale + par->x_scale;
		(*d)->v_wall = 3;
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
	h->arr->y = (h->col->y) / par->y_scale;
	h->arr->x = h->col->x / par->x_scale;
	if (!((*d)->v_dist = ft_find_wall(&h, par)))
		return (0);
	if ((*d)->n * (*d)->a > 127 && (*d)->n * (*d)->a < 129)
	{
		printf("vert: x = %f, y = %f\n", (*d)->v_dist->x, (*d)->v_dist->y);
		printf("arr: x = %d, y = %d\n", h->arr->x, h->arr->y);
	}
	(*d)->v_distance = ft_dist_calc(p, (*d)->v_dist, (*d)->n * (*d)->a);
	// printf("check_before 4\n");
	ft_check_free(h);
	// printf("check_before 5\n");
	return (1);
}