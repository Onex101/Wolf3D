/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:40:54 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/31 09:37:13 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <math.h>

int		key_hook(int keycode, t_param *p)
{
	double		x_change;
	double		y_change;
	t_tables	*tab;

	tab = get_tables();
	if (keycode == 0) //ROTATE LEFT
	{
		if ((p->player->v_angle -= ANGLE_10) < ANGLE_0)
			p->player->v_angle += ANGLE_360;
	}
	else if (keycode == 2) //ROTATE RIGHT
	{
		if ((p->player->v_angle += ANGLE_10) >= ANGLE_360)
			p->player->v_angle -= ANGLE_360;
	}
	x_change = tab->t_cos[p->player->v_angle];
	y_change = tab->t_sin[p->player->v_angle];
	if (keycode == 13) //FORWARD
	{
		p->player->pos.x += (int)(x_change * p->player->spd);
		p->player->pos.y += (int)(y_change * p->player->spd);
	}
	else if (keycode == 1) //BACK
	{
		p->player->pos.x -= (int)(x_change * p->player->spd);
		p->player->pos.y -= (int)(y_change * p->player->spd);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	return (0);
}
