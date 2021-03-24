/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 03:53:02 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/30 21:08:50 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	int		i;

	src = (char *)s;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + i);
	while (i-- != 0)
	{
		if (src[i] == (char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
