/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:29:22 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 13:47:58 by shillebr         ###   ########.fr       */
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
	printf("free test 1\n");
	if (p->map)
		free_map(p);
	printf("free test 2\n");
	if (p->player)
		ft_player_free(p->player);
	printf("free test 3\n");
	if (p->image)
		mlx_destroy_image(p->mlx, p->image);
	printf("free test 4\n");
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	printf("free test 5\n");
	if (p->mlx)
		free(p->mlx);
	printf("free test 6\n");
	// if (p->buf)
	// 	free(p->buf);
	printf("free test 7\n");
	exit (0);
}
//tables