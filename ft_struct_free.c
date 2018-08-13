/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:55:04 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/13 09:22:46 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	ft_vec2_free(t_vec2 *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void	ft_pnt_free(t_pnt *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void	ft_line_free(t_line *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void	ft_player_free(t_player *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void	ft_tables_free(t_tables *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void	ft_dist_free(t_dist *p)
{
	if (p)
	{
		ft_pnt_free(p->p1);
		if (p->p2)
			ft_pnt_free(p->p2);
		free(p);
		p = NULL;
	}
}

void	ft_check_free(t_check *p)
{
	if (p)
	{
		if (p->col)
			ft_vec2_free(p->col);
		if (p->arr)
			ft_pnt_free(p->arr);
		free(p);
		p = NULL;
	}
}