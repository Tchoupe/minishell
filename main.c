/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/05/21 20:25:18 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int		miniwhitespace(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static size_t		ft_c(char const *s)
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

static char			**minisplit(char const *s)
{
	char		**str;
	size_t		i;
	size_t		j;
	size_t		start;
	size_t		len;

	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_c(s) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (j < ft_c(s))
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

static char		**ft_tab_dup(char **str)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	if (!(ret = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		ret[j] = ft_strdup(str[j]);
		j++;
	}
	ret[i] = NULL;
	return (ret);
}

int				main(int argc, char **argv, char **env)
{
	char	*input;
	char	**args;
	char	**envs;
	int		i;

	envs = NULL;
	envs = ft_tab_dup(env);
	while (19)
	{
		input = NULL;
		args = NULL;
		i = 0;
		ft_putstr("$> ");
		if (get_next_line(0, &input) != 1)
			ft_putstr("GNL FAILED\n");
		args = minisplit(input);
		//is_builtin();
		//execve(NULL, args, env);
	}
	return (0);
}
