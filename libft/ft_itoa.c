/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 14:18:38 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/31 02:02:12 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nb_len(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	while (nb > 9)
	{
		nb /= 10;
		++len;
	}
	return (len + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nb;
	unsigned int	num;
	unsigned int	len;

	if (n < 0)
		nb = (unsigned int)(n * -1);
	else
		nb = (unsigned int)n;
	len = (unsigned int)get_nb_len(nb);
	num = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[num] = '-'))
		len++;
	num = len - 1;
	while (nb > 9)
	{
		str[num--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[num] = (char)(nb % 10 + 48);
	str[len] = '\0';
	return (str);
}
