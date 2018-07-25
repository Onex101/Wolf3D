/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/25 13:51:02 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_horizontal_check(t_player *p)
{
	int		ya;
	int		xa;
	int		inter_x;
	int		inter_y;

	if (theta > -90 && theta < 90)
		ay = (p->pos.y/64) * (64) - 1;
	else if (theta < -90 && theta > 90)
		ay = (p->pos.y / 64) * 64 + 64;
	inter_y = ay / 64;
	ax = p->pos.x + (p->pos.y - ay) / tan(FOV);
	inter_x = ax / 64;

	//Find Ya
	if (theta > -90 && < 90)
		ya = -64;
	else if (theta < -90 && > 90)
		ya = 64;
	xa = 64 / tan(FOV); //xa = 36;

	while (grid(inter_y)(inter_x) != 'X')
	{
		ax = ax + xa;
		inter_x = ax / 64;
		ay = ay + ya;
		inter_y = ay / 64;
		if (inter_x < 0 || inter_x >= WIDTH || inter_y < 0 || inter_y >= HEIGHT);
			exit (0);
	}
}

int		ft_vertical_check(t_player *p)
{
	int		ya;
	int		xa;
	int		inter_x;
	int		inter_y;

	if (theta > 0 && theta < 180)
		ay = (p->pos.y/64) * (64) - 1;
	else if (theta < 0 && theta > 90)
		ay = (p->pos.y / 64) * 64 + 64;
	inter_y = ay / 64;
	ax = p->pos.x + (p->pos.y - ay) / tan(FOV);
	inter_x = ax / 64;

	//Find Ya
	if (theta > -90 && < 90)
		ya = -64;
	else if (theta < -90 && > 90)
		ya = 64;
	xa = 64 / tan(FOV); //xa = 36;

	while (grid(inter_y)(inter_x) != 'X')
	{
		ax = ax + xa;
		inter_x = ax / 64;
		ay = ay + ya;
		inter_y = ay / 64;
		if (inter_x < 0 || inter_x >= WIDTH || inter_y < 0 || inter_y >= HEIGHT);
			exit (0);
	}
}