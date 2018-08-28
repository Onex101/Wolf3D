/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/28 07:17:41 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <string.h>
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
	if(!(tmp[i] = (char *)malloc(sizeof(char) * (ft_wrdcnt(line, ' ') + 1 ))))
		return ;
	ft_make_line(&tmp[i], line);
	free(*file);
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
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	**f = NULL;
	i = 1;
	c = 0;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i != 0)
		{
			ft_arradd(f, line, c++);
			// ft_putendl(line);
			ft_strdel(&line);
		}
	}
	return (c);
}

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

int		init_param(t_param **p, char *str, void *mlx)
{
	static int bpp;
	static int s_line;
	static int end;
	char	**file;

	if (!(*p) || !str || !mlx)
	{
		ft_putendl("FAIL");
		return (0);
	}
	if (!((*p)->map = (t_map *)malloc(sizeof(t_map))))
		return (0);	
	if (!((*p)->map->max_y = ft_readfile(&(file), str)))
		return (0);
	(*p)->map->max_x = ft_strlen(file[0]);
	(*p)->map->m = file;
	(*p)->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	(*p)->x_scale = WIDTH / (*p)->map->max_x;
	(*p)->y_scale = HEIGHT / (*p)->map->max_y;
	if(!((*p)->player = ft_player_init((*p))))
		return (0);
	(*p)->buf = (int *)mlx_get_data_addr((*p)->image, &bpp, &s_line, &end);
	(*p)->s_line = s_line;
	return (1);
}

int		draw_to_screen(t_param *p)
{
	if (p->buf)
		clear_image(p);
	draw_back(p);
	draw_map(p);
	if (!(ft_rays(p, p->player)))
		return (0);
	mlx_put_image_to_window(p->mlx, p->win, p->image, 0, 0);
	
	return (1);
}

int		main(void)
{
	t_param	*param;
	void *mlx;
	void *win;

	mlx = NULL;
	win = NULL;
	mlx =  mlx_init();
	if (mlx == NULL)
		return (-1);
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wolf3D");
	if (!win)
		return (-1);
	// if (argc == 2)
	// {
	if ((param = (t_param *)malloc(sizeof(t_param))))
	{
		if (!(init_param(&param, "maps/8", mlx)))
			return (-1);
		param->mlx = mlx;
		param->win = win;
		if (!param->mlx)
			return (-1);
		mlx_hook(win, 2, 0, key_press, param);
		//mlx_key_hook(win, key_press, param);
		mlx_loop_hook(mlx, draw_to_screen, param);
		if (mlx)
			mlx_loop(mlx);
		else
			return (-1);
	}
	//}
	return (0);
}