/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 12:10:40 by ntom              #+#    #+#             */
/*   Updated: 2018/07/02 18:34:22 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ispace(int c)
{
	if ((c == '\t')
	|| (c == '\n')
	|| (c == ' '))
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char			*dest;
	unsigned int	start;
	size_t			len;
	size_t			i;

	if (!s)
		return (NULL);
	start = 0;
	len = 0;
	while (ft_ispace(s[start]))
		start++;
	i = start;
	while (s[i])
	{
		if (!(ft_ispace(s[i])))
			len = i - start + 1;
		i++;
	}
	if (!(dest = (char *)ft_memalloc(len + 1)))
		return (NULL);
	dest = ft_strsub(s, start, len);
	return (dest);
}
