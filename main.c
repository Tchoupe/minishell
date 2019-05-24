/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/05/24 23:24:56 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <sys/stat.h>

static int			miniwhitespace(char c)
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
	int			i;
	int			j;
	char		**ret;

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

static char		**is_binary(char **envs, char *input)
{
	char		**path;
	int			i;

	path = NULL;
	i = 0;
	while (envs[i] && ft_strncmp("PATH=", envs[i], 5) != 0)
		i++;
	if (!(envs[i]))
		return (NULL);
	path = ft_strsplit(envs[i] + 5, ':');
	return (path);
}

static int		is_exec(char **binaries, char *input, char *buf)
{
	int			i;
	struct stat	exist;

	if (ft_strchr(input, '/'))
	{
		ft_strcpy(buf, input);
		return (1);
	}
	i = 0;
	while (binaries[i])
	{
		buf[0] = '\0';
		ft_strcat(buf, binaries[i]);
		if (buf[ft_strlen(buf) - 1] != '/')
			ft_strcat(buf, "/");
		ft_strcat(buf, input);
		if (stat(buf, &exist) != -1)
			return (1);
		i++;
	}
	buf[0] = '\0';
	return (0);
}

static int		stock_env(char **envs, char ***keys, char ***cont)
{
	int			i;

	i = 0;
	while (envs[i])
		i++;
	if (!(*keys = (char **)malloc(sizeof(char *) * (i + 1))))
		return (0);
	if (!(*cont = (char **)malloc(sizeof(char *) * (i + 1))))
		return (0);
	i = 0;
	while(envs[i])
	{
		(*keys)[i] = (ft_strndup(envs[i], ((*cont)[i]
			= (ft_strchr(envs[i], '=') + 1)) - envs[i] - 2));
		i++;
	}
	return (1);
}

static char		*ft_strsrepl(char *str, char *match, char *replacement)
{
    char    *ret;
    char    *tmp;
    size_t    total_len;

    if (!(tmp = ft_strstr(str, match)))
        return (ft_strdup(str));
    total_len = tmp - str;
    total_len += ft_strlen(replacement);
    total_len += ft_strlen(tmp + ft_strlen(match));
    if (!(ret = ft_strnew(total_len)))
        return (NULL);
    ft_strncpy(ret, str, tmp - str);
    ft_strcat(ret, replacement);
    ft_strcat(ret, tmp + ft_strlen(match));
    return (ret);
}

static	int		check_replace(char **keys, char ** cont, char **input)
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
	printf("input ==> %s\n", *input);
	return (0);
}

int				main(int argc, char **argv, char **env)
{
	char		*input;
	char		**args;
	char		**envs;
	int			i;
	char		**binaries;
	char		path[4097];
	pid_t		pid;
	int			status;
	char		**keys;
	char		**cont;

	envs = NULL;
	envs = ft_tab_dup(env);
	while (19)
	{
		keys = NULL;
		cont = NULL;
		input = NULL;
		args = NULL;
		status = 0;
		i = 0;
		path[0] = '\0';
		stock_env(envs, &keys, &cont);
		ft_putstr("$> ");
		if (get_next_line(0, &input) != 1)
		{
			ft_putstr("GNL FAILED\n");
			return (0);
		}
		check_replace(keys, cont, &input);
		args = minisplit(input);
		binaries = is_binary(envs, args[0]);
		if (is_exec(binaries, args[0], path))
		{
			if (!(access(path, X_OK)))
			{
				if ((pid = fork()) < 0)
				{
					ft_putstr("Fork error\n");
					exit(0);
				}
				else if (pid == 0)
				{
					execve(path, args, envs);
					exit(0);
				}
				else
					wait(&status);
			}
			else
				ft_putstr("cant execute\n");
		}
		else
		{
			ft_putstr("minishell: command not found: ");
			ft_putstr(args[0]);
			ft_putchar('\n');
		}
	}
	return (0);
}
