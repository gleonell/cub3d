/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 22:20:34 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/29 21:29:51 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		n;

	n = ft_strlen(s) + 1;
	str = (char*)malloc(sizeof(*str) * n);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, n);
	return (str);
}
