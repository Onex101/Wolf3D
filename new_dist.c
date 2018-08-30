/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:52:46 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/30 07:16:34 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	ft_drawray(t_player *p, t_dda *l, double d, t_param *par)
{
	t_pnt	*p1;
	t_pnt	*p2;
	int		x2;
	int		y2;

	if (!(p1 = ft_pnt_init(p->pos->x, p->pos->y)))
		ft_exit(par);
	x2 = (((l->ray_dir->x) * d) + l->p->x) * par->x_scale;
	y2 = (((l->ray_dir->y) * d) + l->p->y) * par->y_scale;
	if (!(p2 = ft_pnt_init(x2, y2)))
		ft_exit(par);
	draw_ray(p1, p2, par, 0xFFFFFF);
	ft_pnt_free(p1);
	ft_pnt_free(p2);
}

void	ft_d_calc(t_dda *l, t_param *par, t_player *p, int col)
{
	double	perp_wall_dist;
	double	dist;
	double	x_diff;
	double	y_diff;

	x_diff = l->map->x - l->p->x;
	y_diff = l->map->y - l->p->y;
	if (l->side == 0)
		perp_wall_dist = (x_diff + (1 - l->step->x) / 2) / l->ray_dir->x;
	else
		perp_wall_dist = (y_diff + (1 - l->step->y) / 2) / l->ray_dir->y;
	if (par->scrn == 1)
		ft_drawray(p, l, perp_wall_dist, par);
	if (perp_wall_dist == 0)
		dist = 0;
	else
		dist = (int)(HEIGHT / perp_wall_dist);
	if (col < WIDTH && par->scrn == 0)
		draw_col(dist, col, par, l);
}

int		ft_distance(t_param *par, t_player *p, t_tables *t)
{
	t_dda	*l;
	double	cam_x;
	double	x;

	if (!(l = ft_dda_init(p, par, t)))
		return (0);
	x = 0;
	while (x < FOV && l->col++ < WIDTH)
	{
		cam_x = (2 * x) / (double)(FOV) - 1;
		if (!(ft_dda_assign(&l, par, cam_x)))
			return (0);
		ft_step_calc(&l);
		if (!(ft_dda(&l, par)))
			return (0);
		ft_d_calc(l, par, p, l->col);
		ft_dda_unassign(&l);
		x += 0.05;
	}
	ft_dda_free(l);
	return (1);
}

int		ft_rays(t_param *par, t_player *p)
{
	static t_tables		*t;

	if (!t)
		t = get_tables();
	if (!(ft_distance(par, p, t)))
		return (0);
	return (1);
}
