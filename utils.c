/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:02:39 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 23:02:43 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float			angle_correcting(double angle)
{
	double alpha;

	alpha = angle;
	while (alpha >= 2 * M_PI)
		alpha = alpha - 2 * M_PI;
	while (alpha < 0)
		alpha = alpha + 2 * M_PI;
	return ((float)alpha);
}

double			calculate_dist(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void			mlx_pix_put(t_data *data, int x, int y, int color)
{
	char	*pos;
	int		offset;

	offset = y * (*data).img.line_length + x * ((*data).img.bits_per_pixel / 8);
	pos = (*data).img.img_addr + offset;
	*(unsigned int*)pos = color;
}

unsigned long	rgb_hex(int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		print_error("\nInvalid color parameters\n", EINVAL);
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void			print_error(char *s, int id)
{
	if (!s)
		return ;
	errno = id;
	perror("Error ");
	write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}
