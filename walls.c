/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:03:01 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 23:03:04 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rend_walls(t_data *data)
{
	double	dpp;
	double	distance_from_player_to_wall;
	int		column_id;
	double	scale;

	column_id = 0;
	dpp = (*data).map.win_w
	/ 2 * tanl(FOV_ANGLE / 2);
	while (column_id < (*data).map.rays_n)
	{
		(*data).map.rm_wall_heigth = 0;
		distance_from_player_to_wall = ((*data).rays[column_id]->distance)
		* cos(fabsf((*data).rays[column_id]->angel
		- (*data).player.rotating));
		(*data).map.projected_wall_heigth = (TILE_SIZE * dpp)
		/ distance_from_player_to_wall;
		if ((*data).map.projected_wall_heigth > (*data).map.win_h)
			(*data).map.rm_wall_heigth = (*data).map.projected_wall_heigth
			- (*data).map.win_h;
		scale = dpp / distance_from_player_to_wall;
		texture_walls(data, (*data).rays[column_id], column_id,
		scale);
		column_id++;
	}
}

void	texture_walls(t_data *data, t_ray *ray, int column_id, double scale)
{
	t_img	tex;
	int		tex_x;
	int		tex_y;
	char	*c;
	char	*a;

	tex_y = 0;
	scale += (scale <= 0) ? 1 : 0;
	if ((*ray).ray_hit_vertical_wall == 1)
		tex_x = (int)((*ray).wall_hit_y) % (*data).tex[0].width;
	else
		tex_x = (int)((*ray).wall_hit_x) % (*data).tex[0].width;
	tex = scale_textures(data, choose_texture(data, ray), scale, tex_x);
	while (tex_y < tex.height && tex_y < (*data).map.win_h)
	{
		c = (*data).img.img_addr + ((tex_y +
		((*data).map.win_h / 2 - (int)(*data).map.projected_wall_heigth
		/ 2 + (int)(*data).map.rm_wall_heigth / 2)) * (*data).img.line_length
		+ column_id * ((*data).img.bits_per_pixel / 8));
		a = tex.img_addr + (tex_y + (int)(*data).map.rm_wall_heigth / 2) *
		tex.line_length + 0 * (tex.bits_per_pixel / 8);
		*(unsigned int*)c = *(unsigned int*)a;
		tex_y++;
	}
}

t_img	scale_textures(t_data *data, t_img tex, double scale, int tex_x)
{
	t_img	sc_tex;
	int		y1;
	double	y2;

	sc_tex.height = tex.height * scale;
	sc_tex.width = STRIP_WIDTH;
	sc_tex.img_ptr = mlx_new_image((*data).mlx, sc_tex.width, sc_tex.height);
	sc_tex.img_addr = mlx_get_data_addr(sc_tex.img_ptr,
	&sc_tex.bits_per_pixel, &sc_tex.line_length, &sc_tex.endian);
	y1 = 0;
	y2 = 0;
	while (y1 < sc_tex.height && y2 < tex.height)
	{
		*(unsigned int*)(sc_tex.img_addr + y1 * sc_tex.line_length + 0
		* (sc_tex.bits_per_pixel / 8)) = *(unsigned int*)(tex.img_addr
		+ (int)y2 * tex.line_length + tex_x * (tex.bits_per_pixel / 8));
		y1 += 1;
		y2 += 1 / scale;
	}
	return (sc_tex);
}

t_img	choose_texture(t_data *data, t_ray *ray)
{
	if ((*ray).ray_hit_vertical_wall)
	{
		if ((*ray).angel > M_PI / 2 && (*ray).angel <= 3 * M_PI / 2)
			return ((*data).tex[3]);
		else
			return ((*data).tex[1]);
	}
	else
	{
		if ((*ray).angel > 0 && (*ray).angel <= M_PI)
			return ((*data).tex[2]);
		else
			return ((*data).tex[0]);
	}
}

int		wall_color(t_ray *ray)
{
	if ((*ray).ray_hit_vertical_wall)
		return (0xFFFFFF);
	else
		return (0xCCCCCC);
	return (0);
}
