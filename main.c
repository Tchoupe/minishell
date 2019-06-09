/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/06/09 22:33:56 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char			**is_binary(t_info *infos)
{
	char			**path;
	int				i;

	path = NULL;
	i = 0;
	while (infos->keys[i] && ft_strcmp("PATH", infos->keys[i]) != 0)
		i++;
	if (!(infos->keys[i]))
		return (NULL);
	path = ft_strsplit(infos->cont[i], ':');
	return (path);
}

static int			is_exec(char **binaries, char *input, char *buf)
{
	int				i;
	struct stat		exist;

	if (!binaries)
		return (1);
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

static void			forking(t_info *infos, char *path)
{
	pid_t			pid;

	if (!(access(path, X_OK)))
	{
		if ((pid = fork()) < 0)
		{
			ft_putstr("Fork error\n");
			exit(0);
		}
		else if (pid == 0)
		{
			execve(path, infos->args, infos->envs);
			exit(0);
		}
		else
			wait(&infos->status);
	}
	else
		ft_putstr("Cannot execute\n");
}

int					stock_env(t_info *infos)
{
	int				i;
	char			*tmp;

	i = 0;
	while (infos->envs[i])
		i++;
	if (!(infos->keys = (char **)ft_memalloc(sizeof(char *) * (i + 1)))
	|| !(infos->cont = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (0);
	i = 0;
	while (infos->envs[i])
	{
		tmp = (ft_strchr(infos->envs[i], '=') + 1);
		(infos->cont)[i] = ft_strdup(tmp);
		(infos->keys)[i] =
			(ft_strndup(infos->envs[i], (tmp - infos->envs[i] - 1)));
		if (ft_strcmp(infos->keys[i], "HOME") == 0)
			infos->home = infos->cont[i];
		else if (ft_strcmp(infos->keys[i], "PWD") == 0)
			getcwd(infos->pwd, 4097);
		else if (ft_strcmp(infos->keys[i], "OLDPWD") == 0)
			ft_strcat(infos->oldpwd, infos->cont[i]);
		i++;
	}
	return (1);
}

int					main(int argc, char **argv, char **env)
{
	int				i;
	t_info			infos;
	char			path[4097];

	init_vars(&infos, env, argc, argv);
	while (19)
	{
		if (init_vars_prompt(&infos, &i, path) != 0 || !(infos.input[0]))
			continue ;
		check_replace(&infos);
		infos.args = minisplit(infos.input, &infos.argc);
		if (!infos.args[0] || is_builtin(&infos))
			continue ;
		infos.binaries = is_binary(&infos);
		if (is_exec(infos.binaries, infos.args[0], path))
			forking(&infos, path);
		else
		{
			ft_putstr("minishell: command not found: ");
			ft_putstr(infos.args[0]);
			ft_putchar('\n');
		}
	}
	return (0);
}
