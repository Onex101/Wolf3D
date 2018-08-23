/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:34:51 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/23 20:08:45 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_init(t_vector *v)
{
	v->capacity = 64;
	v->total = 0;
	v->items = malloc(sizeof(void *) * v->capacity);
}
