/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceilling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:37:56 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:38:08 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_param_endl(char *str)
{
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ',' || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			print_error("\nInvalid color parameters\n", EINVAL);
	}
}

static void		get_floor_color(char **str, t_data *data, int j)
{
	size_t		i;
	int			r;
	int			g;
	int			b;

	i = 0;
	while (i < ft_strlen(str[j]))
	{
		if (str[j][i] == 'F' && str[j][i + 1] == ' ')
		{
			i += 1;
			check_param_endl(str[j]);
			while (str[j][i] == ' ')
				i++;
			r = ft_atoi(str[j] + i++);
			i += ft_nmbrlen(r);
			g = ft_atoi(str[j] + i++);
			i += ft_nmbrlen(g);
			b = ft_atoi(str[j] + i);
			(*data).map.floor_color = rgb_hex(r, g, b);
			(*data).map.f += 1;
			continue;
		}
		i++;
	}
}

static void		get_ceil_color(char **str, t_data *data, int j)
{
	size_t		i;
	int			r;
	int			g;
	int			b;

	i = 0;
	while (i < ft_strlen(str[j]))
	{
		if (str[j][i] == 'C' && str[j][i + 1] == ' ')
		{
			i += 1;
			check_param_endl(str[j]);
			while (str[j][i] == ' ')
				i++;
			r = ft_atoi(str[j] + i++);
			i += ft_nmbrlen(r);
			g = ft_atoi(str[j] + i++);
			i += ft_nmbrlen(g);
			b = ft_atoi(str[j] + i);
			(*data).map.ceill_color = rgb_hex(r, g, b);
			(*data).map.c += 1;
			continue;
		}
		i++;
	}
}

void			floor_and_ceilling(char **str, t_data *data, size_t map_row)
{
	size_t	j;

	j = 0;
	while (j < map_row)
	{
		get_floor_color(str, data, j);
		get_ceil_color(str, data, j);
		j++;
	}
	if ((*data).map.ceill_color < 0x000000 || (*data).map.ceill_color > 0xFFFFFF
	|| (*data).map.floor_color < 0x000000 || (*data).map.floor_color > 0xFFFFFF)
		print_error("\nColor parameters error\n", EINVAL);
	if ((*data).map.c != 1 || (*data).map.f != 1)
		print_error("\nWrong key\n", EINVAL);
}

void			rend_floor_ceilling(t_data *data)
{
	int i;
	int j;

	j = 0;
	while (j < (*data).map.win_h)
	{
		i = -1;
		while (++i < (*data).map.win_w)
			mlx_pix_put(data, 0 + i, 0 + j, (*data).map.ceill_color);
		j++;
	}
	j = 0;
	while (j < (*data).map.win_h / 2)
	{
		i = -1;
		while (++i < (*data).map.win_w)
			mlx_pix_put(data, 0 + i, (*data).map.win_h
			/ 2 + j, (*data).map.floor_color);
		j++;
	}
}
