/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:38:46 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:38:52 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	to_north(t_data *data, int i, int j)
{
	(*data).player.rotating -= M_PI / 2;
	(*data).player.x = (i + 1) * TILE_SIZE;
	(*data).player.y = (j + 1) * TILE_SIZE;
	return (1);
}

static int	to_east(t_data *data, int i, int j)
{
	(*data).player.x = (i + 1) * TILE_SIZE;
	(*data).player.y = (j + 1) * TILE_SIZE;
	return (1);
}

static int	to_south(t_data *data, int i, int j)
{
	(*data).player.rotating += M_PI / 2;
	(*data).player.x = (i + 1) * TILE_SIZE;
	(*data).player.y = (j + 1) * TILE_SIZE;
	return (1);
}

static int	to_west(t_data *data, int i, int j)
{
	(*data).player.rotating += M_PI;
	(*data).player.x = (i + 1) * TILE_SIZE;
	(*data).player.y = (j + 1) * TILE_SIZE;
	return (1);
}

void		find_player_position(t_data *data)
{
	int i;
	int j;
	int finded;

	j = -1;
	finded = 0;
	while (++j < (*data).map.map_h)
	{
		i = -1;
		while ((*data).map.map_part[j][++i])
		{
			if ((*data).map.map_part[j][i] == 'N')
				finded = finded + to_north(data, i, j);
			if ((*data).map.map_part[j][i] == 'E')
				finded = finded + to_east(data, i, j);
			if ((*data).map.map_part[j][i] == 'S')
				finded = finded + to_south(data, i, j);
			if ((*data).map.map_part[j][i] == 'W')
				finded = finded + to_west(data, i, j);
		}
	}
	if (finded != 1)
		print_error("\nError: map without player\n", EINVAL);
}
