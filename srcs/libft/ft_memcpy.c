/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 21:52:31 by ntom              #+#    #+#             */
/*   Updated: 2018/06/20 20:02:18 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*t_dst;
	const char		*t_src;

	t_dst = dst;
	t_src = src;
	while (n--)
		*t_dst++ = *t_src++;
	return (dst);
}
