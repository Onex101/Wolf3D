/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 07:14:37 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/28 11:14:07 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

unsigned long	rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int				check_wall_color(int c1, int c2, int colour)
{
	if (colour < c1 && colour != 0)
		colour = c1;
	else if (colour > c2 || colour == 0)
		colour = c2;
	return (colour);
}

int				get_wall_colour(double dis, t_dda *l)
{
	int colour;

	colour = (dis / 500) * 255;
	colour = check_wall_color(22, 255, colour);
	if (l->side == 0 && l->step->x == 1)
		colour = rgb_to_hex(colour, 0, 0);
	else if (l->side == 0 && l->step->x == -1)
		colour = rgb_to_hex(0, 0, colour);
	else if (l->side == 1 && l->step->y == 1)
		colour = rgb_to_hex(0, colour, 0);
	else if (l->side == 1 && l->step->y == -1)
		colour = rgb_to_hex(colour, colour, 0);
	return (colour);
}
