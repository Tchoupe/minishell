/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:27:43 by ntom              #+#    #+#             */
/*   Updated: 2018/07/02 18:33:42 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_int(int n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (i + 1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int			ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

char				*ft_itoa(int n)
{
	size_t		i;
	char		*dest;

	i = ft_count_int(n);
	if (n < 0)
		i++;
	if (!(dest = ft_strnew(i)))
		return (NULL);
	if (n < 0)
		dest[0] = '-';
	if (n == 0)
		dest[0] = '0';
	while (i-- && n != 0)
	{
		dest[i] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (dest);
}
