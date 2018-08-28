/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 07:50:04 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/31 12:12:53 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	n;
	int		i;
	long	s;

	i = ft_skpspce(str);
	n = 0;
	s = 1;
	if (str[i] == '-')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (0);
		s = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(n * s));
}
