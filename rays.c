/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:59:57 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:59:59 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ray_cast(t_data *data, t_ray *ray, float angel)
{
	(*ray).angel = angle_correcting(angel);
	ray_pointer(ray);
	if ((*ray).angel != 0 || (*ray).angel != M_PI)
		ray_horzontal_hit_wall(ray, data);
	if ((*ray).angel != (M_PI / 2) || (*ray).angel != (3 * M_PI / 2))
		ray_vertical_hit_wall(ray, data);
}

static void		ray_config(t_ray *ray, double h_d, double v_d)
{
	(*ray).wall_hit_x = (h_d < v_d) ? (*ray).h_w_h_x : (*ray).v_w_h_x;
	(*ray).wall_hit_y = (h_d < v_d) ? (*ray).h_w_h_y : (*ray).v_w_h_y;
	(*ray).distance = (h_d < v_d) ? h_d : v_d;
	(*ray).ray_hit_vertical_wall = (h_d > v_d) ? 1 : 0;
}

void			rend_rays(t_data *data)
{
	t_ray	*ray;
	int		column_id;
	float	angel;
	double	h_d;
	double	v_d;

	column_id = -1;
	angel = (*data).player.rotating - (FOV_ANGLE / 2);
	if ((*data).rays)
		free_rays_array(data);
	if (!((*data).rays = (t_ray **)malloc(sizeof(t_ray *) * data->map.rays_n)))
		exit(EXIT_FAILURE);
	while (++column_id < (*data).map.rays_n)
	{
		if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
			exit(EXIT_FAILURE);
		ray_cast(data, ray, angel);
		h_d = ((*ray).f_h_w_h) ? calculate_dist((*data).player.x,
		(*data).player.y, (*ray).h_w_h_x, (*ray).h_w_h_y) : INFINITY;
		v_d = ((*ray).f_v_w_h) ? calculate_dist((*data).player.x,
		(*data).player.y, (*ray).v_w_h_x, (*ray).v_w_h_y) : INFINITY;
		ray_config(ray, h_d, v_d);
		(*data).rays[column_id] = ray;
		angel += FOV_ANGLE / (*data).map.rays_n;
	}
}

int				is_it_wall(t_data *data, double x, double y)
{
	int map_index_x;
	int map_index_y;

	map_index_x = (int)(x / TILE_SIZE);
	map_index_y = (int)(y / TILE_SIZE);
	if (map_index_x < 0 || map_index_x > (*data).map.win_w || map_index_y < 0
	|| map_index_y > (*data).map.win_h || map_index_y >= (*data).map.map_h)
		return (-1);
	if ((int)ft_strlen((*data).map.map_part[map_index_y]) > map_index_x)
		return ((*data).map.map_part[map_index_y][map_index_x] == '1' ? 1 : 0);
	return (-1);
}

void			free_rays_array(t_data *data)
{
	int i;

	i = 0;
	while (i < (*data).map.rays_n)
	{
		if ((*data).rays[i])
			free((*data).rays[i]);
		i++;
	}
	free((*data).rays);
}
