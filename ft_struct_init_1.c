/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 07:43:05 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/23 20:52:46 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

t_vec2		*ft_vec2_init(double x, double y)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = x;
		new->y = y;
	}
	return (new);
}

t_vec3		*ft_vec3_init(double x, double y, double z)
{
	t_vec3	*new;

	new = NULL;
	if ((new = (t_vec3 *)malloc(sizeof(t_vec3))))
	{
		new->x = x;
		new->y = y;
		new->y = z;
	}
	return (new);
}

t_pnt		*ft_pnt_init(int x, int y)
{
	t_pnt	*new;

	new = NULL;
	if ((new = (t_pnt *)malloc(sizeof(t_pnt))))
	{
		new->x = x;
		new->y = y;
	}
	return (new);
}

t_ln		*ft_line_init(double x1, double y1, double x2, double y2)
{
	t_ln	*new;

	new = NULL;
	if ((new = (t_ln *)malloc(sizeof(t_ln))))
	{
		new->x1 = x1;
		new->y1 = y1;
		new->x2 = x2;
		new->y2 = y2;
	}
	return (new);
}

t_player	*ft_player_init(t_param *par)
{
	t_player	*p;

	if (!(p = (t_player *)malloc(sizeof(t_player))) || !par)
		return (NULL);
	p->pos = ft_vec2_init(365, 365);
	p->dir = ft_vec2_init(0, 0);
	p->m_pos = (t_pnt){0, 0};
	p->v_angle = 90;
	p->hght = 32;
	p->spd = 16;
	return (p);
}
