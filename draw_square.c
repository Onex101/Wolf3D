/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/25 13:05:26 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_square(t_pnt *s, t_window *w)
{
	t_pnt e;

	e.x = s->x + 64;
	e.y = s->y;
	draw_line(&e, s, w);
	e.y = s->y + 64;
	e.x = s->x;
	draw_line(&e, s, w);
	s->x += 64;
	s->y += 64;
	e.x = s->x - 64;
	e.y = s->y;
	draw_line(&e, s, w);
	e.x = s->x;
	e.y = s->y - 64;
	draw_line(&e, s, w);
}