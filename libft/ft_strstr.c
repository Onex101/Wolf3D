/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:25:47 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/25 11:03:52 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		s;
	char	*ret;

	i = 0;
	s = 0;
	ret = (char *)haystack;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (ret[i])
	{
		s = 0;
		while (ret[i + s] == needle[s])
		{
			if (needle[s + 1] == '\0')
				return (ret + i);
			s++;
		}
		i++;
	}
	return (0);
}
