/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:40:54 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/16 12:10:09 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <math.h>
#include <stdio.h>

// void	collision_check(int dx, int dy, t_param *p)
// {
// 	int	x_offset;
// 	int	y_offset;
// 	int	min_dist;
// 	t_vec3	*grid;

// 	x_offset = floor((int)p->player->pos->x % p->x_scale);
// 	y_offset = floor((int)p->player->pos->y % p->y_scale);
// 	min_dist = 15;
// 	if (dx > 0) // RIGHT
// 	{
// 		grid = (t_vec3 *)(vector_get(p->map->ver_vec, ((p->player->pos->y / p->y_scale) * M_WIDTH) + (p->player->pos->x / p->x_scale) + 1));
// 		if (grid->z != 0 && x_offset > (p->x_scale - min_dist))
// 			p->player->pos->x -= (x_offset - (p->x_scale - min_dist));
// 	}
// 	else //LEFT
// 	{
// 		grid = (t_vec3 *)(vector_get(p->map->ver_vec, ((p->player->pos->y / p->y_scale * M_WIDTH) + (p->player->pos->x / p->x_scale) - 1)));
// 		if (grid->z != 0 && x_offset < min_dist)
// 			p->player->pos->x += (min_dist - x_offset);
// 	}
// 	if (dy < 0) //UP
// 	{
// 		grid = (t_vec3 *)(vector_get(p->map->ver_vec, (((p->player->pos->y / p->y_scale) - 1) * M_WIDTH) + (p->player->pos->x / p->x_scale)));
// 		if (grid->z != 0 && y_offset < min_dist)
// 		{
// 			p->player->pos->y += (min_dist - y_offset);
// 			//return (1);
// 		}
// 	}
// 	else //DOWN
// 	{
// 		grid = (t_vec3 *)(vector_get(p->map->ver_vec, (((p->player->pos->y / p->y_scale) + 1) * M_WIDTH) + (p->player->pos->x / p->x_scale)));
// 		if (grid->z != 0 && y_offset > (p->y_scale - min_dist))
// 		{
// 			p->player->pos->y -= (y_offset - (p->y_scale - min_dist));
// 			//return (1);
// 		}	
// 	}
// 	//return (0);
// }

int			wall_check(t_param *par, t_player *p, int x_inc, int y_inc)
{
	void *pos;
	int		i;
	int		arr_y;
	int		arr_x;

	arr_x = (p->pos->x + x_inc) / par->x_scale;
	arr_y = (p->pos->y + y_inc) / par->y_scale;
	i = par->map->max_x * arr_y + arr_x;
	pos = vector_get(par->map->ver_vec, i);
	if (((t_vec3 *)(pos))->z == 0)
		return (1);
	i = par->map->max_x * (p->pos->y / par->y_scale) + arr_x;
	pos = vector_get(par->map->ver_vec, i);
	if (((t_vec3 *)(pos))->z == 0)
		return (2);
	i = par->map->max_x * arr_y + (p->pos->x / par->x_scale);
	pos = vector_get(par->map->ver_vec, i);
	if (((t_vec3 *)(pos))->z == 0)
		return (3);
	return (0);
}

void		mac_key_press(int keycode, t_param *p)
{
	double		x_change;
	double		y_change;
	static t_tables	*tab;
	int			wc;

	if (!tab)
		tab = get_tables();
	if (keycode == 0) //ROTATE LEFT
	{
		if ((p->player->v_angle -= 5) < 0)
			p->player->v_angle += 360;
	}
	else if (keycode == 2) //ROTATE RIGHT
	{
		if ((p->player->v_angle += 5) >= 360)
			p->player->v_angle -= 360;
	}
	x_change = cos_d(p->player->v_angle - 15);
	y_change = sin_d(p->player->v_angle - 15);
	if (keycode == 13)
	{
		wc = wall_check(p, p->player, x_change * p->player->spd, y_change * p->player->spd);
		if (wc == 1)
		{
			p->player->pos->x += (int)(x_change * p->player->spd);
			p->player->pos->y += (int)(y_change * p->player->spd);
		}
		else if (wc == 2)
			p->player->pos->x += (int)(x_change * p->player->spd);
		else if (wc == 3)
			p->player->pos->y += (int)(y_change * p->player->spd);
		//	collision_check(x_change * p->player->spd, y_change * p->player->spd, p);
		// collision_check(x_change * p->player->spd, y_change * p->player->spd, p);
	}
	else if (keycode == 1)
	{
		wc = wall_check(p, p->player, -x_change * p->player->spd, -y_change * p->player->spd);
		if (wc == 1)
		{
			p->player->pos->x -= (int)(x_change * p->player->spd);
			p->player->pos->y -= (int)(y_change * p->player->spd);
		}
		else if (wc == 2)
			p->player->pos->x -= (int)(x_change * p->player->spd);
		else if (wc == 3)
			p->player->pos->y -= (int)(y_change * p->player->spd);
			// collision_check(x_change * p->player->spd, y_change * p->player->spd, p);
	// 	p->player->pos->x -= (int)(x_change * p->player->spd);
	// 	p->player->pos->y -= (int)(y_change * p->player->spd);
	// 	collision_check(x_change * p->player->spd, y_change * p->player->spd, p);
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
	// return (0);
}

void		linux_key_press(int keycode, t_param *p)
{
	double		x_change;
	double		y_change;
	static t_tables	*tab;

	if (!tab)
		tab = get_tables();
	if (keycode == 97) //ROTATE LEFT
	{
		if ((p->player->v_angle -= 5) < 0)
			p->player->v_angle += 360;
	}
	else if (keycode == 100) //ROTATE RIGHT
	{
		if ((p->player->v_angle += 5) >= 360)
			p->player->v_angle -= 360;
	}
	x_change = cos_d(p->player->v_angle - 15);
	y_change = sin_d(p->player->v_angle - 15);
	if (keycode == 119)
	{
		p->player->pos->x += (int)(x_change * p->player->spd) / 2;
		p->player->pos->y += (int)(y_change * p->player->spd) / 2;
		//collision_check(x_change, y_change, p);
	}
	else if (keycode == 115)
	{
		p->player->pos->x -= (int)(x_change * p->player->spd) / 2;
		p->player->pos->y -= (int)(y_change * p->player->spd) / 2;
		//collision_check(x_change, y_change, p);
	}
	if (keycode == 65307)
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
	// return (0);
}

int		key_press(int keycode, t_param *p)
{
	printf("key = %d\n", keycode);
	if (OS)
		mac_key_press(keycode, p);
	else
		linux_key_press(keycode, p);
	return (1);
}