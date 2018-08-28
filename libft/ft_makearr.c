/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:29:25 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 14:29:55 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_makearr(char **r, char const *s, char c, int size)
{
	int		a;
	int		i;

	if (!r)
		return (NULL);
	a = 0;
	while (*s != '\0' && a < size)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != c && s[i] != '\0')
				i++;
			r[a++] = ft_strsub(s, 0, i);
			s = s + i;
		}
		s++;
	}
	r[a] = NULL;
	return (r);
}
