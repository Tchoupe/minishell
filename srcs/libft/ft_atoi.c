/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:51:26 by ntom              #+#    #+#             */
/*   Updated: 2018/07/03 16:37:46 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_whilespace(const char *str)
{
	int i;

	i = 0;
	while (((str[i] == '\t')
	|| (str[i] == '\n')
	|| (str[i] == '\v')
	|| (str[i] == '\f')
	|| (str[i] == '\r')
	|| (str[i] == ' '))
	&& (str[i]))
		i++;
	return (i);
}

int				ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;
	size_t			i;

	result = 0;
	i = ft_whilespace(str);
	sign = str[i] == '-' ? -1 : 1;
	i += str[i] == '-' || str[i] == '+';
	while (ft_isdigit(str[i]))
		result = ((result * 10) + (str[i++] - 48));
	if (result > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	return ((int)(result * sign));
}
