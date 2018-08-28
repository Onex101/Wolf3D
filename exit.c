/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:29:22 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 13:57:59 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	free_map(t_param *p)
{
	free_map_arr(p->map->m, p->map->max_y);
	free(p->map);
	p->map = NULL;
}

void	ft_exit(t_param *p)
{
	if (p->map)
		free_map(p);
	if (p->player)
		ft_player_free(p->player);
	if (p->image)
		mlx_destroy_image(p->mlx, p->image);
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->mlx)
		free(p->mlx);
	// if (p->buf)
	// 	free(p->buf);
	exit (0);
}
//tables