/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:48:50 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/25 12:48:35 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static	void	d_line(t_line_p line, t_pnt *pnt1, t_pnt *pnt2, t_window *p)
{
	int err;
	int m;

	err = line.dx + line.dy;
	while (1)
	{
		mlx_pixel_put(p->mlx, p->win, pnt1->x, pnt1->y, 0xFFFFFF);
		if (pnt1->x == pnt2->x && pnt1->y == pnt2->y)
			break ;
		m = 2 * err;
		if (m >= line.dy)
		{
			err += line.dy;
			pnt1->x += line.sx;
		}
		if (m <= line.dx)
		{
			err += line.dx;
			pnt1->y += line.sy;
		}
	}
}

void			draw_line(t_pnt *pnt1, t_pnt *pnt2, t_window *p)
{
	t_line_p line;

	line.dx = abs(pnt2->x - pnt1->x);
	line.dy = -(abs(pnt2->y - pnt1->y));
	line.sx = pnt1->x < pnt2->x ? 1 : -1;
	line.sy = pnt1->y < pnt2->y ? 1 : -1;
	d_line(line, pnt1, pnt2, p);
}
