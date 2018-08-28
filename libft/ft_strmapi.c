/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:29:47 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 13:34:49 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			size;
	char			*ret;

	i = 0;
	if (s)
	{
		size = ft_strlen(s);
		if (size > 0)
		{
			ret = (char *)ft_memalloc(sizeof(char) * (size + 1));
			if (!ret)
				return (NULL);
			while (s[i])
			{
				ret[i] = f(i, (char)s[i]);
				i++;
			}
			ret[i] = '\0';
			return (ret);
		}
		return (NULL);
	}
	return (NULL);
}
