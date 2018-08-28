/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:39:20 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/29 09:46:15 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 && s2)
	{
		ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (ret)
		{
			ft_strcpy(ret, s1);
			ft_strcat(ret, s2);
			return (ret);
		}
		return (NULL);
	}
	return (NULL);
}
