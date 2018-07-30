/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 07:43:48 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/30 07:44:47 by shillebr         ###   ########.fr       */
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