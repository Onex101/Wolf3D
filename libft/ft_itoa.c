/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:27:42 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/30 14:13:26 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;

	if (n == -2147483647 - 1)
		return (ft_strcpy(ft_strnew(12), "-2147483648"));
	if (n < 0)
		return (ft_strjoin("-", ft_itoa(-1 * n)));
	ret = ft_strnew(1);
	if (ret)
	{
		if (n == 0)
			return (ft_strcpy(ret, "0"));
		else if (n >= 10)
		{
			ret[0] = (n % 10) + '0';
			ret[1] = '\0';
			return (ft_strjoin(ft_itoa(n / 10), ret));
		}
		ret[0] = n + '0';
		ret[1] = '\0';
		return (ret);
	}
	return (NULL);
}
