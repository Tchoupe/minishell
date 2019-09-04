/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 01:31:04 by ntom              #+#    #+#             */
/*   Updated: 2019/09/04 15:54:47 by ntom             ###   ########.fr       */
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
	if (!(str = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
