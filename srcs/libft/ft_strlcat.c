/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:55:25 by ntom              #+#    #+#             */
/*   Updated: 2018/06/22 16:11:52 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i;

	size_dst = ft_strlen(dst);
	i = size_dst;
	size_src = ft_strlen(src);
	if (size <= size_dst)
		return (size + size_src);
	size = size - (size_dst + 1);
	while (i != (size_dst + size))
		dst[i++] = *src++;
	dst[i] = '\0';
	return (size_dst + size_src);
}
