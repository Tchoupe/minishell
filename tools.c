/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/06/04 13:35:18 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			miniwhitespace(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

size_t		ft_c(char const *s)
{
	size_t		count;
	size_t		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (miniwhitespace(s[i]) == 1)
			i++;
		if (s[i] && miniwhitespace(s[i]) != 1)
		{
			while (s[i] && miniwhitespace(s[i]) != 1)
				i++;
			count++;
		}
	}
	return (count);
}

char		**minisplit(char const *s, int *argc)
{
	char		**str;
	size_t		i;
	size_t		j;
	size_t		start;
	size_t		len;

	if (!s)
		return (NULL);
	if (!(str = (char **)ft_memalloc(sizeof(char *) * (ft_c(s) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	*argc = ft_c(s);
	while (j < *argc)
	{
		len = 0;
		start = 0;
		while (miniwhitespace(s[i]) == 1)
			i++;
		start = i;
		while (s[i] && miniwhitespace(s[i++]) != 1)
			len++;
		str[j++] = ft_strsub(s, start, len);
	}
	str[j] = 0;
	return (str);
}

char		**ft_tab_dup(char **str)
{
	int			i;
	int			j;
	char		**ret;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		ret[j] = ft_strdup(str[j]);
		j++;
	}
	ret[i] = NULL;
	return (ret);
}

int			check_replace(char **keys, char **cont, char **input)
{
	int			i;
	char		buf[4097];

	i = 0;
	while (ft_strcmp(keys[i], "HOME") != 0)
		i++;
	*input = ft_strsrepl(*input, "~", cont[i]);
	i = 0;
	while (keys[i])
	{
		buf[0] = '\0';
		ft_strcat(buf, "$");
		ft_strcat(buf, keys[i]);
		*input = ft_strsrepl(*input, buf, cont[i]);
		i++;
	}
	return (0);
}
