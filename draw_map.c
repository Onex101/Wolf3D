/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:41:59 by xeno              #+#    #+#             */
/*   Updated: 2018/07/26 16:46:06 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_map(t_param *p, int x_scale, int y_scale)
{
	t_pnt	s;
	int		i;
	int		total;
	t_vec3	*v;

	i = 0;
	x_scale = WIDTH / p->map->max_x;
	y_scale = HEIGHT / p->map->max_y;
	total = vector_total(p->map->ver_vec);
	while (i < total)
	{
		v = (t_vec3 *)vector_get(p->map->ver_vec, i);
		s.x = (x_scale * v->x);
		s.y = (y_scale * v->y);
		if (v->z > 0)
			draw_square(&s, p, x_scale, y_scale);
		i++;
	}
}