/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 07:39:27 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 11:12:24 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	draw_sky(int *c, int *l, int *col, t_param *p)
{
	t_pnt s1;
	t_pnt s2;

	*col = 22;
	while (*l < HEIGHT)
	{
		*col = rgb_to_hex(*c, 20, 20);
		s1 = (t_pnt){0, *l};
		s2 = (t_pnt){WIDTH - 1, *l};
		draw_line(&s1, &s2, p, *col);
		if ((int)(*l) % 10 == 0)
			*c += 2;
		(*l)++;
	}
}

void	draw_floor(int *c, int *l, int *col, t_param *p)
{
	t_pnt s1;
	t_pnt s2;

	while (*l < HEIGHT / 2)
	{
		*col = rgb_to_hex(0, 0, *c);
		s1 = (t_pnt){0, *l};
		s2 = (t_pnt){WIDTH - 1, *l};
		draw_line(&s1, &s2, p, *col);
		if ((int)(*l) % 10 == 0)
			*c -= 2;
		(*l)++;
	}
}

void	draw_back(t_param *p)
{
	int l;
	int c;
	int col;

	c = 125;
	l = 0;
	col = 0;
	draw_floor(&c, &l, &col, p);
	draw_sky(&c, &l, &col, p);
}
