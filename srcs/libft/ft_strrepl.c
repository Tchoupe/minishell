/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 22:13:16 by ntom              #+#    #+#             */
/*   Updated: 2019/06/15 17:11:20 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char		*ft_strsrepl(char *str, char *match, char *replacement)
// {
// 	char	*ret;
// 	char	*tmp;
// 	size_t	total_len;
//
// 	if (!(tmp = ft_strstr(str, match)))
// 		return (ft_strdup(str));
// 	total_len = tmp - str;
// 	total_len += ft_strlen(replacement);
// 	total_len += ft_strlen(tmp + ft_strlen(match));
// 	if (!(ret = ft_strnew(total_len)))
// 		return (NULL);
// 	ft_strncpy(ret, str, tmp - str);
// 	ft_strcat(ret, replacement);
// 	ft_strcat(ret, tmp + ft_strlen(match));
// 	return (ret);
// }

static char	*ft_strsj1(char *s1, int i, char *s2, int j)
{
	char	c2;
	char	*s;

	c2 = '\0';
	if (s1 && s1[i] && i != -1)
		s1[i] = '\0';
	if (s2 && s2[j] && i != -1)
	{
		c2 = s2[j];
		s2[j] = '\0';
	}
	if (s1 == NULL)
		s = ft_strdup(s2);
	else if (s2 == NULL)
		s = ft_strdup(s1);
	else
		s = ft_strjoin(s1, s2);
	if (c2 != '\0')
		s2[j] = c2;
	free(s1);
	s1 = NULL;
	return (s);
}


static char	*ft_strsj(char *s1, int i, char *s2, int j)
{
	char	c1;
	char	c2;
	char	*s;

	c1 = '\0';
	c2 = '\0';
	if (s1 && i != -1 && s1[i])
	{
		c1 = s1[i];
		s1[i] = '\0';
	}
	if (s2 && j != -1 && s2[j])
	{
		c2 = s2[j];
		s2[j] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		s = (!s1) ? ft_strdup(s2) : ft_strdup(s1);
	else
		s = ft_strjoin(s1, s2);
	if (c1 != '\0')
		s1[i] = c1;
	if (c2 != '\0')
		s2[j] = c2;
	return (s);
}


char	*ft_strsrepl(char *str, char *s1, char *s2)
{
	char	*new_str;
	char	*tmp;

	if (!(tmp = ft_strstr((const char *)str, (const char *)s1)))
	{
		free(str);
		return (NULL);
	}
	new_str = ft_strsj(str, tmp - str, s2, -1);
	if (new_str)
		new_str = ft_strsj1(new_str, -1, &str[tmp - str + ft_strlen(s1)], -1);
	free(str);
	return (new_str);
}
