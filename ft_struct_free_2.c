/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:23:43 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 11:15:12 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

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
