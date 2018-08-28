/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:02:51 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/23 10:26:34 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	char		chr;
	char		*s;

	i = 0;
	s = (char *)str;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (s[i] == chr)
			return (s + i);
		i++;
	}
	return (NULL);
}
