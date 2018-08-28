/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:19:00 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/21 08:19:03 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (dest[i] != '\0')
		i++;
	while (src[s] != '\0' && n > 0)
	{
		dest[i + s] = src[s];
		s++;
		n--;
		dest[i + s] = '\0';
	}
	return (dest);
}
