/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:02:30 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 14:30:58 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		size;
	char	**ret;

	if (!s)
		return (NULL);
	size = ft_wrdcnt(s, c);
	ret = (char **)ft_memalloc(sizeof(char *) * size + 1);
	if (!ret)
		return (NULL);
	ret = ft_makearr(ret, s, c, size);
	if (!ret)
		return (NULL);
	return (ret);
}
