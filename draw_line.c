/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:48:50 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/15 18:13:51 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>
#include <stdio.h>

static	void	d_line(t_line_p line, t_pnt *pnt1, t_pnt *pnt2, t_param *p)
{
	int err;
	int m;

	err = line.dx + line.dy;
	while (1)
	{
		// ft_putendl("d_line test 1");
		// printf("pnt1 x = %d y = %d\npnt2 x = %d y = %d\n", pnt1->x, pnt1->y, pnt2->x, pnt2->y);
		pixel_put_image(p, pnt1->x, pnt1->y, line.c);
		// ft_putendl("d_line test 2");
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
		// ft_putendl("d_line test 3");
	}
	// ft_putendl("d_line test 4");
}

void			draw_line(t_pnt *pnt1, t_pnt *pnt2, t_param *p, int c)
{
	t_line_p line;

	line.dx = abs(pnt2->x - pnt1->x);
	line.dy = -(abs(pnt2->y - pnt1->y));
	line.sx = pnt1->x < pnt2->x ? 1 : -1;
	line.sy = pnt1->y < pnt2->y ? 1 : -1;
	line.c = c;
	// ft_putendl("draw_line test 1");
	d_line(line, pnt1, pnt2, p);
	// ft_putendl("draw_line test 2");
}
