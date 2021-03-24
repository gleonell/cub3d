/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:58:38 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/01 22:58:42 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				get_map(char **str, t_data *data)
{
	size_t j;
	size_t i;

	j = (*data).map.map_row - 1;
	while (j > 0)
	{
		i = 0;
		while (i < ft_strlen(str[j]))
		{
			if (str[j][i] == ' ' || str[j][i] == '0' || str[j][i] == '1'
			|| str[j][i] == '2' || str[j][i] == 'N' || str[j][i] == 'E'
			|| str[j][i] == 'S' || str[j][i] == 'W')
				i++;
			else
				break ;
		}
		if (i != ft_strlen(str[j]))
			break ;
		j--;
	}
	(*data).map.map_part = &str[++j];
	if (j == 0)
		print_error("\nMap dose not exist\n", EINVAL);
	return ((*data).map.map_row - j);
}

char			**map_to_string(t_list **list, size_t map_row)
{
	char		**ptr;
	t_list		*end_to_begin;
	size_t		i;

	end_to_begin = *list;
	i = map_row;
	ptr = (char**)malloc((sizeof(char*) * i) + 2);
	while (end_to_begin && i >= 0)
	{
		ptr[i - 1] = (*end_to_begin).rows;
		end_to_begin = (*end_to_begin).next;
		i--;
	}
	ptr[map_row++] = "";
	ptr[map_row] = NULL;
	return (ptr);
}

void			check_map(t_data *data)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (j < (*data).map.map_h)
	{
		i = 0;
		len = ft_strlen((*data).map.map_part[j]);
		while (i < len)
		{
			if ((*data).map.map_part[j][i] == '0' &&
			(check_sides((*data).map.map_part, j, i) == -1))
				print_error("\nInvalid map\n", EINVAL);
			i++;
		}
		j++;
	}
}

static t_list	*push_back(char *str, t_list *pre_ptr_list)
{
	t_list	*next_list_ptr;

	if (!(next_list_ptr = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	(*next_list_ptr).rows = str;
	(*next_list_ptr).next = pre_ptr_list;
	return (next_list_ptr);
}

size_t			map_to_list(int fd, t_list **list)
{
	char	*str;
	size_t	i;

	i = 0;
	*list = NULL;
	while (get_next_line(fd, &str))
	{
		*list = push_back(str, *list);
		i++;
	}
	*list = push_back(str, *list);
	i++;
	return (i);
}
