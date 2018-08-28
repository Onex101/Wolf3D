/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 07:35:53 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/28 08:58:48 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dest;

	i = 0;
	src = (unsigned char *)s2;
	dest = (unsigned char *)s1;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
		{
			i++;
			return (dest + i);
		}
		i++;
	}
	return (NULL);
}
