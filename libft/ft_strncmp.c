/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 07:23:38 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/31 14:13:09 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t		i;

	i = 0;
	while (str1[i] && str2[i] && i < n - 1)
	{
		if (str1[i] == str2[i])
			i++;
		else
			break ;
	}
	if (n > 0)
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
