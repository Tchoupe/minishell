/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 22:04:24 by ntom              #+#    #+#             */
/*   Updated: 2018/06/20 21:07:14 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*t_dst;
	const unsigned char	*t_src;
	unsigned char		x;

	x = c;
	t_dst = (unsigned char *)dst;
	t_src = (const unsigned char *)src;
	while (n--)
	{
		if ((*t_dst++ = *t_src++) == x)
			return (t_dst);
	}
	return (NULL);
}
