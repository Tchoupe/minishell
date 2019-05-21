/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 00:31:29 by ntom              #+#    #+#             */
/*   Updated: 2018/06/21 00:07:01 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str;
	const unsigned char *str1;

	str = s1;
	str1 = s2;
	while (n--)
	{
		if (*str != *str1)
			return (*str - *str1);
		str++;
		str1++;
	}
	return (0);
}
