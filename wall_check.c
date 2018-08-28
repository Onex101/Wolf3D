/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:02:53 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 10:06:49 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

int			wall_block_check(t_param *par, t_player *p, t_pnt *arr)
{
	int		ret;
	int		pos;
	int		posx;
	int		posy;

	if (arr->x < 0 || arr->x > par->map->max_x)
		return (0);
	if (arr->y < 0 || arr->y > par->map->max_y)
		return (0);
	pos = (par->map)->m[arr->y][arr->x];
	posy = (par->map)->m[arr->y][(int)(p->pos->x / par->x_scale)];
	posx = (par->map)->m[(int)(p->pos->y / par->y_scale)][arr->x];
	if (pos == '0')
		ret = 1;
	else if (posx == '0' && posy != '0')
		ret = 2;
	else if (posx != '0' && posy == '0')
		ret = 3;
	else
		ret = 0;
	return (ret);
}

int			wall_check(t_param *par, t_player *p, int x_inc, int y_inc)
{
	int		ret;
	t_pnt	*arr;

	if (!(arr = ft_pnt_init(0, 0)))
		return (0);
	arr->x = (p->pos->x + x_inc) / par->x_scale;
	arr->y = (p->pos->y + y_inc) / par->y_scale;
	ret = wall_block_check(par, p, arr);
	ft_pnt_free(arr);
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
