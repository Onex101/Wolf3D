/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:46:36 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 13:32:10 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*ret;

	if (s)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
		{
			ret = ft_strcpy(ft_memalloc(sizeof(char) * 2), "");
			return (ret);
		}
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		ret = ft_strsub(s, i, j - i + 1);
		if (ret)
			return (ret);
		return (NULL);
	}
	return (NULL);
}
