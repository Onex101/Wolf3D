/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:35:02 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/15 17:36:35 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_resize(t_vector *v, int capacity)
{
	void **items;

	ft_putendl("vec resize test 1");
	items = (void **)malloc(sizeof(void *) * capacity);
	ft_putendl("vec resize test 2");
	if (!items)
	{
		ft_putendl_fd("Items malloc error", 2);
		return ;
	}
	ft_putendl("vec resize test 3");
	ft_memcpy(items, v->items, sizeof(void *) * v->capacity);
	ft_putendl("vec resize test 4");
	// if (v->items)
	// 	free(v->items);
	ft_putendl("vec resize test 5");
	if (items)
	{
		ft_putendl("vec resize test 6");
		v->items = items;
		ft_putendl("vec resize test 7");
		v->capacity = capacity;
		ft_putendl("vec resize test 8");
	}
	ft_putendl("vec resize test 9");
}
