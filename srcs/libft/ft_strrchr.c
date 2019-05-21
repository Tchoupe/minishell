/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 22:24:17 by ntom              #+#    #+#             */
/*   Updated: 2018/06/28 19:39:38 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *str;

	str = s;
	if (!*s)
		return (NULL);
	while (*s++)
		if (*s == (char)c)
			str = s;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
