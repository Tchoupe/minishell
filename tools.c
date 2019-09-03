/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/03 15:15:44 by ntom             ###   ########.fr       */
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
	int			i;
	int			j;
	int			start;
	int			len;

	if (!s || !(str = (char **)ft_memalloc(sizeof(char *) * (ft_c(s) + 1))))
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

int			check_replace(t_info *infos)
{
	int			i;
	char		buf[4097];
	int			j;
	char		*str;
	char		tmp[4097];

	i = 0;
	while (infos->envs[i])
	{
		str = NULL;
		j = 0;
		buf[0] = '\0';
		tmp[0] = '\0';
		ft_strcat(buf, "$");
		while (infos->envs[i][j] != '=')
			j++;
		ft_strncat(buf, infos->envs[i], j);
		ft_strcat(tmp, infos->input);
		infos->input = ft_strsrepl(infos->input, buf, (infos->envs[i] + j + 1));
		if (ft_strcmp(infos->input, tmp) == 0)
			i++;
	}
	return (0);
}
