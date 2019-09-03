/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/09/03 14:11:28 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int				find_env(t_info *infos, char *needle)
{
	int				i;
	int				j;

	i = 0;
	while (infos->envs[i])
	{
		j = 0;
		while (infos->envs[i][j] && needle[j])
		{
			if (infos->envs[i][j] == '=' && needle[j] == '\0')
				return (i);
			if (infos->envs[i][j] != needle[j])
				break ;
			j++;
		}
		i++;
	}
	return (-1);
}

static char			**is_binary(t_info *infos)
{
	char			**path;
	int				i;
	int				j;

	path = NULL;
	j = 0;
	if ((i = find_env(infos, "PATH")) == -1)
		return (NULL);
	while (infos->envs[i][j] != '=')
		j++;
	path = ft_strsplit((infos->envs[i] + j), ':');
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
		{
			signal(SIGINT, proghandler);
			wait(&infos->status);
			signal(SIGINT, c_handler);
		}
	}
	else
		ft_putstr("Cannot execute\n");
}

int					main(int argc, char **argv, char **env)
{
	int				i;
	t_info			infos;
	char			path[4097];

	if (argv || argc)
		;
	init_vars(&infos, env);
	signal(SIGINT, c_handler);
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
