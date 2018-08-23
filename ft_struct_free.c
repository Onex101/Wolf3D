/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:55:04 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/23 10:47:30 by shillebr         ###   ########.fr       */
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
		ft_vec2_free(p->pos);
		ft_vec2_free(p->dir);
		ft_pnt_free((&(p->m_pos)));
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
