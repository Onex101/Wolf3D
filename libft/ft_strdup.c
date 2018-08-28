/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:54:01 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/25 10:57:04 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		t;
	char	*ret;

	i = ft_strlen(str) + 1;
	t = 0;
	ret = (char *)malloc(sizeof(char) * i);
	if (ret)
	{
		while (str[t] != '\0')
		{
			ret[t] = str[t];
			t++;
		}
		ret[t] = '\0';
		return (ret);
	}
	return (NULL);
}
