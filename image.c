/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 06:31:29 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/07 11:30:12 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clear_image(t_param *p)
{
	int i;
	int j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (p->buf[j * WIDTH + i] != 0x000000)
				p->buf[j * WIDTH + i] = 0x000000;
			i++;
		}
		j++;
	}
}

void	pixel_put_image(t_param *p, int x, int y, int c)
{
	static int bpp;
	static int s_line;
	static int end;

	if (!s_line)
		p->buf = (int *)mlx_get_data_addr(p->image, &bpp, &s_line, &end);
	if (WIDTH * y + x < s_line * HEIGHT && WIDTH * y + x >= 0)
		p->buf[WIDTH * y + x] = mlx_get_color_value(p->mlx, c);
}