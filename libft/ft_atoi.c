/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:29:07 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/31 02:31:38 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conv(const char *str, int nb, int sm)
{
	int r;

	r = 0;
	while (str[nb] >= '0' && str[nb] <= '9')
	{
		if ((r == 214748364) && ((str[nb] - '0') > 8) && sm == -1)
			return (0);
		else if (r > 214748364 && (ft_strlen(str) >= 11) && sm == -1)
			return (0);
		else if (r == 214748364 && ((str[nb] - '0') > 7) && sm == 1)
			return (-1);
		else if (r > 214748364 && ft_strlen(str) >= 10 && sm == 1)
			return (-1);
		r = (r * 10) + (str[nb] - '0');
		nb++;
	}
	return (r);
}

int			ft_atoi(const char *str)
{
	int nb;
	int sm;
	int res;
	int j;

	nb = 0;
	sm = 1;
	res = 0;
	j = 0;
	while (str[nb] == ' ' || str[nb] == '\t' ||
	str[nb] == '\n' || str[nb] == '\f' || str[nb] == '\v' || str[nb] == '\r')
		nb++;
	j = nb - 1;
	while ((str[nb] == '+' || str[nb] == '-') &&
	(str[j] != '-' && str[j] != '+'))
	{
		if (str[nb] == '-')
			sm = sm * (-1);
		nb++;
		j++;
	}
	res = conv(str, nb, sm);
	res *= sm;
	return (res);
}
