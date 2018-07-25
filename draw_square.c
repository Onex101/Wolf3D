/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/25 16:52:57 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_square(t_pnt *s, t_window *w)
{
	t_pnt e;

	e.x = s->x + SCALE;
	e.y = s->y;
	draw_line(&e, s, w);
	e.y = s->y + SCALE;
	e.x = s->x;
	draw_line(&e, s, w);
	s->x += SCALE;
	s->y += SCALE;
	e.x = s->x - SCALE;
	e.y = s->y;
	draw_line(&e, s, w);
	e.x = s->x;
	e.y = s->y - SCALE;
	draw_line(&e, s, w);
}