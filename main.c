/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/16 10:21:14 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

t_param		*init_param(char *str)
{
	t_param	*p;
	// static int bpp;
	// static int s_line;
	// static int end;

	if (!(p = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	if (!(p->map = read_map(open(str, O_RDONLY))))
		return (NULL);
	ft_putendl("init param test 1");
	p->player = ft_player_init(p);
	ft_putendl("init param test 2");
	p->x_scale = WIDTH / p->map->max_x;
	p->y_scale = HEIGHT / p->map->max_y;
	ft_putendl("init param test 3");
	p->mlx = NULL;
	ft_putendl("init param test 4");
	p->win = NULL;
	ft_putendl("init param test 5");
	p->buf = 0;
	ft_putendl("init param test 6");
	p->image = NULL;
	ft_putendl("init param test 7");
	p->s_line = 0;
	ft_putendl("init param test 8");
	// p->buf = (int *)mlx_get_data_addr(p->image, &bpp, &s_line, &end);
	// exit(0);
	return (p);
}

int		draw_to_screen(t_param *p)
{
	// exit (0);
	ft_putendl("draw screen test 1");
	if (p->buf)
	{
		// sleep(1);
		clear_image(p);
	}
	ft_putendl("before draw map");
	draw_map(p);
	ft_putendl("after draw map");
	// exit (0);
	if(!(ft_rays(p, p->player)))
	 	return (0);
	// ft_putendl("Draw screen test 2");
	// draw_player(p);
	// sleep (0.5);
	mlx_put_image_to_window(p->mlx, p->win, p->image, 0, 0);
	// ft_putendl("Draw screen test 3");

	return (1);
}

int		main(int argc, char **argv)
{
	t_param	*param;
	void *mlx;
	void *win;
	static int bpp;
	static int s_line;
	static int end;

	if (argc != 2)
		exit (0);
	mlx =  mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wolf3D");
	// while (1)
	// {
		ft_putendl("main test 0");
		// if (!(param = (t_param *)malloc(sizeof(t_param))))
		// 	return (-1);
		ft_putendl("main test 1");
		if (!(param = init_param(argv[1])))
			return (-1);
		ft_putendl("main test 2");
		if (!(param->mlx = mlx))
			return (-1);
		ft_putendl("main test 3");
		if (!(param->win = win))
			return (-1);
		// if (!(init_param(param, argv[1])))
		// 	return (-1);
		ft_putendl("main test 4");
		param->image = mlx_new_image(param->mlx, WIDTH, HEIGHT);
		// exit (0);
		ft_putendl("main test 5");
		param->buf = (int *)mlx_get_data_addr(param->image, &bpp, &s_line, &end);
		ft_putendl("main test 6");
		param->s_line = s_line;
		ft_putendl("main test 7");
		// mlx_destroy_window(param->mlx, param->win);
		ft_putendl("main test 8");
		// free(win);
		// free(mlx);
		// exit (0);
		// return (0);
		// mlx_hook(param->win, 2, 0, key_press, param);
		mlx_loop_hook(param->mlx, draw_to_screen, param);
		ft_putendl("main test 9");
		mlx_key_hook(param->win, key_press, param);
		ft_putendl("main test 10");
		// exit (0);
		mlx_loop(mlx);
		ft_putendl("main test 11");
	// }
	while (1);
	return (0);
}