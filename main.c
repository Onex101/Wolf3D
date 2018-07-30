/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/30 06:57:38 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

void	init_param(t_param *p, char *str)
{
	if (!(p->map = read_map(open(str, O_RDONLY))))
		return ;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Wolf3D");
	p->x_scale = WIDTH / p->map->max_x;
	p->y_scale = HEIGHT / p->map->max_y;
}

int		draw_to_screen(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	draw_map(p);
	//draw_player(); // wrtie draw_player;
	return (0);
}

int		main(int argc, char **argv)
{
	t_param	*param;

	if (argc == 2)
	{
		param = (t_param *)malloc(sizeof(t_param));
		init_param(param, argv[1]);
		if (!param->mlx)
			return (-1);
		mlx_loop_hook(param->mlx, draw_to_screen, param);
		mlx_loop(param->mlx);
	}
	return (0);
}
