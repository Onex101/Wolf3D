/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/26 09:42:21 by xrhoda           ###   ########.fr       */
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
	t_pnt	s;
	int		x_scale;
	int		y_scale;
	int		i;
	int		total;

	i = 0;
	x_scale = WIDTH / p->map->max_x;
	y_scale = HEIGHT / p->map->max_y;
	total = vector_total(p->map->ver_vec);
	while (i < total)
	{
		s.x = (x_scale * ((t_vec3 *)vector_get(p->map->ver_vec, i))->x);
		s.y = (y_scale * ((t_vec3 *)vector_get(p->map->ver_vec, i))->y);
		if (((t_vec3 *)vector_get(p->map->ver_vec, i))->z > 0)
			draw_square(&s, p, x_scale, y_scale);
		i++;
	}
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
