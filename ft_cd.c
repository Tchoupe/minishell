/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/06/15 15:43:28 by ntom             ###   ########.fr       */
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
		printf("PWD %s, OLDPWD %s\n", infos->pwd, infos->oldpwd);
		if (infos->args[1][0] == '-' && !infos->args[1][1])
		{
			if (chdir(infos->oldpwd) != 0)
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
	if (ft_strcmp(infos->args[1], infos->home) == 0)
		if (chdir(infos->home) != 0)
			ft_putstr("HOME: Undefined variable.\n");
	ft_cd3(infos);
}

void			ft_cd(t_info *infos)
{
	struct stat		buf;

	getcwd(infos->pwd, 4097);
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
		if (chdir(infos->home) != 0)
			ft_putstr("HOME: Undefined variable.\n");
	infos->oldpwd[0] = '\0';
	ft_strcat(infos->oldpwd, infos->pwd);
	getcwd(infos->pwd, 4097);
}
