/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 23:41:55 by ntom              #+#    #+#             */
/*   Updated: 2018/09/03 21:07:08 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char *dest;
	const char *src;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len--)
	{
		dest = haystack;
		src = needle;
		while (*src != '\0' && *src == *dest && dest - haystack <= (long)len)
		{
			dest++;
			src++;
			if (*src == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
