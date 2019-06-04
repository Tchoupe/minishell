/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/06/05 01:19:58 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_cd(t_info *infos)
{
	struct stat		buf;
	char			*tmp;

	infos->pwd = getcwd(NULL, 0);
	tmp = NULL;
	chdir("srcs");
	printf("cwd == > %s\n", getcwd(NULL, 0));
	if (infos->argc > 2)
	{
		ft_putendl("cd: too many arguments");
		return ;
	}
	if (infos->argc > 1)
	{
		if (stat(infos->args[1], &buf) == -1)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(infos->args[1]);
			return ;
		}
		if (!S_ISDIR(buf.st_mode))
		{
			ft_putstr("cd: not a directory: ");
			ft_putendl(infos->args[1]);
			return ;
		}
		if (ft_strcmp(infos->args[1], infos->home) == 0)
			if (chdir(infos->home) != 0)
				ft_putstr("cd : home: failed for some reason\n");
		if (infos->args[1][0] == '/')
		{
			if (chdir(infos->args[1]) != 0)
				ft_putstr("cd : truc failed for some reason\n");
		}
		else if (access(infos->args[1], R_OK) == 0)
		{
			tmp = ft_strcat(infos->pwd, "/");
			if (chdir(tmp = ft_strcat(tmp, infos->args[1])) != 0)
				ft_putstr("cd : home: failed for some reason\n");
			printf("tmp => %s\n", tmp);
		}
		else
		{
			ft_putstr("cd: ");
			ft_putstr(infos->args[1]);
			ft_putstr(": Permission denied\n");
		}
	}
	if (infos->argc == 1)
		if (chdir(infos->home) != 0)
			ft_putstr("cd : home: failed for some reason\n");
	infos->pwd = getcwd(NULL, 0);
	printf("infos->pwd => %s\n", infos->pwd);
}
