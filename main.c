/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/08 16:39:05 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	init_param(t_param *p, char *str)
{
	if (!(p->map = read_map(open(str, O_RDONLY))))
		return ;
	ft_putendl("readmap test");
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Wolf3D");
	p->image = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->x_scale = WIDTH / p->map->max_x;
	p->y_scale = HEIGHT / p->map->max_y;
	p->player = ft_player_init(p);
}

int		draw_to_screen(t_param *p)
{
	if (p->buf)
	{
		sleep(1);
		clear_image(p);
	}
	draw_map(p);
	//ft_putendl("test1");
	if(!(ft_rays(p, p->player)))
	 	return (0);
	draw_player(p);
	// sleep (0.5);
	// ft_putendl("test2");
	// draw_player(); // wrtie draw_player;
	mlx_put_image_to_window(p->mlx, p->win, p->image, 0, 0);
	return (1);
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
		mlx_hook(param->win, 2, 0, key_press, param);
		mlx_loop_hook(param->mlx, draw_to_screen, param);
		mlx_loop(param->mlx);
	}
	return (0);
}
