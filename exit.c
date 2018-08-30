/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:29:22 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/30 07:00:40 by shillebr         ###   ########.fr       */
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
	t_tables		*t;

	if (!p)
		return ;
	t = get_tables();
	if (t)
		ft_tables_free(t);
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
	exit(0);
}
