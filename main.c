/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/23 18:20:38 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <string.h>
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
	draw_back(p);
	draw_map(p);
	if(!(ft_rays(p, p->player)))
	 return (0);
	mlx_put_image_to_window(p->mlx, p->win, p->image, 0, 0);
	if (p->buf)
		clear_image(p);
	return (1);
}

//int		main(int argc, char **argv)
int		main(void)
{
	t_param	*param;
	void *mlx;
	void *win;

	mlx = NULL;
	win = NULL;
	mlx =  mlx_init();
	if (mlx == NULL)
		return (-1);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wolf3D");
	if (!win)
		return (-1);
	if (!win)
		return (-1);
	// if (argc == 2)
	// {
	if ((param = (t_param *)malloc(sizeof(t_param))))
	{
		param->mlx = mlx;
		param->win = win;
		if (!(init_param(param, "maps/8")))
			return (-1);
		if (!param->mlx)
			return (-1);
		mlx_hook(win, 2, 0, key_press, param);
		mlx_loop_hook(mlx, draw_to_screen, param);
		if (mlx)
			mlx_loop(mlx);
		else
			return (-1);
	}
	//}
	return (0);
}