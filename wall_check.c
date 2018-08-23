/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:02:53 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/23 14:19:38 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

int			wall_block_check(t_vec3 *i, t_param *par)
{
	int		ret;
	void	*pos;
	void	*posx;
	void	*posy;

	pos = vector_get(par->map->ver_vec, i->x);
	posx = vector_get(par->map->ver_vec, i->y);
	posy = vector_get(par->map->ver_vec, i->z);
	if (((t_vec3 *)(pos))->z == 0)
		ret = 1;
	else if (((t_vec3 *)(posx))->z == 0 && ((t_vec3 *)(posy))->z != 0)
		ret = 2;
	else if (((t_vec3 *)(posx))->z != 0 && ((t_vec3 *)(posy))->z == 0)
		ret = 3;
	else
		ret = 0;
	return (ret);
}

int			wall_check(t_param *par, t_player *p, int x_inc, int y_inc)
{
	int		ret;
	t_vec3	*i;
	t_pnt	*arr;

	if (!(arr = ft_pnt_init(0, 0)))
		return (0);
	if (!(i = ft_vec3_init(0, 0, 0)))
		return (0);
	arr->x = (p->pos->x + x_inc) / par->x_scale;
	arr->y = (p->pos->y + y_inc) / par->y_scale;
	i->x = par->map->max_x * arr->y + arr->x;
	i->y = par->map->max_x * (p->pos->y / par->y_scale) + arr->x;
	i->z = par->map->max_x * arr->y + (p->pos->x / par->x_scale);
	ret = wall_block_check(i, par);
	ft_pnt_free(arr);
	ft_vec3_free(i);
	return (ret);
}

void		move_forward(t_param *p, double x_change, double y_change)
{
	int		wc;
	int		x_inc;
	int		y_inc;

	x_inc = x_change * p->player->spd;
	y_inc = y_change * p->player->spd;
	wc = wall_check(p, p->player, x_inc, y_inc);
	if (wc == 1)
	{
		p->player->pos->x += (int)(x_change * p->player->spd);
		p->player->pos->y += (int)(y_change * p->player->spd);
	}
	else if (wc == 2)
		p->player->pos->x += (int)(x_change * p->player->spd);
	else if (wc == 3)
		p->player->pos->y += (int)(y_change * p->player->spd);
}

void		move_back(t_param *p, double x_change, double y_change)
{
	int		wc;
	int		x_inc;
	int		y_inc;

	x_inc = -x_change * p->player->spd;
	y_inc = -y_change * p->player->spd;
	wc = wall_check(p, p->player, x_inc, y_inc);
	if (wc == 1)
	{
		p->player->pos->x -= (int)(x_change * p->player->spd);
		p->player->pos->y -= (int)(y_change * p->player->spd);
	}
	else if (wc == 2)
		p->player->pos->x -= (int)(x_change * p->player->spd);
	else if (wc == 3)
		p->player->pos->y -= (int)(y_change * p->player->spd);
}
