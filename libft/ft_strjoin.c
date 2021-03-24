/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 23:12:05 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/29 21:52:21 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	n;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	n = 0;
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[n])
		str[i++] = s1[n++];
	n = 0;
	while (s2[n])
		str[i++] = s2[n++];
	str[i] = '\0';
	return (str);
}
