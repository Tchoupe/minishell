/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/06/08 18:19:22 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

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

int			stock_env(t_info *infos)
{
	int			i;
	char		*tmp;

	i = 0;
	while (infos->envs[i])
		i++;
	if (!(infos->keys = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (0);
	if (!(infos->cont = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (0);
	i = 0;
	while (infos->envs[i])
	{
		tmp = (ft_strchr(infos->envs[i], '=') + 1);
		(infos->cont)[i] = ft_strdup(tmp);
		(infos->keys)[i] =
			(ft_strndup(infos->envs[i], (tmp - infos->envs[i] - 2)));
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

int				main(int argc, char **argv, char **env)
{
	int			i;
	char		path[4097];
	pid_t		pid;
	t_info		infos;

	init_vars(&infos, env);
	while (19)
	{
		init_vars_prompt(&infos, &i, path);
		if (!(infos.input[0]))
			continue ;
		check_replace(&infos);
		infos.args = minisplit(infos.input, &infos.argc);
		if (is_builtin(&infos))
			continue ;
		infos.binaries = is_binary(infos.envs, infos.args[0]);
		if (is_exec(infos.binaries, infos.args[0], path))
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
					execve(path, infos.args, infos.envs);
					exit(0);
				}
				else
					wait(&infos.status);
			}
			else
				ft_putstr("cant execute\n");
		}
		else
		{
			ft_putstr("minishell: command not found: ");
			ft_putstr(infos.args[0]);
			ft_putchar('\n');
		}
	}
	return (0);
}
