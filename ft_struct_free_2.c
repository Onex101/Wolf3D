/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_free_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:23:43 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/29 08:17:14 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	free_str_arr(char **str_arr)
{
	int i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	str_arr = NULL;
}

void	free_map_arr(char **str_arr, int y_max)
{
	int i;

	i = y_max;
	while (--i >= 0)
		free(str_arr[i]);
	free(str_arr);
}

void	ft_player_free(t_player *p)
{
	if (p)
	{
		if (p->pos)
			ft_vec2_free(p->pos);
		if (p->dir)
			ft_vec2_free(p->dir);
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

void	ft_dda_free(t_dda *p)
{
	if (p)
	{
		if (p->p)
			ft_vec2_free(p->p);
		if (p->dir)
			ft_vec2_free(p->dir);
		if (p->plane)
			ft_vec2_free(p->plane);
		free(p);
		p = NULL;
	}
}
