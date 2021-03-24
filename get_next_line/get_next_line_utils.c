/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:10:03 by gleonell          #+#    #+#             */
/*   Updated: 2020/08/16 22:36:55 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*exbuff_check(char **line, char **exbuff, int *bytes)
{
	char *newline;

	newline = NULL;
	if (!*exbuff)
		*line = ft_strdup("");
	if (*exbuff)
	{
		*bytes = 1;
		if ((newline = ft_strchr(*exbuff, '\n')))
		{
			*newline = '\0';
			*line = ft_strdup(*exbuff);
			newline++;
			newline = ft_strdup(newline);
		}
		else
			*line = ft_strdup(*exbuff);
		free(*exbuff);
	}
	return (newline);
}

int		ft_slen(const char *str)
{
	int count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char *str;
	char *ptr_newstr;
	char *tmp_str_for_free_s1;

	if (s1 == NULL || s2 == NULL)
		return ("\0");
	tmp_str_for_free_s1 = s1;
	if (!(str = (char*)malloc((ft_slen(s1) + ft_slen(s2) + 1) * sizeof(char))))
		return (NULL);
	ptr_newstr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	free(tmp_str_for_free_s1);
	return (ptr_newstr);
}

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	while (*str)
	{
		if (*str == c)
			return (str);
		++str;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_slen(str) + 1);
	if (!dest)
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
