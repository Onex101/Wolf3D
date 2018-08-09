/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 07:43:05 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/09 14:06:12 by shillebr         ###   ########.fr       */
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

t_line		*ft_line_init(double x1, double y1, double x2, double y2)
{
	t_line	*new;


	new = NULL;
	if ((new = (t_line *)malloc(sizeof(t_line))))
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
	p->pos = *ft_vec2_init(360, 300);
	p->dir = *ft_vec2_init(0, 0);
	p->v_angle = 0;
	p->hght = 32;
	return (p);
}

t_dist	*ft_init_dist(t_player *p)
{
	t_dist	*dist;

	if ((dist = (t_dist *)malloc(sizeof(t_dist))))
	{
		if (!(dist->t = get_tables()))
			return (NULL);
		dist->h_dist = NULL;
		dist->v_dist = NULL;
		if(!(dist->p1 = ft_pnt_init((p->pos).x, (p->pos).y)))
			return (NULL);
		dist->p2 = NULL;
		dist->h_distance = 0;
		dist->v_distance = 0;
		dist->a = 0;
		dist->n = 1;
		return (dist);
	}
	else
		return (NULL);
}

t_check	*ft_init_check(void)
{
	t_check	*ret;

	if (!(ret = (t_check *)malloc(sizeof(t_check))))
		return (NULL);
	if (!(ret->col = ft_vec2_init(0, 0)) || !(ret->arr = ft_pnt_init(0, 0)))
		return (NULL);
	ret->ya = 0;
	ret->xa = 0;
	ret->pos = NULL;
	ret->vu = 0;
	ret->hl = 0;
	return (ret);
}