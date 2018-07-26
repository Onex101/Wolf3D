/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/26 16:49:36 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

void	init_win(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Wolf3D");
}

int		draw_to_screen(t_param *p)
{
	int		x_scale;
	int		y_scale;

	mlx_clear_window(p->mlx, p->win);
	x_scale = WIDTH / p->map->max_x;
	y_scale = HEIGHT / p->map->max_y;
	draw_map(p, x_scale, y_scale);
	return (0);
}

int		main(int argc, char **argv)
/*int		main(void)*/
{
	t_map	 *map;
	t_param	 *param;

	if (argc == 2)
	{
		if(!(map = read_map(open(argv[1], O_RDONLY))))
			return (-1);
		if (!(param = (t_param *)malloc(sizeof(t_param))))
			return (-1);
		param->map = map;
		param->map->max_x = map->max_x;
		param->map->max_y = map->max_y;
		init_win(param);
		mlx_loop_hook(param->mlx, draw_to_screen, param);
		mlx_loop(param->mlx);
	}
	return (0);
}
