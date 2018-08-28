/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:49:00 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 14:32:29 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		i;
	char		*ret;

	i = ft_strlen(str) + 1;
	ret = (char *)str;
	while (i-- > 0)
	{
		if (ret[i] == (unsigned char)c)
			return (ret + i);
	}
	return (NULL);
}
