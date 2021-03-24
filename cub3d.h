/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:37:22 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:37:28 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define TILE_SIZE 32
# define STRIP_WIDTH 1
# define FOV_ANGLE 60 * M_PI / 180
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx_dylib/mlx.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

typedef struct	s_list
{
	char			*rows;
	struct s_list	*next;
}				t_list;

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct	s_player
{
	double		x;
	double		y;
	double		radius;
	float		rotating;
	double		speeding;
	double		rotating_speed;
}				t_player;

typedef struct	s_ray
{
	float	angel;
	double	wall_hit_x;
	double	wall_hit_y;
	double	h_w_h_x;
	double	h_w_h_y;
	double	v_w_h_x;
	double	v_w_h_y;
	double	distance;
	double	hit_sprite;
	double	x_step;
	double	y_step;
	double	dx;
	double	dy;
	double	next_horz_y;
	double	next_horz_x;
	double	next_vert_y;
	double	next_vert_x;
	int		point_up;
	int		point_down;
	int		point_right;
	int		point_left;
	int		ray_hit_vertical_wall;
	int		f_h_w_h;
	int		f_v_w_h;
}				t_ray;

typedef struct	s_map
{
	int				r;
	int				no;
	int				ea;
	int				so;
	int				we;
	int				sp;
	int				f;
	int				c;
	int				win_h;
	int				win_w;
	char			*path_north;
	char			*path_east;
	char			*path_south;
	char			*path_west;
	char			*path_sprite;
	char			**map_part;
	int				map_row;
	int				map_h;
	double			map_size;
	double			projected_wall_heigth;
	double			rm_wall_heigth;
	int				screen_size_x;
	int				screen_size_y;
	int				rays_n;
	unsigned long	ceill_color;
	unsigned long	floor_color;
}				t_map;

typedef struct	s_sprite
{
	double	spr_dir;
	int		i;
	int		j;
	double	step;
	int		count;
	int		color;
	int		x;
	int		y;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	dir;
	double	distance;
	double	ray_hit_x;
	double	ray_hit_y;
	int		sprite_w;
	int		sprite_h;
	double	h_offset;
	double	v_offset;
	void	*next;
}				t_sprite;

typedef struct	s_data
{
	double		depth_buffer[1920];
	void		*mlx;
	void		*mlx_win;
	char		**str;
	int			save;
	t_map		map;
	t_player	player;
	t_ray		**rays;
	t_img		img;
	t_img		tex[5];
	t_sprite	*sprite;
	t_sprite	*out;
	t_sprite	*q;
	t_sprite	*p;
	t_sprite	*pr;

}				t_data;

unsigned long	rgb_hex(int r, int g, int b);
size_t			map_to_list(int fd, t_list **list);
char			**map_to_string(t_list **list, size_t map_row);
void			rend_floor_ceilling(t_data *data);
void			rend_rays(t_data *data);
void			free_rays_array(t_data *data);
void			ray_pointer(t_ray *ray);
void			ray_vertical_hit_wall(t_ray *ray, t_data *data);
void			ray_horzontal_hit_wall(t_ray *ray, t_data *data);
void			sprites_conf(t_data *data);
void			screenshot(t_data *data);
void			sprites_pos(t_data *data);
void			rend_sprites(t_data *data);
void			check_double_key(t_data *data);
void			check_key_error(t_data *data, char **str);
void			find_player_position(t_data *data);
void			win_params(t_data *data);
void			floor_and_ceilling(char **str, t_data *data, size_t map_row);
void			take_texture_path(char **str, t_data *data, size_t map_row);
void			moving(int keycode, t_data *data);
void			check_player(int detcted);
void			check_save(t_data *data, int argc, char **argv, int fd);
void			print_error(char *s, int id);
void			put_textures(t_data *data);
void			check_map(t_data *data);
void			mlx_pix_put(t_data *data, int x, int y, int color);
void			rend_walls(t_data *data);
void			texture_walls(t_data *data, t_ray *ray, int column_id,
				double scale);
float			angle_correcting(double angle);

double			calculate_dist(double x1, double y1,
				double x2, double y2);
int				safe_distance(t_data *data, double player_x, double player_y);
int				mlx_close(t_data *data);
int				is_it_wall(t_data *data, double x, double y);
int				wall_color(t_ray *ray);
int				check_sides(char **map_part, int j, int i);
int				get_map(char **ptr, t_data *data);
int				point_in_vert_segment(t_data *data, t_ray *ray,
				t_sprite *sprite, int column_id);
int				point_in_horz_segment(t_data *data, t_ray *ray,
				t_sprite *sprite, int column_id);
int				point_in_segment(t_data *data, t_ray *ray,
				t_sprite *sprite, int column_id);
t_sprite		*sort_sprite(t_data *all, t_sprite **ph);
t_img			scale_textures(t_data *data, t_img tex,
				double scale, int tex_x);
t_img			choose_texture(t_data *data, t_ray *ray);

#endif
