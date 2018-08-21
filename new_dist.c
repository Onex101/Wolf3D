/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:52:46 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/21 14:02:14 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_vec2	*ft_dirVec(t_player *p)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = x_scale * cos(v_angle) + p->pos->x;
		new->y = y_scale * sin(v_angle) + p->pos->y;
		return (new);
	}
	return (NULL);
}

t_vec2	*ft_planeVec(t_player *p, t_vec2 *dir)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = dir->x + (1 / sqrt(3)) * (-(p->pos_y - dir->y));
		new->y = dir->y + (1 / sqrt(3)) * (-(p->pos_x - dir->x));
		return (new);
	}
	return (NULL);
}

t_vec2	*ft_rayDirVec(t_vec2 *dir, t_vec2 *plane, double cameraX)
{
	t_vec2	*new;

	new = NULL;
	if ((new = (t_vec2 *)malloc(sizeof(t_vec2))))
	{
		new->x = dir->x + plane->x * cameraX;
		new->y = dir->y + plane->y * cameraX;
		return (new);
	}
	return (NULL);
}

double	ft_distance()
{
	//posX and Y are in player->pos
	t_vec2	*dir;
	t_vec2	*plane;
	t_vec2	*rayDir;
	t_vec2	*sideDist; // initially the dist the ray has to travel from its start position to the first x-side and the first y-side. Later in the code their meaning will slightly change
	t_vec2	*deltaDist; //the distance the ray has to travel to go from one xside and yside to the next
	t_pnt	*map; //current square on the map the ray is in
	t_pnt	*step; //what direction  to step in x or y direction(either +1 or -1)
	double	t; //time
	double	ot; //old_time
	double	cameraX;
	double	perpWallDist;
	int		x;
	int		hit; //was wall hit? h->pos
	int		side; //which wall was hit h->wall


	if (!(dir = ft_dirVec(p)) || !(plane = ft_planeVec(p, dir)))
		return (-1);
		x = 0;
		while (x < FOV)
		{
			cameraX = 2 * x / FOV - 1;
			if (!(rayDir = ft_rayDirVec(dir, plane, cameraX)))
				return (-1);
			// if (!(map = ft_pnt_init(floor(p->pos->x / x_scale), floor(p->pos->y / y_scale))))
			if (!(map = ft_pnt_init(floor(p->pos->x), floor(p->pos->y))))
				return (-1);
			if ( !(sideDist = ft_vec2_init(0, 0)) || !(deltaDist = ft_vec2_init(fabs(1 / rayDir->x), fabs(1 / rayDir->y))))
				return (-1);
			
			//Now calculate stepX, stepY, sideDistX and sideDistY
			if (rayDir->x < 0)
			{
				step->x = -1;
				sideDist->x = (p->pos->x - map->x) * deltaDist->x;
			}
			else
			{
				step->x = 1;
				sideDist->x = (map->x + 1 - p->pos->x) * deltaDist->x;
			}
			if (rayDir->y < 0)
			{
				step->y = -1;
				sideDist->x = (p->pos->y - map->y) * deltaDist->y;
			}
			else
			{
				step->y = 1;
				sideDist->y = (map->y + 1 - p->pos->y) * deltaDist->y;
			}
			//Perform DDA
			hit = 0;
			while (hit == 0)
			{
				if (sideDist->x < sideDist->y)
				{
					sideDist->x += deltaDist->x;
					map->x += step->x;
					side = 0;
				}
				else
				{
					sideDist->y += deltaDist->y;
					map->y += step->y;
					side = 1;
				}

				h->pos = vectorget();
				if (((t_vec3 *)(h->pos))->z > 0)
					hit = 1;
			}
			//Calculate distance projected on camera direction
			if (side == 0)
				perpWallDist = (map->x - pos->x + (1 - step->x) / 2) / rayDir->x;
			else
				perpWallDist = (map->y - pos->y + (1 - step->y) / 2) / rayDir->y;

			ft_vec2_free(rayDir);
			x++;
		}
}