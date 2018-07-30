/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 06:40:54 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/30 10:15:55 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

// int		adjust_rotate(int keycode, t_param *p)
// {
// 	double rotate;

// 	rotate = 0.1;
// 	if (keycode == 0)
// 		p->v_angle += 10;
// 	else if (keycode == 2)
// 		p->v_angle -= 10;
// 	else
// 		return (0);
// 	return (1);
// }

// int		adjust_pos(int keycode, t_param *p)
// {
// 	double trans;

// 	trans = 2;
// 	if (keycode == 123)
// 		p->pos->x -= trans;
// 	else if (keycode == 124)
// 		p->t.x += trans;
// 	return (1);
// }

int		key_hook(int keycode, t_param *p)
{
	// if ((adjust_rotate(keycode, p) == 1))
	// 	;
	// // else if ((adjust_pos(keycode, p) == 1))
	// // 	;
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(0);
	}
	return (0);
}
