/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_assign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 09:49:11 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 13:56:00 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

int		ft_dda_assign(t_dda **l, t_param *par, double cam_x)
{
	if (!par)
		return (0);
	if (!((*l)->ray_dir = ft_ray_dir_vec((*l)->dir, (*l)->plane, cam_x)))
		return (0);
	if (!((*l)->map = ft_pnt_init(floor((*l)->p->x), floor((*l)->p->y))))
		return (0);
	if (!((*l)->step = ft_pnt_init(1, 1)))
		return (0);
	if (!((*l)->side_dist = ft_vec2_init(0, 0)))
		return (0);
	if (!((*l)->delta_dist = ft_init_delta_dist((*l)->ray_dir)))
		return (0);
	return (1);
}

void	ft_dda_unassign(t_dda **l)
{
	ft_vec2_free((*l)->ray_dir);
	ft_pnt_free((*l)->map);
	ft_pnt_free((*l)->step);
	ft_vec2_free((*l)->side_dist);
	ft_vec2_free((*l)->delta_dist);
}
