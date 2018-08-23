/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/23 14:20:06 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

int		init_param(t_param *p, char *str)
{
	static int bpp;
	static int s_line;
	static int end;

	if (!(p->map = read_map(open(str, O_RDONLY))))
		return (0);
	p->image = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->x_scale = WIDTH / p->map->max_x;
	p->y_scale = HEIGHT / p->map->max_y;
	if(!(p->player = ft_player_init(p)))
		return (0);
	p->buf = (int *)mlx_get_data_addr(p->image, &bpp, &s_line, &end);
	p->s_line = s_line;

	return (1);
}

int		draw_to_screen(t_param *p)
{
	if (p->buf)
		clear_image(p);
	draw_back(p);
	draw_map(p);
	if(!(ft_rays(p, p->player)))
	 	return (0);
	mlx_put_image_to_window(p->mlx, p->win, p->image, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_param	*param;
	void *mlx;
	void *win;

	mlx =  mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wolf3D");
	if (argc == 2)
	{
		if ((param = (t_param *)malloc(sizeof(t_param))))
		{
			param->mlx = mlx;
			param->win = win;
			if (!(init_param(param, argv[1])))
				return (-1);
			if (!param->mlx)
				return (-1);
			mlx_hook(param->win, 2, 0, key_press, param);
			mlx_loop_hook(param->mlx, draw_to_screen, param);
			mlx_key_hook(param->win, key_press, param);
			mlx_loop(param->mlx);
		}
	}
	return (0);
}