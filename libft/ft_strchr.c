/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:26:17 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/24 14:08:42 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	chr;
	size_t	i;

	chr = (char)c;
	i = -1;
	while (str[++i] != chr)
		if (!str[i])
			return (NULL);
	return ((char*)(str + i));
}
