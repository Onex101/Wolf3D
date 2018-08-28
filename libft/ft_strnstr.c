/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 07:23:50 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/25 17:36:35 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	i;
	size_t	s;
	char	*ret;

	ret = (char *)hay;
	i = 0;
	if (ndl[i] == '\0')
		return (ret);
	while (hay[i] != '\0' && i < len)
	{
		s = 0;
		while (hay[i + s] == ndl[s] && i + s < len)
		{
			if (ndl[s + 1] == '\0')
				return (ret + i);
			s++;
		}
		i++;
	}
	return (NULL);
}
