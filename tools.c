/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/07 17:45:34 by ntom             ###   ########.fr       */
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

char		**replace_tilde(char **str, t_info *infos)
{
	int			i;
	int			x;

	if ((x = find_env(infos, "HOME")) == -1)
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i][0] == '~' && str[i][1] != '~')
			str[i] = ft_strsrepl(str[i], "~",
			ft_strchr(infos->envs[x], '=') + 1);
		i++;
	}
	return (str);
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
		if (!(infos->input =
			ft_strsrepl(infos->input, buf, (infos->envs[i] + j + 1))))
			return (1);
		if (ft_strcmp(infos->input, tmp) == 0)
			i++;
	}
	return (0);
}
