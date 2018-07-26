/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/26 09:42:02 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_square(t_pnt *s, t_param *p, int scale_x, int scale_y)
{
	t_pnt e;

	e.x = s->x + scale_x;
	e.y = s->y;
	draw_line(&e, s, p);
	e.y = s->y + scale_y;
	e.x = s->x;
	draw_line(&e, s, p);
	s->x += scale_x;
	s->y += scale_y;
	e.x = s->x - scale_x;
	e.y = s->y;
	draw_line(&e, s, p);
	e.x = s->x;
	e.y = s->y - scale_y;
	draw_line(&e, s, p);
}