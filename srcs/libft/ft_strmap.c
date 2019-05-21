/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 18:24:37 by ntom              #+#    #+#             */
/*   Updated: 2018/06/28 18:43:05 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(dest = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		dest[i] = f(s[i]);
		i++;
	}
	return (dest);
}
