/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/03 14:07:12 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void		ft_cd3(t_info *infos)
{
	if (infos->args[1][0] == '/')
	{
		if (chdir(infos->args[1]) != 0)
			ft_putstr("ROOT: Undefined variable\n");
	}
	else if (access(infos->args[1], R_OK) == 0)
	{
		if (chdir(infos->args[1]) != 0)
		{
			ft_putstr("cd: permission denied: ");
			ft_putendl(infos->args[1]);
			return ;
		}
	}
	else
	{
		ft_putstr("cd: ");
		ft_putstr(infos->args[1]);
		ft_putstr(": Permission denied\n");
	}
}

static void		ft_cd2(t_info *infos, struct stat *buf)
{
	if (stat(infos->args[1], buf) == -1)
	{
		if (infos->args[1][0] == '-' && !infos->args[1][1])
		{
			if (find_env(infos, "OLDPWD") == -1)
				ft_putstr("OLDPWD: Undefined variable.\n");
			return ;
		}
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(infos->args[1]);
		return ;
	}
	if (!S_ISDIR(buf->st_mode))
	{
		ft_putstr("cd: not a directory: ");
		ft_putendl(infos->args[1]);
		return ;
	}
	if (find_env(infos, "HOME") == -1)
		ft_putstr("HOME: Undefined variable.\n");
	if (infos->args[1][0] == '~' && infos->args[1][1] == '\0')
		chdir(infos->envs[find_env(infos, "HOME")]);
	ft_cd3(infos);
}

void			ft_cd(t_info *infos)
{
	struct stat		buf;
	char			pwd[4097];

	pwd[0] = '\0';
	getcwd(pwd, 4097);
	if (infos->argc > 2)
	{
		ft_putendl("cd: too many arguments");
		return ;
	}
	else if (infos->argc > 1)
	{
		ft_cd2(infos, &buf);
	}
	else if (infos->argc == 1)
		if (chdir(infos->envs[find_env(infos, "HOME")]) != 0)
			ft_putstr("HOME: Undefined variable.\n");
	free(infos->envs[find_env(infos, "OLDPWD")]);
	ft_strcat(infos->envs[find_env(infos, "OLDPWD")], infos->envs[find_env(infos, "PWD")]);
	getcwd(pwd, 4097);
	free(infos->envs[find_env(infos, "PWD")]);
	infos->envs[find_env(infos, "OLDPWD")] = ft_strdup(pwd);
}
