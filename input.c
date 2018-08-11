/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:40:54 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/08 08:58:44 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <math.h>
#include <stdio.h>

int		key_press(int keycode, t_param *p)
{
	double		x_change;
	double		y_change;
	static t_tables	*tab;

	if (!tab)
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
	if (keycode == 13)
	{
		p->player->pos->x += (int)(x_change * p->player->spd) / 2;
		p->player->pos->y += (int)(y_change * p->player->spd) / 2;
	}
	else if (keycode == 1)
	{
		p->player->pos->x -= (int)(x_change * p->player->spd) / 2;
		p->player->pos->y -= (int)(y_change * p->player->spd) / 2;
	}
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	//printf("player x = [%f] player y = [%f] player v_angle = [%d]", p->player->x, p->player->y, p->player->v_angle);
	ft_putstr("player x = ");
	ft_putnbr(p->player->pos->x);
	ft_putstr(" player y = ");
	ft_putnbr(p->player->pos->y);
	ft_putstr(" player v_angle = ");
	ft_putnbr(p->player->v_angle);
	ft_putendl("");
	return (0);
}