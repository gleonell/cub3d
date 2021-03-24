/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:34:54 by gleonell          #+#    #+#             */
/*   Updated: 2020/12/06 19:35:10 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

int		ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int		ft_nmbrlen(int num)
{
	int size;

	size = 1;
	while (num / 10)
	{
		num = num / 10;
		size++;
	}
	return (size);
}
