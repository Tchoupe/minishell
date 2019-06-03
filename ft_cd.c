/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/06/03 23:55:19 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_cd(char **args, char **envs)
{
/*	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	path = NULL;
	tmp = NULL;
	while (args[i])
		i++;
	if (i == 1)
		chdir();
	else if (i > 2)
	 	ft_putstr("cd: too many arguments\n");
	else
	{
		tmp = getcwd(NULL, 0);
		path = ft_strcat(tmp, args[1]);
		if (!(chdir()))
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putstr(args[1]);
		}
	}*/
	exit(0);
}
