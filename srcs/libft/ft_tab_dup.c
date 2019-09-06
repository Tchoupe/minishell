/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 00:40:26 by ntom              #+#    #+#             */
/*   Updated: 2019/09/07 00:40:41 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tab_dup(char **str, int size)
{
	int			j;
	char		**ret;

	j = 0;
	if (size == -1)
	{
		size++;
		while (str[size])
			size++;
	}
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (str[j] && j < size)
	{
		if (!(ret[j] = ft_strdup(str[j])))
			return (NULL);
		j++;
	}
	ret[size] = NULL;
	return (ret);
}
