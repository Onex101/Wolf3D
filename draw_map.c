/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:41:59 by xeno              #+#    #+#             */
/*   Updated: 2018/08/14 15:12:02 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_map(t_param *p)
{
	t_pnt	s;
	int		i;
	int		j;
	//int		total;
	t_vec3	*v;

	//total = vector_total(p->map->ver_vec);
	j = 0;
	while (j < M_HEIGHT)
	{
		i = 0;
		while (i < M_WIDTH)
		{
			v = (t_vec3 *)vector_get(p->map->ver_vec, (M_WIDTH * j + i));
			s.x = WIDTH + (i * MAP_SIZE / 2.5);
			s.y = (j * MAP_SIZE / 2.5);
			if (v->z > 0)
				draw_f_square(&s, p, WALL_COL);
			else
				draw_f_square(&s, p, SPC_COL);
			i++;
		}
		j++;
	}
	p->player->m_pos.x = WIDTH + ((p->player->pos->x / TILE_SIZE) * MAP_SIZE);
	p->player->m_pos.y = (p->player->pos->y / TILE_SIZE) * MAP_SIZE;
}