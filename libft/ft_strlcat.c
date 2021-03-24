/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 01:05:00 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/30 21:10:04 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	char		*ptr_dest;
	const char	*ptr_src;

	if (!dest && !src)
		return (0);
	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	j = 0;
	while (ptr_dest[i] && i < size)
		i++;
	while (ptr_src[j] && (i + j + 1) < size)
	{
		ptr_dest[i + j] = ptr_src[j];
		j++;
	}
	if (i < size)
		ptr_dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
