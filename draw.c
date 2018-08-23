/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/23 16:58:52 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	draw_f_square(t_pnt *s, t_param *p, int c)
{
	t_pnt	e;
	int		i;

	i = 0;
	while (i <= (MAP_SIZE))
	{
		e.x = s->x + (MAP_SIZE);
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
	pnt2->x = ((pnt2->x * MAP_SIZE) / p->x_scale);
	pnt2->y = (pnt2->y * MAP_SIZE) / p->y_scale;
	draw_line(pnt1, pnt2, p, c);
}

unsigned long rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	draw_back(t_param *p)
{
	int l;
	t_pnt s1;
	t_pnt s2;
	int c;
	int col;

	c = 125;
	l = 0;
	while (l < HEIGHT / 2)
	{
		col = rgb_to_hex(0, 0, c);
		s1.x = 0;
		s1.y = l;
		s2.x = WIDTH;
		s2.y = l;
		draw_line(&s1, &s2, p, col);
		if (l % 10 == 0)
			c -= 2;
		l++;
	}
	col = 22;
	while (l < HEIGHT)
	{
		col = rgb_to_hex(c, 20, 20);
		s1.x = 0;
		s1.y = l;
		s2.x = WIDTH;
		s2.y = l;
		draw_line(&s1, &s2, p, col);
		if (l % 10 == 0)
			c += 2;
		l++;
	}
}

int	check_wall_color(int c1, int c2, int colour)
{
	if (colour < c1)
		colour = c1;
	if (colour > c2)
		colour = c2;
	return (colour);
}

int get_wall_colour(double dis, t_dda *l)
{
	int colour;

	colour = (dis / 500) * 255;
	colour = check_wall_color(22, 255, colour);
	if (l->side == 0 && l->step->x == 1)
		colour = rgb_to_hex(colour, 0, 0);
	else if (l->side == 0 && l->step->x == -1)
		colour = rgb_to_hex(0, 0, colour);
	else if (l->side == 1 && l->step->y == 1)
		colour = rgb_to_hex(0, colour, 0);
	else if (l->side == 1 && l->step->y == -1)
		colour = rgb_to_hex(colour, colour, 0);
	return (colour);
}

void	draw_col(double dist, int col, t_param *p, t_dda *l)
{
	int bot_wall;
	int top_wall;
	t_pnt pnt1;
	t_pnt pnt2;
	int colour;

	colour = get_wall_colour(dist, l);
	bot_wall = -dist / 2 + HEIGHT / 2;
	if (bot_wall < 0)
		bot_wall = 1;
	top_wall = dist / 2 + HEIGHT / 2;
	if (top_wall > HEIGHT)
		top_wall = HEIGHT - 1;
	pnt1.x = col;
	pnt1.y = top_wall;
	pnt2.x = col;
	pnt2.y = bot_wall;
	draw_line(&pnt1, &pnt2, p, colour);
}