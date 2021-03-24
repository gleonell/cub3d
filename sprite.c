/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:01:50 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 23:01:53 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sprite_struct_init(t_data *data, t_sprite *sprite)
{
	(*sprite).spr_dir = atan2((double)((*sprite).y - (*data).player.y),
			(double)((*sprite).x - (*data).player.x));
	while ((*sprite).spr_dir - (*data).player.rotating > M_PI)
		(*sprite).spr_dir -= 2 * M_PI;
	while ((*sprite).spr_dir - (*data).player.rotating < -M_PI)
		(*sprite).spr_dir += 2 * M_PI;
	(*sprite).sprite_h = ((*data).map.win_h) * TILE_SIZE / (*sprite).distance;
	(*sprite).sprite_w = ((*data).map.win_w) * TILE_SIZE / (*sprite).distance;
	(*sprite).h_offset = ((*sprite).spr_dir - (*data).player.rotating)
	* (*data).map.win_w / (M_PI / 3) + (*data).map.win_w
	/ 2 - (*sprite).sprite_w / 2;
	(*sprite).v_offset = (*data).map.win_h / 2 - (*sprite).sprite_h / 2;
	(*sprite).i = 0;
	(*sprite).j = 0;
	(*sprite).count = fabs((*sprite).h_offset - (*data).rays[0]->distance);
	(*sprite).step = M_PI / ((*data).map.win_w * 3.0);
	(*sprite).color = 0;
}

static int	get_color(t_img *texture, int x, int y)
{
	char		*dst;

	dst = (*texture).img_addr + (y * (*texture).line_length
			+ x * ((*texture).bits_per_pixel / 8));
	return (*(int*)dst);
}

static void	draw_sprite(t_data *data, t_sprite *sprite)
{
	while ((*sprite).j < (*sprite).sprite_h - 2)
	{
		if ((*sprite).v_offset + (*sprite).j < 0
			|| (*sprite).v_offset + (*sprite).j >= (int)(*data).map.win_h)
		{
			(*sprite).j++;
			continue;
		}
		(*sprite).color = get_color(&(*data).tex[4],
				(int)((*sprite).i * ((*data).tex[4].width / TILE_SIZE)
					* TILE_SIZE / (*sprite).sprite_w),
				(int)((*sprite).j * ((*data).tex[4].height / TILE_SIZE)
					* TILE_SIZE / (*sprite).sprite_h));
		if ((*sprite).color >= 0)
			mlx_pix_put(data, (*sprite).h_offset + (*sprite).i,
					(*sprite).v_offset + (*sprite).j, (*sprite).color);
		(*sprite).j++;
	}
	(*sprite).step += M_PI / ((*data).map.win_w * 3.0);
	(*sprite).j = 0;
	(*sprite).i++;
	(*sprite).count++;
}

static void	put_sprite(t_data *data, t_sprite *sprite)
{
	sprite_struct_init(data, sprite);
	if ((*sprite).sprite_h > 2000)
		(*sprite).sprite_h = 0;
	while ((*sprite).i < (*sprite).sprite_w)
	{
		if ((*sprite).h_offset + (*sprite).i < 0 ||
			(*sprite).h_offset + (*sprite).i >= (*data).map.win_w)
		{
			(*sprite).i++;
			continue;
		}
		if ((*data).rays[(int)((int)(*sprite).h_offset + (*sprite).i)]->distance
				< (*sprite).distance)
		{
			(*sprite).i++;
			continue;
		}
		draw_sprite(data, sprite);
	}
}

void		rend_sprites(t_data *data)
{
	t_sprite	*tmp;

	tmp = (*data).sprite;
	sprites_conf(data);
	sort_sprite(data, &(*data).sprite);
	while (tmp)
	{
		if ((*tmp).distance > 30)
			put_sprite(data, tmp);
		tmp = (*tmp).next;
	}
}
