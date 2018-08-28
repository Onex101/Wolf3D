/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:50:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/28 11:13:10 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	draw_f_square(t_pnt *s, t_param *p, int c)
{
	t_pnt	e;
	int		i;

	i = 0;
	while (i < p->y_scale)
	{
		e.x = s->x + p->x_scale;
		e.y = s->y;
		draw_line(&e, s, p, c);
		s->y++;
		i++;
	}
}

void	draw_ray(t_pnt *pnt1, t_pnt *pnt2, t_param *p, int c)
{
	pnt1->x = p->player->m_pos.x;
	pnt1->y = p->player->m_pos.y;
	pnt2->x = pnt2->x;
	pnt2->y = pnt2->y;
	draw_line(pnt1, pnt2, p, c);
}

void	draw_col(double dist, int col, t_param *p, t_dda *l)
{
	int		bot_wall;
	int		top_wall;
	t_pnt	pnt1;
	t_pnt	pnt2;
	int		colour;

	colour = get_wall_colour(dist, l);
	bot_wall = -dist / 2 + HEIGHT / 2;
	if (bot_wall < 0)
		bot_wall = 1;
	top_wall = dist / 2 + HEIGHT / 2;
	if (top_wall > HEIGHT)
		top_wall = HEIGHT - 1;
	if (dist == 0)
	{
		bot_wall = 0;
		top_wall = HEIGHT;
	}
	pnt1 = (t_pnt){col, top_wall};
	pnt2 = (t_pnt){col, bot_wall};
	draw_line(&pnt1, &pnt2, p, colour);
}
