/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:41:59 by xeno              #+#    #+#             */
/*   Updated: 2018/07/30 06:51:30 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_map(t_param *p)
{
	t_pnt	s;
	int		i;
	int		total;
	t_vec3	*v;

	i = 0;
	total = vector_total(p->map->ver_vec);
	while (i < total)
	{
		v = (t_vec3 *)vector_get(p->map->ver_vec, i);
		s.x = (p->x_scale * v->x);
		s.y = (p->y_scale * v->y);
		if (v->z > 0)
			draw_square(&s, p);
		i++;
	}
}