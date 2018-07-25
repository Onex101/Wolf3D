/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 06:40:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/25 06:42:27 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_horizontal_check()
{
	int		ya;
	int		xa;

	//Find first grid intersection
	if (theta > -90 && < 90)
		ay = (player_y/64) * (64) - 1;
	else if (theta < -90 && > 90)
		ay = (player_y / 64) * 64 + 64;
	ay = ay / 64;
	ax = player_x + (player_y - ay) / tan(60);
	ax = ax / 64;

	//Find Ya
	if (theta > -90 && < 90)
		ya = -64;
	else if (theta < -90 && > 90)
		ya = 64;
	xa = 64 / tan(60); //xa = 36;

	//Coordinates of next intersection
	cx = ax + xa; //original xa val, not grid position
	cx = cx / 64;
	cy = ay + ya;
	cy = cy / 64;

	//loop through until hit a "wall"
	//
	int		inter_x;
	int		inter_y;

	if (theta > -90 && theta < 90)
		ay = (player_y/64) * (64) - 1;
	else if (theta < -90 && theta > 90)
		ay = (player_y / 64) * 64 + 64;
	inter_y = ay / 64;
	ax = player_x + (player_y - ay) / tan(60);
	inter_x = ax / 64;

	//Find Ya
	if (theta > -90 && < 90)
		ya = -64;
	else if (theta < -90 && > 90)
		ya = 64;
	xa = 64 / tan(60); //xa = 36;

	while (grid(inter_y)(inter_x) != 'X')
	{
		ax = ax + xa;
		inter_x = ax / 64;
		ay = ay + ya;
		inter_y = ay / 64;
		if (inter_x < 0 || inter_x >= screen_width || inter_y < 0 || inter_y >= screen height);
			exit (0);
	}
}