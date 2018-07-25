/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/25 13:51:02 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_isup(double theta)
{
	if (theta >= 0 && theta < 90)
		return (1);
	else if (theta >= -360 && theta < -270)
		return (1);
	else if (theta > -90 && theta <= 0)
		return (1);
	else if (theta > 270 && theta <= 360)
		return (1);
	else
		return (0);
}

int		ft_isdown(double theta)
{
	if (theta > 90 && theta <= 180)
		return (1);
	else if (theta > -270 && theta <= -180)
		return (1);
	else if (theta < 270 && theta >= 180)
		return (1);
	else if (theta < -90 && theta >= -180)
		return (1);
	else
		return (0);
}

int		ft_isleft(double theta)
{
	if (theta < 0 && theta > -180)
		return (1);
	else if (theta < 360 && theta > 180)
		return (1);
	else
		return (0);
}

int		ft_isright(double theta)
{
	if (theta > 0 && theta < 180)
		return (1);
	else if (theta > -360 && theta < -180)
		return (1);
	else
		return (0);
}

int		ft_horizontal_check(t_player *p)
{
	int		ya;
	int		xa;
	int		inter_x;
	int		inter_y;

	if (ft_isup(theta))
		ay = (p->pos.y/64) * (64) - 1;
	else if (ft_isdown(theta))
		ay = (p->pos.y / 64) * 64 + 64;
	inter_y = ay / 64;
	ax = p->pos.x + (p->pos.y - ay) / tan(FOV);
	inter_x = ax / 64;

	//Find Ya
	if (ft_isup(theta))
		ya = -64;
	else if (ft_isdown(theta))
		ya = 64;
	xa = 64 / tan(FOV); //xa = 36;

	while (grid(inter_y)(inter_x) != 'X')
	{
		ax = ax + xa;
		inter_x = ax / 64;
		ay = ay + ya;
		inter_y = ay / 64;
		if (inter_x < 0 || inter_x >= WIDTH || inter_y < 0 || inter_y >= HEIGHT);
			exit (0);
	}
}

int		ft_vertical_check(t_player *p)
{
	int		ya;
	int		xa;
	int		inter_x;
	int		inter_y;

	if (ft_isright(theta))
		ay = (p->pos.y/64) * (64) - 1;
	else if (ft_isleft(theta))
		ay = (p->pos.y / 64) * 64 + 64;
	inter_y = ay / 64;
	ax = p->pos.x + (p->pos.y - ay) / tan(FOV);
	inter_x = ax / 64;

	//Find Xa
	if (ft_isright(theta))
		xa = 64;
	else if (ft_isleft(theta))
		xa = -64;
	ya = 64 / tan(FOV); //ya = 36;

	while (grid(inter_y)(inter_x) != 'X')
	{
		ax = ax + xa;
		inter_x = ax / 64;
		ay = ay + ya;
		inter_y = ay / 64;
		if (inter_x < 0 || inter_x >= WIDTH || inter_y < 0 || inter_y >= HEIGHT);
			exit (0);
	}
}

//distance needs to be calculate, check fish eye code already made
//return t_point for where the wall occurs, use tpoint in the declarations