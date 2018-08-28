/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 07:21:24 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 13:33:53 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*ret;

	if (s)
	{
		size = ft_strlen(s);
		i = 0;
		if (size > 0)
		{
			ret = (char *)ft_memalloc(size + 1);
			if (!ret)
				return (NULL);
			while (s[i] != '\0')
			{
				ret[i] = f(s[i]);
				i++;
			}
			ret[i] = '\0';
			return (ret);
		}
		return (NULL);
	}
	return (NULL);
}
