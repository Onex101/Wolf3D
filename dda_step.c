/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:54:06 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 11:13:24 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	ft_step_calc(t_dda **l)
{
	if ((*l)->ray_dir->x < 0)
	{
		(*l)->step->x = -1;
		(*l)->side_dist->x = ((*l)->p->x - (*l)->map->x);
		(*l)->side_dist->x = (*l)->side_dist->x * (*l)->delta_dist->x;
	}
	else
	{
		(*l)->side_dist->x = ((*l)->map->x + 1 - (*l)->p->x);
		(*l)->side_dist->x = (*l)->side_dist->x * (*l)->delta_dist->x;
	}
	if ((*l)->ray_dir->y < 0)
	{
		(*l)->step->y = -1;
		(*l)->side_dist->y = ((*l)->p->y - (*l)->map->y);
		(*l)->side_dist->y = (*l)->side_dist->y * (*l)->delta_dist->y;
	}
	else
	{
		(*l)->side_dist->y = ((*l)->map->y + 1 - (*l)->p->y);
		(*l)->side_dist->y = (*l)->side_dist->y * (*l)->delta_dist->y;
	}
}

int		ft_border(t_dda *l, t_param *par)
{
	double	a;
	double	b;

	a = (l->p->x + l->side_dist->x);
	b = (l->p->y + l->side_dist->y);
	if (l->map->x <= 0 && l->map->y <= 0)
		return (0);
	if (l->map->x >= par->map->max_x && l->map->y >= par->map->max_y)
		return (0);
	if (a * par->x_scale <= 0)
		return (0);
	if (b * par->y_scale <= 0)
		return (0);
	if (a * par->x_scale >= par->map->max_x * par->x_scale)
		return (0);
	if (b * par->y_scale <= par->map->max_y * par->y_scale)
		return (0);
	return (1);
}

int		ft_check_block(t_dda **l, t_param *par)
{
	int			v;

	v = ((par->map)->m[(*l)->map->y][(*l)->map->x] - '0');
	if (v > 0)
		(*l)->wall = 1;
	return (1);
}

int		ft_dda(t_dda **l, t_param *par)
{
	(*l)->wall = 0;
	while ((*l)->wall == 0)
	{
		if (((*l)->side_dist->x < (*l)->side_dist->y
			&& (*l)->delta_dist->x != 0) ||
			(*l)->delta_dist->y == 0)
		{
			(*l)->side_dist->x += (*l)->delta_dist->x;
			(*l)->map->x += (*l)->step->x;
			(*l)->side = 0;
		}
		else
		{
			(*l)->side_dist->y += (*l)->delta_dist->y;
			(*l)->map->y += (*l)->step->y;
			(*l)->side = 1;
		}
		if (!(ft_check_block(l, par)))
			return (0);
	}
	return (1);
}
