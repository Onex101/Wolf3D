/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 13:16:02 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/24 13:40:57 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] != '\0')
			dest[i] = ((unsigned char *)src)[i];
		else
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		i++;
	}
	return (dest);
}
