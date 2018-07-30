/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/30 08:57:55 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_square(t_pnt *s, t_param *p)
{
	t_pnt e;

	e.x = s->x + p->x_scale;
	e.y = s->y;
	draw_line(&e, s, p, SQR_COL);
	e.y = s->y + p->y_scale;
	e.x = s->x;
	draw_line(&e, s, p, SQR_COL);
	s->x += p->x_scale;
	s->y += p->y_scale;
	e.x = s->x - p->x_scale;
	e.y = s->y;
	draw_line(&e, s, p, SQR_COL);
	e.x = s->x;
	e.y = s->y - p->y_scale;
	draw_line(&e, s, p, SQR_COL);
}

void	draw_f_square(t_pnt *s, t_param *p)
{
	t_pnt	e;
	int		i;

	i = 0;
	while (i <= p->y_scale)
	{
		e.x = s->x + p->x_scale;
		e.y = s->y;
		draw_line(&e, s, p, SQR_COL);
		s->y++;
		i++;
	}
}