/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:22:37 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/23 14:24:28 by shillebr         ###   ########.fr       */
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

void	ft_vec3_free(t_vec3 *p)
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
