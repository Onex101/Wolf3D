/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:48:50 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/28 08:22:24 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

static	void	d_line(t_line_p line, t_pnt *pnt1, t_pnt *pnt2, t_param *p)
{
	int err;
	int m;

	err = line.dx + line.dy;
	while (1)
	{
		if (pnt1->x >= 0 && pnt1->x < WIDTH && pnt1->y >= 0 && pnt1->y < HEIGHT)
			pixel_put_image(p, pnt1->x, pnt1->y, line.c);
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

void			pnt_check(t_pnt *pnt1)
{
	if (pnt1->x < 0)
		pnt1->x = 0;
	else if (pnt1->x >= WIDTH)
		pnt1->x = WIDTH - 1;
	if (pnt1->y < 0)
		pnt1->y = 0;
	else if (pnt1->y >= HEIGHT)
		pnt1->y = HEIGHT - 1;
}

void			draw_line(t_pnt *pnt1, t_pnt *pnt2, t_param *p, int c)
{
	t_line_p line;

	pnt_check(pnt1);
	pnt_check(pnt2);
	line.dx = abs(pnt2->x - pnt1->x);
	line.dy = -(abs(pnt2->y - pnt1->y));
	line.sx = pnt1->x < pnt2->x ? 1 : -1;
	line.sy = pnt1->y < pnt2->y ? 1 : -1;
	line.c = c;
	d_line(line, pnt1, pnt2, p);
}
