/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 01:31:04 by ntom              #+#    #+#             */
/*   Updated: 2018/06/21 17:39:08 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*str;
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(s1);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
