/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:43:27 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:43:31 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	new_player_pos(t_data *data, double new_x, double new_y)
{
	(*data).player.y = new_y;
	(*data).player.x = new_x;
}

void		moving(int keycode, t_data *data)
{
	double	new_x;
	double	new_y;

	new_y = (*data).player.y;
	new_x = (*data).player.x;
	if (keycode == 13)
	{
		new_y += sin((*data).player.rotating) * (*data).player.speeding;
		new_x += cos((*data).player.rotating) * (*data).player.speeding;
	}
	if (keycode == 1)
	{
		new_y -= sin((*data).player.rotating) * (*data).player.speeding;
		new_x -= cos((*data).player.rotating) * (*data).player.speeding;
	}
	if (keycode == 0)
		(*data).player.rotating -= (*data).player.rotating_speed;
	if (keycode == 2)
		(*data).player.rotating += (*data).player.rotating_speed;
	if (keycode == 53)
		mlx_close(data);
	if (safe_distance(data, new_x, new_y) != -1)
		new_player_pos(data, new_x, new_y);
}

int			mlx_close(t_data *data)
{
	if (data == 0)
		exit(EXIT_SUCCESS);
	mlx_destroy_window((*data).mlx, (*data).mlx_win);
	exit(EXIT_SUCCESS);
}

int			safe_distance(t_data *data, double player_x, double player_y)
{
	int		i;
	int		j;
	double	radius;

	radius = (*data).player.radius - 10;
	j = -1 * radius;
	while (j <= radius)
	{
		i = -1 * radius;
		while (i <= radius)
		{
			if (i * i < radius * radius - j * j)
			{
				if (is_it_wall(data, player_x + i, player_y + j))
					return (-1);
			}
			i++;
		}
		j++;
	}
	return (1);
}
