/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 08:49:31 by shillebr          #+#    #+#             */
/*   Updated: 2018/05/31 11:38:24 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*nxt;

	tmp = (t_list *)ft_memalloc(sizeof(t_list));
	nxt = (t_list *)ft_memalloc(sizeof(t_list));
	if (!tmp || !nxt)
		return ;
	if (del == NULL)
		return ;
	tmp->next = (*alst);
	while ((tmp->next) != NULL)
	{
		nxt->next = (tmp->next)->next;
		del(tmp->next, (tmp->next)->content_size);
		tmp->next = nxt->next;
	}
	(*alst) = NULL;
}
