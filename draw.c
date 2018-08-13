/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/13 20:45:31 by xeno             ###   ########.fr       */
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

void	draw_back(t_param *p, int sky_c, int floor_c)
{
	int r;
	t_pnt s1;
	t_pnt s2;

	r = 0;
	while (r < HEIGHT / 2)
	{
		s1.x = 0;
		s1.y = r;
		s2.x = WIDTH;
		s2.y = r;
		draw_line(&s1, &s2, p, sky_c);
		r++;
	}
	while (r < HEIGHT)
	{
		s1.x = 0;
		s1.y = r;
		s2.x = WIDTH;
		s2.y = r;
		draw_line(&s1, &s2, p, floor_c);
		r++;
	}
}

void	draw_column(double dist, t_param *p, int col, int colour)
{
	int top_wall;
	int bot_wall;
	int h_scale;
	t_pnt s1;
	t_pnt s2;

	dist /= 
	h_scale = WALL_HEIGHT * PLANE_DIST / dist;
	bot_wall = HEIGHT / 2 + (h_scale * 0.5);
	top_wall = HEIGHT - bot_wall;
	if (bot_wall >= HEIGHT)
		bot_wall = HEIGHT - 1;
	s1.x = col;
	s1.y = top_wall;
	s2.x = col;
	s2.y = bot_wall;
	draw_line(&s1, &s2, p, colour);
}

static void draw_c(t_param *p, int x, int y, int c)
{
	t_pnt pnt1;
	t_pnt pnt2;

	pnt1.x = x;
	pnt1.y = y;
	pnt2.x = p->player->pos->x;
	pnt2.y = p->player->pos->y;
	ft_putendl("draw_c test 1");
	draw_line(&pnt1, &pnt2, p, c);
	ft_putendl("draw_c test 2");
}

void draw_f_circle(t_pnt *s, t_param *p, int radius, int c)
{
	int x = radius - 1;
	int y = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (radius << 1);

	ft_putendl("draw_circle test 1");
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
		ft_putendl("draw_circle test 1_1");

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
	ft_putendl("draw_circle test 2");
}

void	draw_player(t_param *p)
{
	t_pnt s;

	s.x = (p->player->pos->x);
	s.y = (p->player->pos->y);
	ft_putendl("draw_player test 1");
	draw_f_circle(&s, p, TILE_SIZE / 8, P_COL);
	ft_putendl("draw_player test 2");
}