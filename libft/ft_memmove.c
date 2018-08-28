/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:49:50 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 14:11:51 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*dest;
	char	*src;

	dest = (char *)str1;
	src = (char *)str2;
	if (dest > src)
	{
		while (n-- > 0)
			dest[n] = src[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
