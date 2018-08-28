/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/28 10:01:51 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <string.h>
#include "trig_tables.h"

int		init_param(t_param **p, char *str, void *mlx)
{
	static int	bpp;
	static int	s_line;
	static int	end;
	char		**file;

	if (!(*p) || !str || !mlx)
	{
		ft_putendl("FAIL");
		return (0);
	}
	if (!((*p)->map = (t_map *)malloc(sizeof(t_map))))
		return (0);	
	if (!((*p)->map->max_y = ft_readfile(&(file), str)))
		return (0);
	(*p)->map->max_x = ft_strlen(file[0]);
	(*p)->map->m = file;
	(*p)->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	(*p)->x_scale = WIDTH / (*p)->map->max_x;
	(*p)->y_scale = HEIGHT / (*p)->map->max_y;
	if(!((*p)->player = ft_player_init((*p))))
		return (0);
	(*p)->buf = (int *)mlx_get_data_addr((*p)->image, &bpp, &s_line, &end);
	(*p)->s_line = s_line;
	(*p)->scrn = 0;
	return (1);
}

int		draw_to_screen(t_param *p)
{
	if (p->buf)
		clear_image(p);
	if (p->scrn == 0)
		draw_back(p);
	if (p->scrn == 1)
		draw_map(p);
	if (!(ft_rays(p, p->player)))
		return (0);
	mlx_put_image_to_window(p->mlx, p->win, p->image, 0, 0);
	
	return (1);
}

int		main(int ac, char **av)
{
	t_param	*param;
	void *mlx;
	void *win;

	if (!(mlx =  mlx_init()))
		return (-1);
	if (!(win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wolf3D")))
		return (-1);
	if (ac != 2)
	{
		ft_putendl("Incorrect number of inputs.");
		return (0);
	}
	if ((param = (t_param *)malloc(sizeof(t_param))))
	{
		if (!(init_param(&param, av[1], mlx)))
			return (-1);
		param->mlx = mlx;
		param->win = win;
		if (!param->mlx)
			return (-1);
		mlx_hook(win, 2, 0, key_press, param);
		mlx_loop_hook(mlx, draw_to_screen, param);
		if (mlx)
			mlx_loop(mlx);
		else
			return (-1);
	}
	return (0);
}
