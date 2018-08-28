/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:41:59 by xeno              #+#    #+#             */
/*   Updated: 2018/08/28 11:15:08 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_map(t_param *p)
{
	t_pnt	s;
	int		i;
	int		j;
	int		v;

	j = -1;
	while (++j < p->map->max_y)
	{
		i = -1;
		while (++i < p->map->max_x)
		{
			v = p->map->m[j][i] - '0';
			s = (t_pnt){(i * p->x_scale), (j * p->y_scale)};
			if (v > 0)
				draw_f_square(&s, p, WALL_COL);
			else
				draw_f_square(&s, p, SPC_COL);
		}
	}
	p->player->m_pos.x = p->player->pos->x;
	p->player->m_pos.y = p->player->pos->y;
}
