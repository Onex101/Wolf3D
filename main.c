/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/28 12:29:16 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

int		map_init(t_param **p, char *str)
{
	char		**file;

	if (!((*p)->map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if (!((*p)->map->max_y = ft_readfile(&(file), str)))
		return (0);
	(*p)->map->max_x = ft_strlen(file[0]);
	(*p)->map->m = file;
	return (1);
}

int		init_param(t_param **p, char *str)
{
	static int	bpp;
	static int	s_line;
	static int	end;

	if (!(*p) || !str)
		return (0);
	if (!map_init(p, str))
		return (0);
	(*p)->mlx = mlx_init();
	if ((*p)->mlx)
		(*p)->win = mlx_new_window((*p)->mlx, WIDTH, HEIGHT, "Wolf3D");
	if (!((*p)->mlx) || !((*p)->win))
		return (-1);
	(*p)->image = mlx_new_image((*p)->mlx, WIDTH, HEIGHT);
	(*p)->x_scale = WIDTH / (*p)->map->max_x;
	(*p)->y_scale = HEIGHT / (*p)->map->max_y;
	if (!((*p)->player = ft_player_init((*p))))
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

	if (ac != 2)
	{
		ft_putendl("Incorrect number of inputs.");
		return (0);
	}
	if ((param = (t_param *)malloc(sizeof(t_param))))
	{
		if (!(init_param(&param, av[1])))
			return (-1);
		if (!param->mlx)
			return (-1);
		mlx_hook(param->win, 2, 0, key_press, param);
		mlx_loop_hook(param->mlx, draw_to_screen, param);
		mlx_loop(param->mlx);
	}
	return (0);
}
