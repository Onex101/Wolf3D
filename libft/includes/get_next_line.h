/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:23:50 by shillebr          #+#    #+#             */
/*   Updated: 2018/06/08 07:00:45 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 32

typedef struct		s_line
{
	int				fd;
	char			*str;
	char			*ovr;
	char			*buf;
	int				nl;
	int				n;
	int				os;
	struct s_line	*next;
}					t_line;
int					get_next_line(const int fd, char **line);

#endif
