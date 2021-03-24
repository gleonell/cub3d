/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:47:05 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/31 02:02:25 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*to;
	unsigned const char	*from;

	if (n == 0 || src == dest)
		return (dest);
	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	if (to < from)
	{
		while (n--)
			*to++ = *from++;
		return (dest);
	}
	while (n-- > 0)
		to[n] = from[n];
	return (dest);
}
