/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 08:36:22 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/31 07:58:51 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void	ft_make_line(char **dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] != ' ' && src[i] != '\0')
		{
			(*dest)[j] = src[i];
			j++;
		}
		i++;
	}
	(*dest)[j] = '\0';
}

void	ft_arradd(char ***file, char *line, int size)
{
	char	**tmp;
	int		i;

	i = 0;
	if (!(tmp = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return ;
	tmp[size] = NULL;
	while (i < size)
	{
		tmp[i] = ft_strdup((*file)[i]);
		i++;
	}
	if (!(tmp[i] = (char *)malloc(sizeof(char) * (ft_wrdcnt(line, ' ') + 1))))
		return ;
	ft_make_line(&tmp[i], line);
	free_map_arr(*file, size);
	*file = tmp;
}

int		ft_readfile(char ***f, char *av)
{
	char	*line;
	int		i;
	int		fd;
	int		c;

	if (!(*f = (char **)ft_memalloc(sizeof(char *))))
		return (-1);
	if (((fd = open(av, O_RDONLY))) == -1)
		return (0);
	**f = NULL;
	i = 1;
	c = 0;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i > 0)
		{
			ft_arradd(f, line, c++);
			ft_strdel(&line);
		}
	}
	return (c);
}
