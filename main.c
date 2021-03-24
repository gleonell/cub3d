/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:43:54 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:43:59 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	start_settings(t_data *data)
{
	(*data).map.r = 0;
	(*data).map.no = 0;
	(*data).map.ea = 0;
	(*data).map.so = 0;
	(*data).map.we = 0;
	(*data).map.sp = 0;
	(*data).map.c = 0;
	(*data).map.f = 0;
	(*data).map.map_part = NULL;
	(*data).map.map_h = -1;
	(*data).map.map_size = 0.3;
	(*data).map.win_h = -1;
	(*data).map.win_w = -1;
	(*data).player.x = 0;
	(*data).player.y = 0;
	(*data).player.radius = 16;
	(*data).player.speeding = 9.0;
	(*data).player.rotating_speed = 4 * (M_PI / 180);
	(*data).player.rotating = 0;
	(*data).map.floor_color = -1;
	(*data).map.ceill_color = -1;
	(*data).sprite = NULL;
	(*data).save = 0;
}

static int	rend_begin(int keycode, t_data *data)
{
	t_img	put_img;

	moving(keycode, data);
	rend_floor_ceilling(data);
	rend_rays(data);
	rend_walls(data);
	rend_sprites(data);
	put_img = (*data).img;
	mlx_put_image_to_window((*data).mlx,
	(*data).mlx_win, put_img.img_ptr, 0, 0);
	return (1);
}

static void	read_map(t_data *data)
{
	find_player_position(data);
	take_texture_path((*data).str, data, (*data).map.map_row);
	put_textures(data);
	floor_and_ceilling((*data).str, data, (*data).map.map_row);
	check_double_key(data);
}

static void	mlx_call(t_data *data)
{
	(*data).mlx = mlx_init();
	(*data).mlx_win = mlx_new_window((*data).mlx, (*data).map.win_w,
	(*data).map.win_h, "Cub3D");
	(*data).img.img_ptr = mlx_new_image((*data).mlx, (*data).map.win_w,
	(*data).map.win_h);
	(*data).img.img_addr = mlx_get_data_addr((*data).img.img_ptr,
	&(*data).img.bits_per_pixel, &(*data).img.line_length, &(*data).img.endian);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_data	data;
	t_list	*list;

	start_settings(&data);
	fd = open(argv[1], O_RDONLY);
	check_save(&data, argc, argv, fd);
	data.map.map_row = map_to_list(fd, &list);
	data.str = map_to_string(&list, data.map.map_row);
	win_params(&data);
	data.map.map_h = get_map(data.str, &data);
	check_map(&data);
	sprites_pos(&data);
	mlx_call(&data);
	read_map(&data);
	rend_begin(13, &data);
	if (data.save == 1)
		screenshot(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, rend_begin, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, mlx_close, 0);
	mlx_loop(data.mlx);
	return (0);
}
