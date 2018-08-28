/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 08:36:22 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/23 20:46:29 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "trig_tables.h"

void		free_str_arr(char **str_arr)
{
	int i;

	i = 0;
	while (str_arr[i])
		i++;
	while (--i >= 0)
		free(str_arr[i]);
	free(str_arr);
}

void		map_check(char *line, int *c_line)
{
	if (!*c_line)
		*c_line = ft_strcount(line, ' ');
	else if (*c_line != ft_strcount(line, ' '))
	{
		ft_putendl("Error: Map is not rectangular");
		exit(0);
	}
}

int			get_line(int fd, char *line, t_map *map, int *c_line)
{
	size_t		y;
	int			gnl;
	char		**s;
	int			x;

	y = 0;
	gnl = 0;
	while ((gnl = get_next_line(fd, &line)) != 0)
	{
		if (gnl < 0)
			return (0);
		map_check(line, c_line);
		ft_putendl(line);
		s = ft_strsplit(line, ' ');
		x = 0;
		while (s[x] != '\0')
		{
			map->wall_list[y] = ft_atoi(s[x]);
			y++;
			x++;
		}
		ft_strclr(line);
		free_str_arr(s);
	}
	if (line)
			free(line);
	map->max_x = x;
	return (y / x);
}

t_map		*read_map(int fd)
{
	char		*line;
	t_map		*map;
	size_t		y;
	int			c_line;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->wall_list = (int *)malloc(64)))
		return (NULL);
	c_line = 0;
	line = NULL;
	y = get_line(fd, line, map, &c_line);
	if (y == 0 && c_line == 0)
	{
		ft_putendl("Error: File does not exist");
		exit(0);
	}
	map->max_y = y;
	close(fd);
	return (map);
}
