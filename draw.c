/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/08 08:53:58 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_f_square(t_pnt *s, t_param *p, int c)
{
	t_pnt	e;
	int		i;

	i = 0;
	while (i <= p->y_scale)
	{
		e.x = s->x + p->x_scale;
		e.y = s->y;
		draw_line(&e, s, p, c);
		s->y++;
		i++;
	}
}

static void draw_c(t_param *p, int x, int y, int c)
{
	t_pnt pnt1;
	t_pnt pnt2;

	pnt1.x = x;
	pnt1.y = y;
	pnt2.x = p->player->pos->x;
	pnt2.y = p->player->pos->y;
	draw_line(&pnt1, &pnt2, p, c);
}

void draw_f_circle(t_pnt *s, t_param *p, int radius, int c)
{
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	while (x >= y)
	{
		draw_c(p, s->x + x, s->y + y, c);
		draw_c(p, s->x + y, s->y + x, c);
		draw_c(p, s->x - y, s->y + x, c);
		draw_c(p, s->x - x, s->y + y, c);
		draw_c(p, s->x - x, s->y - y, c);
		draw_c(p, s->x - y, s->y - x, c);
		draw_c(p, s->x + y, s->y - x, c);
		draw_c(p, s->x + x, s->y - y, c);

		if (err <= 0)
		{
			y++;
			err += dy;
			dy += 2;
		}
		
		if (err > 0)
		{
			x--;
			dx += 2;
			err += dx - (radius << 1);
		}
	}
}

void	draw_player(t_param *p)
{
	t_pnt s;

	s.x = (p->player->pos->x);
	s.y = (p->player->pos->y);
	draw_f_circle(&s, p, TILE_SIZE / 8, P_COL);
}