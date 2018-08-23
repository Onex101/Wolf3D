/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_tables_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:50:26 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/23 14:58:58 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trig_tables.h"

double	cos_d(double i)
{
	return (cos((i * M_PI) / 180));
}

double	sin_d(double i)
{
	return (sin((i * M_PI) / 180));
}

double	tan_d(double i)
{
	return (tan((i * M_PI) / 180));
}
