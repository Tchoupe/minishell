/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 20:07:13 by ntom              #+#    #+#             */
/*   Updated: 2019/01/13 15:02:02 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	char	*ret;
	int		i;
	int		x;
	char	*tab;

	tab = "0123456789abcdefghjiklmnopqrstuvwxyz";
	i = base;
	x = 0;
	while ((value / i) != 0)
	{
		i *= base;
		x++;
	}
	x++;
	if (!(ret = (char*)malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	ret[x--] = '\0';
	while (x >= 0)
	{
		ret[x] = tab[value % base];
		value /= base;
		x--;
	}
	return (ret);
}
