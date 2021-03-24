/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 21:56:30 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/31 02:01:56 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *mem;

	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}
