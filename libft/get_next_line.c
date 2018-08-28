/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:22:38 by shillebr          #+#    #+#             */
/*   Updated: 2018/06/12 12:21:23 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*ft_getfd(int fd, t_line *head)
{
	t_line	*tmp;

	tmp = head;
	if (tmp->fd == fd)
		return (tmp);
	while ((tmp->fd != fd) && (tmp->next != NULL))
		tmp = tmp->next;
	if (tmp->fd == fd)
		return (tmp);
	tmp->next = (t_line *)ft_memalloc(sizeof(t_line) * 1);
	if (!(tmp->next))
		return (NULL);
	(tmp->next)->str = NULL;
	(tmp->next)->next = NULL;
	(tmp->next)->ovr = NULL;
	(tmp->next)->buf = NULL;
	(tmp->next)->nl = 0;
	(tmp->next)->n = 1;
	(tmp->next)->fd = fd;
	tmp = tmp->next;
	return (tmp);
}

int		get_str(t_line *ret)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((ret->ovr)[i] != '\n' && (ret->ovr)[i] != '\0')
		i++;
	if ((ret->ovr)[i] == '\n')
	{
		ret->str = ft_strsub(ret->ovr, 0, i);
		tmp = ft_strdup(ret->ovr + i + 1);
		ret->nl--;
		ft_memdel((void *)&ret->ovr);
		ret->ovr = tmp;
		if ((ret->ovr)[0] == '\0')
			ft_strdel((void *)&ret->ovr);
	}
	else if ((ret->ovr)[i] == '\0' && ret->n == 0)
	{
		ret->str = ft_strdup(ret->ovr);
		ft_memdel((void *)&ret->ovr);
	}
	return (1);
}

void	ft_combinelines(t_line *ret)
{
	char	*tmp;

	if ((ret->ovr) == NULL)
		ret->ovr = ft_strnew(1);
	tmp = ft_strjoin(ret->ovr, ret->buf);
	ft_memdel((void *)&ret->ovr);
	ret->ovr = tmp;
	ft_strclr(ret->buf);
}

int		get_line(t_line *ret)
{
	ret->nl = 0;
	ret->n = 1;
	if (!(ret->buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (ret->ovr != NULL)
		if (ft_strchr(ret->ovr, '\n'))
			ret->nl = 1;
	while (ret->n > 0 && ret->nl < 1)
	{
		ret->n = read(ret->fd, ret->buf, BUFF_SIZE);
		ret->buf[ret->n] = '\0';
		if (ft_strchr(ret->buf, '\n'))
			ret->nl = 1;
		ft_combinelines(ret);
	}
	ft_memdel((void *)&ret->buf);
	if (ret->n < 0)
		return (-1);
	else if (ret->n == 0 && (ret->ovr == NULL || ret->ovr[0] == '\0'))
		return (0);
	return (get_str(ret));
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*link;
	t_line			*ret;
	int				i;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!link)
	{
		link = (t_line *)ft_memalloc(sizeof(t_line) * 1);
		if (link == NULL)
			return (-1);
	}
	if ((ret = ft_getfd(fd, link)) == NULL)
		return (-1);
	i = get_line(ret);
	if ((i == 0 || i == -1) && ret->str == NULL)
		return (i);
	if ((*line = ft_strdup(ret->str)) == NULL)
		return (-1);
	ft_memdel((void **)(&ret->str));
	ret->str = NULL;
	return (i);
}
