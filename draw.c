/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/14 13:50:35 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_f_square(t_pnt *s, t_param *p, int c)
{
	t_pnt	e;
	int		i;

	i = 0;
	while (i <= (MAP_SIZE / 2.5))
	{
		e.x = s->x + (MAP_SIZE / 2.5);
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

void	draw_ray(t_pnt *pnt1, t_pnt *pnt2, t_param *p, int c)
{
	pnt1->x = p->player->m_pos.x; 
	pnt1->y = p->player->m_pos.y;
	pnt2->x = WIDTH + ((pnt2->x * MAP_SIZE) / TILE_SIZE);
	pnt2->y = (pnt2->y * MAP_SIZE) / TILE_SIZE;
	draw_line(pnt1, pnt2, p, c);
}

void	draw_back(t_param *p, int s_col, int f_col)
{
	int l;
	t_pnt s1;
	t_pnt s2;

	l = 0;
	while (l < HEIGHT / 2)
	{
		s1.x = 0;
		s1.y = l;
		s2.x = WIDTH;
		s2.y = l;
		draw_line(&s1, &s2, p, s_col);
		if (l % 10 == 0)
			s_col += 2;
		l++;
	}
	while (l < HEIGHT)
	{
		s1.x = 0;
		s1.y = l;
		s2.x = WIDTH;
		s2.y = l;
		draw_line(&s1, &s2, p, f_col);
		if (l % 10 == 0)
			f_col += 2;
		l++;
	}
}

void	draw_col(double dist, int col, t_param *p, int c)
{
	int bot_wall;
	int top_wall;
	t_pnt pnt1;
	t_pnt pnt2;

	bot_wall = (HEIGHT / 2) + ((WALL_HEIGHT * (PLANE_DIST / dist)));
	top_wall = HEIGHT - bot_wall;
	if (bot_wall >= HEIGHT)
		bot_wall = HEIGHT - 1;
	pnt1.x = col;
	pnt1.y = top_wall;
	pnt2.x = col;
	pnt2.y = bot_wall;
	draw_line(&pnt1, &pnt2, p, c);
}