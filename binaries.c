/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 00:33:22 by ntom              #+#    #+#             */
/*   Updated: 2019/09/07 00:37:12 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char		**is_binary(t_info *infos)
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
	path = ft_strsplit((infos->envs[i] + j + 1), ':');
	return (path);
}

static int		check_binaries(char **binaries, char *input, char **path)
{
	int				i;
	struct stat		exist;
	char			buf[4097];

	i = 0;
	while (binaries[i])
	{
		buf[0] = '\0';
		ft_strcat(buf, binaries[i]);
		if (buf[ft_strlen(buf) - 1] != '/')
			ft_strcat(buf, "/");
		ft_strcat(buf, input);
		if (stat(buf, &exist) != -1)
		{
			*path = ft_strdup(buf);
			return (1);
		}
		i++;
	}
	*path = ft_strdup(buf);
	return (0);
}

static void		forking(t_info *infos, char *path)
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
		ft_putstr("minishell: command may not exist\n");
}

static int		is_exec(char **binaries, char *input, char **path)
{
	if (!binaries)
		return (1);
	if (ft_strchr(input, '/'))
	{
		*path = ft_strdup(input);
		return (1);
	}
	return (check_binaries(binaries, input, path));
}

void			binaries_and_notfound(t_info *infos, char *path)
{
	if (is_exec(infos->binaries, infos->args[0], &path))
		forking(infos, path);
	else
	{
		ft_putstr("minishell: command not found: ");
		ft_putstr(infos->args[0]);
		ft_putchar('\n');
	}
	ft_strdel(&path);
	free_stuff(infos, 0);
}
