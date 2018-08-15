/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:34:01 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/15 18:29:01 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

void	vector_add(t_vector *v, void *item)
{
	printf("total = %f\n", v->total);
	ft_putendl("vec add test 1");
	if (v->capacity == v->total)
	{
		ft_putendl("vec add test 2");
		vector_resize(v, v->capacity * 2);
		ft_putendl("vec add test 3");
	}
	ft_putendl("vec add test 4");
	printf("total = %f\n", v->total);
	v->items[(int)(v->total)] = item;
	(v->total)++;
	ft_putendl("vec add test 5");
}
