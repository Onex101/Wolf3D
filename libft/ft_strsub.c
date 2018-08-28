/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 08:06:56 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 14:03:27 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (s)
	{
		ret = ft_strnew(len);
		if (ret)
		{
			ft_strncpy(ret, s + start, len);
			ret[len] = '\0';
			return (ret);
		}
		return (NULL);
	}
	return (NULL);
}
