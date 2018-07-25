/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/25 18:14:10 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <fcntl.h>

void	init_win(t_window *w)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "Wolf3D");
}

int		draw_to_screen(t_window *w)
{
	t_pnt	s;
	int		x;
	int		y;

	s.y = 0;
	y = 0;
	while (s.y < HEIGHT)
	{
		y = s.y;
		s.x = 0;
		x = 0;
		while (s.x < WIDTH)
		{
			x = s.x + SCALE;
			if (s.y == 0 || s.x == 0 || x == WIDTH || y == HEIGHT)
				draw_square(&s, w);
			s.x = x;
			s.y = y;
		}
		s.y += SCALE;
	}
	return (0);
}

//int		main(int argc, char **argv)
int		main(void)
{
	t_window *win;
	//t_map	 *map;

	//if (argc == 2)
	//{
		if (!(win = (t_window *)malloc(sizeof(t_window))))
			return (-1);
		//if(!(map = read_map(open(argv[1], O_RDONLY))))
		//	return (-1);
		init_win(win);
		mlx_loop_hook(win->mlx, draw_to_screen, win);
		mlx_loop(win->mlx);
	//}
	return (0);
}
