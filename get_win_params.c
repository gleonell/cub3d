/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:39:42 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:39:46 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_param_end(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			print_error("\nInvalid R parameters\n", EINVAL);
		i++;
	}
}

static void	screen_size(t_data *data)
{
	int size_x;
	int size_y;

	if ((*data).map.win_w == -1 || (*data).map.win_h == -1)
		print_error("\nThe resolution key does not exist\n", EINVAL);
	mlx_get_screen_size((*data).mlx_win, &size_x, &size_y);
	if ((*data).map.win_h > size_y || (*data).map.win_h > INT32_MAX)
		(*data).map.win_h = size_y;
	if ((*data).map.win_w > size_x || (*data).map.win_w > INT32_MAX)
		(*data).map.win_w = size_x;
	if ((*data).map.win_h <= 0 || (*data).map.win_w <= 0)
		print_error("\nInvalid r parameters\n", EINVAL);
	(*data).map.rays_n = (*data).map.win_w / STRIP_WIDTH;
}

void		win_params(t_data *data)
{
	size_t	j;
	size_t	i;

	j = -1;
	while (++j < (size_t)(*data).map.map_row)
	{
		i = -1;
		while (++i < ft_strlen((*data).str[j]) && (*data).str[j][i] != '\0')
		{
			if ((*data).str[j][i++] == 'R')
			{
				(*data).map.r = (*data).map.r + 1;
				while ((*data).str[j][i] == ' ')
					i++;
				(*data).map.win_w = ft_atoi((*data).str[j] + i);
				i = i + ft_nmbrlen((*data).map.win_w);
				while ((*data).str[j][i] == ' ')
					i++;
				(*data).map.win_h = ft_atoi((*data).str[j] + i);
				i = i + ft_nmbrlen((*data).map.win_h);
				check_param_end((*data).str[j] + i);
			}
		}
	}
	screen_size(data);
}
