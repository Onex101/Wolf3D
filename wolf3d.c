/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 07:58:08 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/25 09:52:05 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		init_player(t_player *p)
{
	p->pos.x = 22;
	p->pos.y = 12;
	p->v_angle = 0;
	p->dir.x = -1;
	p->dir.y = 0;
	p->hght = WALL_HEIGHT / 2;
	p->angle = 0;
}

void		init_window(t_window *w)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Wolf3D");
}

void		init_plane(t_plane *plane)
{
	plane->proj_plane = WIDTH * HEIGHT;
	plane->centre.x = WIDTH / 2;
	plane->centre.y = HEIGHT / 2;
	plane->dist_plane = (WIDTH / 2) / tan(30);
	plane->angl_rays = 60 / WIDTH;
}

void	game_loop
{
	int i;
	vec2 camera;
	vec2 ray_direction;
	vec2 map_box;

	i = 0;
	while (i < WIDTH)
	{
		
	}
}

int			main(void)
{
	t_player	p;
	t_window	w;
	double		t_new;
	double		t_old;

	init_player(&player);
	init_window(&w);
	return (0);

	while (!done)
	{
		game_loop();
	}
}