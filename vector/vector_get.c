/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:34:44 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/23 14:30:41 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*vector_get(t_vector *v, int index)
{
	if (index >= 0 && index < v->total)
	{
		return (v->items[index]);
	}
	return (NULL);
}
