/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 12:00:01 by ntom              #+#    #+#             */
/*   Updated: 2019/06/09 16:39:39 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_c(char const *s, char c)
{
	size_t		count;
	size_t		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		j;
	size_t		start;
	size_t		len;

	if (!s)
		return (NULL);
	if (!(str = (char **)ft_memalloc(sizeof(char *) * (ft_c(s, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (j < ft_c(s, c))
	{
		len = 0;
		start = 0;
		while (s[i] == c)
			i++;
		start = i;
		while (s[i++] != c)
			len++;
		str[j++] = ft_strsub(s, start, len);
		printf("str[%lu] => %s\n", (j - 1), str[j - 1]);
	}
	str[j] = 0;
	return (str);
}
