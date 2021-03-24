/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:49:29 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/31 02:02:17 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src;

	src = (unsigned char *)s;
	while (n--)
	{
		if (*src != (unsigned char)c)
			src++;
		else
			return (src);
	}
	return (NULL);
}
