/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:40:54 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/30 08:10:22 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	mac_rotate(int keycode, t_param *p)
{
	if (keycode == 0 || keycode == 123)
	{
		if ((p->player->v_angle -= 5) < 0)
			p->player->v_angle += 360;
	}
	else if (keycode == 2 || keycode == 124)
	{
		if ((p->player->v_angle += 5) >= 360)
			p->player->v_angle -= 360;
	}
}

void	mac_key_press(int keycode, t_param *p)
{
	double			x_change;
	double			y_change;
	static t_tables	*tab;

	if (!tab)
		tab = get_tables();
	mac_rotate(keycode, p);
	x_change = cos_d(p->player->v_angle - 15);
	y_change = sin_d(p->player->v_angle - 15);
	if (keycode == 13 || keycode == 126)
		move_forward(p, x_change, y_change);
	else if (keycode == 1 || keycode == 125)
		move_back(p, x_change, y_change);
	if (keycode == 48)
		p->scrn = p->scrn == 0 ? 1 : 0;
	if (keycode == 53)
		ft_exit(p);
}

void	linux_rotate(int keycode, t_param *p)
{
	if (keycode == 97)
	{
		if ((p->player->v_angle -= 5) < 0)
			p->player->v_angle += 360;
	}
	else if (keycode == 100)
	{
		if ((p->player->v_angle += 5) >= 360)
			p->player->v_angle -= 360;
	}
}

void	linux_key_press(int keycode, t_param *p)
{
	double			x_change;
	double			y_change;
	static t_tables	*tab;

	if (!tab)
		tab = get_tables();
	linux_rotate(keycode, p);
	x_change = cos_d(p->player->v_angle - 15);
	y_change = sin_d(p->player->v_angle - 15);
	if (keycode == 119)
		move_forward(p, x_change, y_change);
	else if (keycode == 115)
		move_back(p, x_change, y_change);
	if (keycode == 65289)
		p->scrn = p->scrn == 0 ? 1 : 0;
	if (keycode == 65307)
		ft_exit(p);
}

int		key_press(int keycode, t_param *p)
{
	if (OS)
		mac_key_press(keycode, p);
	else
		linux_key_press(keycode, p);
	return (1);
}
