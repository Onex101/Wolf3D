/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:56:10 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/31 09:17:05 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	init_player(t_player *p)
{
	p->pos.x = 100;
	p->pos.y = 160;
	p->v_angle = ANGLE_0;
	p->hght = 32;
	p->spd = 16;
}