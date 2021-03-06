/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 08:36:22 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/30 09:41:56 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "wolf3d.h"

void		free_str_arr(char **str_arr)
{
	int i;

	i = 0;
	while (str_arr[i])
		i++;
	while (--i)
		free(str_arr[i]);
	free(str_arr);
}

void			map_check(char *line, int *c_line)
{
	if (!*c_line)
		*c_line = ft_strcount(line, ' ');
	else if (*c_line != ft_strcount(line, ' '))
	{
		ft_putendl("Error: Map is not rectangular");
		exit(0);
	}
}

void		create_vertex_list(t_map *map, char *line, int y)
{
	char			**s;
	size_t			x;
	t_vec3			*v;

	x = 0;
	s = ft_strsplit(line, ' ');
	while (s[x])
	{
		v = new_vertex(x, y, ft_atoi(s[x]));
		vector_add(map->ver_vec, v);
		x++;
	}
	map->max_x = x;
	ft_strclr(line);
	free_str_arr(s);
}

t_map		*read_map(int fd)
{
	char		*line;
	t_map		*map;
	size_t		y;
	int			c_line;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->ver_vec = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	vector_init(map->ver_vec);
	y = 0;
	c_line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map_check(line, &c_line);
		ft_putendl(line);
		create_vertex_list(map, line, y);
		y++;
	}
	if (y == 0 && c_line == 0)
	{
		ft_putendl("Error: File does not exist");
		exit(0);
	}
	free(line);
	map->max_y = y;
	close(fd);
	return (map);
}