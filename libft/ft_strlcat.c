/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:18:45 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/21 13:25:35 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	si;

	dlen = 0;
	slen = ft_strlen(src);
	si = 0;
	while (dest[dlen] && size > 0)
	{
		dlen++;
		size--;
	}
	while (src[si] && size-- > 1)
	{
		dest[dlen + si] = src[si];
		si++;
		dest[dlen + si] = '\0';
	}
	if (size == 1 || src[si] == '\0')
		dest[dlen + si] = '\0';
	return (dlen + slen);
}
