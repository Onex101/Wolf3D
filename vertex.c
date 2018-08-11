/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/25 17:50:32 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec3	*new_vertex(double x, double y, double z)
{
	t_vec3 *vertex;

	vertex = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!vertex)
		return (NULL);
	vertex->x = x;
	vertex->y = y;
	vertex->z = z;
	return (vertex);
}

t_vec3	*vertex_copy(t_vec3 *vec)
{
	t_vec3 *cpy;

	cpy = new_vertex(vec->x, vec->y, vec->z);
	return (cpy);
}

void	del_vertex(t_vec3 *vertex)
{
	if (vertex)
		free(vertex);
}