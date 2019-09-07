/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/07 18:34:00 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void		cd_permissions(t_info *infos)
{
	if (infos->args[1][0] == '/')
		chdir(infos->args[1]);
	else if (access(infos->args[1], R_OK) == 0)
	{
		if (chdir(infos->args[1]) != 0)
		{
			ft_putstr_fd("cd: permission denied: ", 2);
			ft_putendl_fd(infos->args[1], 2);
			return ;
		}
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(infos->args[1], 2);
		ft_putendl_fd(": Permission denied", 2);
	}
}

static void		cd_errors(t_info *infos, struct stat *buf)
{
	if (stat(infos->args[1], buf) == -1)
	{
		if (infos->args[1][0] == '-' && !infos->args[1][1])
		{
			if (find_env(infos, "OLDPWD") == -1)
				ft_putendl_fd("OLDPWD: Undefined variable.", 2);
			else
				chdir(
					ft_strchr(infos->envs[find_env(infos, "OLDPWD")], '=') + 1);
			return ;
		}
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(infos->args[1], 2);
		return ;
	}
	else if (!S_ISDIR(buf->st_mode))
	{
		ft_putstr_fd("cd: not a directory: ", 2);
		ft_putendl_fd(infos->args[1], 2);
		return ;
	}
	cd_permissions(infos);
}

static void		set_pwds(t_info *infos, char *pwd)
{
	int				i;
	char			tmp[4097];
	char			*protec;

	i = find_env(infos, "OLDPWD");
	tmp[0] = '\0';
	protec = NULL;
	free(infos->envs[i]);
	ft_strcat(tmp, "OLDPWD=");
	if ((protec = ft_strdup(ft_strcat(tmp, pwd))))
		infos->envs[i] = protec;
	getcwd(pwd, 4097);
	tmp[0] = '\0';
	ft_strcat(tmp, "PWD=");
	i = find_env(infos, "PWD");
	free(infos->envs[i]);
	if ((protec = ft_strdup(ft_strcat(tmp, pwd))))
		infos->envs[i] = protec;
}

void			ft_cd(t_info *infos)
{
	struct stat		buf;
	char			pwd[4097];
	int				i;

	getcwd(pwd, 4097);
	if (infos->argc > 2)
		return (ft_putendl_fd("cd: too many arguments", 2));
	else if (infos->argc > 1)
		cd_errors(infos, &buf);
	else if (infos->argc == 1)
		if (((i = find_env(infos, "HOME")) == -1)
		|| chdir(ft_strchr(infos->envs[i], '=') + 1) != 0)
			ft_putendl_fd("HOME: Undefined variable.", 2);
	set_pwds(infos, pwd);
}
