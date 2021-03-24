/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_texture_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:42:13 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:42:19 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		find_no_so(char **str, t_data *data, int j)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(str[j]))
	{
		if (str[j][i] == 'N' && str[j][i + 1] == 'O' && str[j][i + 2] == ' ')
		{
			i += 2;
			while (str[j][i] == ' ')
				i++;
			(*data).map.path_north = &(str[j][i]);
			(*data).map.no += 1;
			continue;
		}
		if (str[j][i] == 'S' && str[j][i + 1] == 'O' && str[j][i + 2] == ' ')
		{
			i += 2;
			while (str[j][i] == ' ')
				i++;
			(*data).map.path_south = &(str[j][i]);
			(*data).map.so += 1;
			continue;
		}
		i++;
	}
}

static void		find_ea_we(char **str, t_data *data, int j)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(str[j]))
	{
		if (str[j][i] == 'E' && str[j][i + 1] == 'A' && str[j][i + 2] == ' ')
		{
			i += 2;
			while (str[j][i] == ' ')
				i++;
			(*data).map.path_east = &(str[j][i]);
			(*data).map.ea += 1;
			continue;
		}
		if (str[j][i] == 'W' && str[j][i + 1] == 'E' && str[j][i + 2] == ' ')
		{
			i += 2;
			while (str[j][i] == ' ')
				i++;
			(*data).map.path_west = &(str[j][i]);
			(*data).map.we += 1;
			continue;
		}
		i++;
	}
}

static void		find_sprite(char **str, t_data *data, int j)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(str[j]))
	{
		if (str[j][i] == 'S' && str[j][i + 1] == ' ')
		{
			i += 1;
			while (str[j][i] == ' ')
				i++;
			(*data).map.path_sprite = &(str[j][i]);
			(*data).map.sp += 1;
			continue;
		}
		i++;
	}
}

void			take_texture_path(char **str, t_data *data, size_t map_row)
{
	size_t	j;

	j = 0;
	while (j < map_row)
	{
		find_no_so(str, data, j);
		find_ea_we(str, data, j);
		find_sprite(str, data, j);
		j++;
	}
	check_key_error(data, str);
	if (!((*data).map.path_east) || !((*data).map.path_west)
	|| !((*data).map.path_south) || !((*data).map.path_north)
	|| !((*data).map.path_sprite))
		print_error("\nDid not find the textures\n", EINVAL);
}
