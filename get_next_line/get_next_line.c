/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:53:12 by gleonell          #+#    #+#             */
/*   Updated: 2020/08/16 22:24:49 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char		*exbuff;
	char			*newline;
	char			buff[BUFFER_SIZE + 1];
	int				bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	bytes = 0;
	newline = NULL;
	exbuff = exbuff_check(line, &exbuff, &bytes);
	while (!(exbuff) && (bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if ((newline = ft_strchr(buff, '\n')))
		{
			*newline = '\0';
			exbuff = ft_strdup(++newline);
		}
		if (!(*line = ft_gnl_strjoin(*line, buff)) || bytes < 0)
			return (-1);
	}
	if (exbuff && bytes == 0)
		free(exbuff);
	return ((bytes ? 1 : 0));
}
