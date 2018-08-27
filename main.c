/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:40:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/27 14:00:01 by shillebr         ###   ########.fr       */
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
		// printf("src[%d] = %c", i, src[i]);
		if (src[i] != ' ' && src[i] != '\0')
		{
			
			(*dest)[j] = src[i];
			// printf("      dest[%d] = %d", j, (*dest)[j]);
			j++;
		}
		printf("\n");
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
	// printf("i = %d c = %d  line = %s\n", i, size, line);
	while (i < size)
	{
		// printf("entered while\n");
		tmp[i] = ft_strdup((*file)[i]);
		// ft_putendl(tmp[i]);
		i++;
	}
	// printf("i = %d\nline = %s\n", i, line);
	if(!(tmp[i] = (char *)malloc(sizeof(char) * (ft_wrdcnt(line, ' ') + 1 ))))
		return ;
	// printf("test1\n");
	ft_make_line(&tmp[i], line);
	// printf("test2\n");
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
		// printf("i = %d    c = %d\n", i, c);
		if (i != 0)
		{
			// printf("line = %s\n", line);
			ft_arradd(f, line, c++);
			ft_putendl(line);
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
		printf("FAIL\n");
	}
	if (!((*p)->map = (t_map *)malloc(sizeof(t_map))))
		return (0);	
	if (!((*p)->map->max_y = ft_readfile(&(file), str)))
		return (0);
	(*p)->map->max_x = ft_strlen(file[0]);
	(*p)->map->m = file;
	(*p)->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	(*p)->x_scale = WIDTH / (*p)->map->max_x;
	printf("x_scale [%d] = WIDTH / map->max_x [%d]\n", (*p)->x_scale, (*p)->map->max_x);
	(*p)->y_scale = HEIGHT / (*p)->map->max_y;
	printf("y_scale [%d] = WIDTH / map->max_y [%d]\n", (*p)->y_scale, (*p)->map->max_y);
	if(!((*p)->player = ft_player_init((*p))))
		return (0);
	(*p)->buf = (int *)mlx_get_data_addr((*p)->image, &bpp, &s_line, &end);
	(*p)->s_line = s_line;
	return (1);
}

void	ft_print_arr(char **s, t_param *p)
{
	int		i;
	int		j;

	j = 0;
	while (j < p->map->max_y )
	{
		i = 0;
		while (s[j][i])
		{
			printf(" %c",s[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

int		draw_to_screen(t_param *p)
{
	// ft_print_arr(p->map->m, p);
	printf("test1\n");
	if (p->buf)
	{
		// sleep(1);
		clear_image(p);
	}
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
	if (!win)
		return (-1);
	// if (argc == 2)
	// {
	if ((param = (t_param *)malloc(sizeof(t_param))))
	{
		if (!(init_param(&param, "maps/8", mlx)))
			return (-1);
		printf("main 1\n");
		param->mlx = mlx;
		printf("main 2\n");
		param->win = win;
		printf("main 3\n");
		if (!param->mlx)
			return (-1);
		printf("main 4\n");
		mlx_hook(win, 2, 0, key_press, param);
		// mlx_key_hook(win, key_press, param);
		printf("main 5\n");
		mlx_loop_hook(mlx, draw_to_screen, param);
		printf("main 6\n");
		if (mlx)
			mlx_loop(mlx);
		else
			return (-1);
	}
	//}
	return (0);
}

// int		main(void)
// {
// 	void 	*mlx;
// 	void 	*win;
// 	t_param	*param;

// 	mlx =  mlx_init();
// 	// while (1)
// 	// {
// 		// if (mlx)
// 	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wolf3D");
// 		// printf("main 1\n");
// 	if (!(param = (t_param *)malloc(sizeof(t_param))))
// 		return (-1);
// 		// printf("main 2\n");
// 	if (!(init_param(&param, "maps/8", mlx)))
// 		return (-1);
// 		// printf("main 3\n");
// 		// free(param->map->m);
// 		// free(param->map);
// 		// free(param);
// 		// if (win)
// 	// mlx_destroy_window(mlx, win);
// 		// win = NULL;
// 	// }
// 	// printf("main 4\n");
// 	mlx_loop(mlx);
// 	return (0);
// }