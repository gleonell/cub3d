/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 19:55:49 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/31 02:02:14 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned const char *from;
	unsigned char		*to;
	size_t				i;

	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		if (from[i] == (unsigned char)c)
			return (to + i + 1);
		i++;
	}
	return (0);
}
