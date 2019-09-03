/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 22:13:16 by ntom              #+#    #+#             */
/*   Updated: 2019/09/03 15:12:38 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsrepl(char *str, char *match, char *replacement)
{
	char	*ret;
	char	*tmp;
	size_t	total_len;

	if (!(tmp = ft_strstr(str, match)))
		return (str);
	total_len = tmp - str;
	total_len += ft_strlen(replacement);
	total_len += ft_strlen(tmp + ft_strlen(match));
	if (!(ret = ft_strnew(total_len)))
		return (NULL);
	ft_strncpy(ret, str, tmp - str);
	ft_strcat(ret, replacement);
	ft_strcat(ret, tmp + ft_strlen(match));
	free(str);
	return (ret);
}
