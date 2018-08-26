/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_assign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:49:11 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/23 09:58:10 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <stdio.h>

int		ft_dda_assign(t_dda **l, t_param *par, double cam_x)
{
	if (!par)
		return (0);
	if (!((*l)->ray_dir = ft_ray_dir_vec((*l)->dir, (*l)->plane, cam_x)))
		return (0);
	printf("raydir x = %f y = %f\n", (*l)->ray_dir->x, (*l)->ray_dir->y);
	if (!((*l)->map = ft_pnt_init(floor((*l)->p->x), floor((*l)->p->y))))
		return (0);
	printf("map x = %d y = %d\n", (*l)->map->x, (*l)->map->y);
	if (!((*l)->step = ft_pnt_init(1, 1)))
		return (0);
	printf("step x = %d y = %d\n", (*l)->step->x, (*l)->step->y);
	if (!((*l)->side_dist = ft_vec2_init(0, 0)))
		return (0);
	if (!((*l)->delta_dist = ft_init_delta_dist((*l)->ray_dir)))
		return (0);
	printf("delta dist x = %f y = %f\n", (*l)->delta_dist->x, (*l)->delta_dist->y);
	return (1);
}

void	ft_dda_unassign(t_dda **l)
{
	ft_vec2_free((*l)->ray_dir);
	ft_pnt_free((*l)->map);
	ft_vec2_free((*l)->side_dist);
	ft_vec2_free((*l)->delta_dist);
}
