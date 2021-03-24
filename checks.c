/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:35:32 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:35:39 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_key_error(t_data *data, char **str)
{
	int i;
	int j;

	j = 0;
	while (j < (*data).map.map_row)
	{
		i = -1;
		while (++i < (int)ft_strlen(str[j]))
		{
			if ((str[j][i] == 'R' && str[j][i + 1] == ' ')
			|| (str[j][i] == 'N' && str[j][i + 1] == 'O')
			|| (str[j][i] == 'S' && str[j][i + 1] == 'O')
			|| (str[j][i] == 'W' && str[j][i + 1] == 'E')
			|| (str[j][i] == 'E' && str[j][i + 1] == 'A')
			|| (str[j][i] == 'F' && str[j][i + 1] == ' ')
			|| (str[j][i] == 'C' && str[j][i + 1] == ' ')
			|| (str[j][i] == 'S' && str[j][i + 1] == ' ')
			|| (str[j][i] == '1') || (str[j][i] == ' ')
			|| (str[j][i] == '\n') || (str[j][i] == '\t'))
				break ;
			else
				print_error("\nWrong key\n", EINVAL);
		}
		j++;
	}
}

void			check_double_key(t_data *data)
{
	if ((*data).map.r != 1 || (*data).map.so != 1
	|| (*data).map.no != 1 || (*data).map.ea != 1
	|| (*data).map.we != 1 || (*data).map.c != 1
	|| (*data).map.f != 1 || (*data).map.sp != 1)
		print_error("\nError: double key\n", EINVAL);
}

void			check_save(t_data *data, int argc, char **argv, int fd)
{
	if (argc < 2)
		print_error("\nFew arguments\n", EINVAL);
	if (argc > 2 && ((ft_strncmp(argv[2], "--save", ft_strlen("--save")) != 0)
	|| (ft_strlen(argv[2]) != ft_strlen("--save"))))
		print_error("\nOnly --save flag is allowed\n", EINVAL);
	else if (argc > 2 &&
	((ft_strncmp(argv[2], "--save", ft_strlen("--save")) == 0)
	|| (ft_strlen(argv[2]) == ft_strlen("--save"))))
		(*data).save = 1;
	if (argc >= 2 &&
	(ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 2)) != 0)
		print_error("\nWrong file\n", EINVAL);
	if (fd < 0)
		print_error("\nFile does not exist\n", EINVAL);
}

static int		check_sides_symb(char **map_part, int j, int i)
{
	if (map_part[j][i] != '0' &&
	map_part[j][i] != '1' && map_part[j][i] != '2'
	&& map_part[j][i] != 'N' &&
	map_part[j][i] != 'S' && map_part[j][i] != 'E'
	&& map_part[j][i] != 'W')
		return (-1);
	return (1);
}

int				check_sides(char **map_part, int j, int i)
{
	if (check_sides_symb(map_part, j - 1, i - 1) == -1)
		return (-1);
	if (check_sides_symb(map_part, j - 1, i) == -1)
		return (-1);
	if (check_sides_symb(map_part, j - 1, i + 1) == -1)
		return (-1);
	if (check_sides_symb(map_part, j, i - 1) == -1)
		return (-1);
	if (check_sides_symb(map_part, j, i + 1) == -1)
		return (-1);
	if (check_sides_symb(map_part, j + 1, i - 1) == -1)
		return (-1);
	if (check_sides_symb(map_part, j + 1, i) == -1)
		return (-1);
	if (check_sides_symb(map_part, j + 1, i + 1) == -1)
		return (-1);
	return (1);
}
