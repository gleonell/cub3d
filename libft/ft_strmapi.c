/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:49:44 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/29 17:20:26 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_mems(void *b, int c, size_t len)
{
	unsigned char *str;

	str = b;
	while (len--)
		*str++ = c;
	return (b);
}

static void		*ft_memall(size_t size)
{
	void *ptr;

	if ((ptr = malloc(size)))
		ptr = ft_mems(ptr, 0, size);
	else
		return (NULL);
	return (ptr);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		len;
	char		*str;

	if (s && f)
	{
		len = ft_strlen(s);
		str = ft_memall(len + 1);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (i < len && s[i] && str)
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
