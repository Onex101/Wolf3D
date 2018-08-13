/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:50:37 by xeno              #+#    #+#             */
/*   Updated: 2018/08/13 20:45:35 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

double ray_dist(t_vec2 start, t_vec2 end) 
{
	return	(sqrt(
			(end.x - start.x) * (end.x - start.x) + 
			(end.y - start.y) * (end.y - start.y)));
}

double get_raycast(t_vec2 ray_start, double ray_cos, double ray_sin, t_line line) 
{
	t_vec2	ray_end;
	t_vec2	l_diff;
	t_vec2	ray_col;
	double	s;
	double	t;

	ray_end.x = ray_cos - ray_start.x; // End of ray x
	ray_end.y = ray_sin - ray_start.y; // End of ray y
	l_diff.x = line.x2 - line.x1; // Line x diff
	l_diff.y = line.y2 - line.y1; // Line y diff
	s = (-ray_end.y * (ray_start.x - line.x1) + 
		ray_end.x * (ray_start.y - line.y1)) / 
		(-l_diff.x * ray_end.y + ray_end.x * l_diff.y);
	t = (l_diff.x * (ray_start.y - line.y1) - l_diff.y * (ray_start.x - line.x1)) / 
		(-l_diff.x * ray_end.y + ray_end.x * l_diff.y);
	if (s >= 0 && s <= 1 && t >= 0 && t <= 1) 
	{
		// Collision detected
		ray_col.x = ray_start.x + (t * ray_end.x);
		ray_col.y = ray_start.y + (t * ray_end.y);
		return ray_dist(ray_start, ray_col);
	}

	return (-1); // No collision
}