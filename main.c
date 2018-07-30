/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/07/30 14:34:26 by shillebr         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2018/07/30 09:42:00 by xrhoda           ###   ########.fr       */
=======
/*   Updated: 2018/07/30 09:12:24 by shillebr         ###   ########.fr       */
>>>>>>> 379ff54766860855e531f0c31e8c107ab66e28a9
>>>>>>> 0a51f07c89c16a50f2b274168bb522b55a1df80d
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"
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
	int		i;

	mlx_clear_window(p->mlx, p->win);
	draw_map(p);
	//ft_putendl("test1");
	//i = ft_rays(p);
	//ft_putendl("test2");
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
