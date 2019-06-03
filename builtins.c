/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/06/04 00:05:52 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

const t_fct g_fct_builtins[] = {
	{ft_cd},
	{NULL},
	{ft_echo},
	{ft_env},
	{ft_setenv},
	{ft_unsetenv}
};

int		exe_builtin(int i, char **args, char **envs)
{
	int		pid;
	int		status;

	pid = 0;
	status = 0;
	if (i != 1)
	{
		if ((pid = fork()) < 0)
		{
			ft_putstr("Fork error\n");
			exit(0);
		}
		else if (pid == 0)
		{
			g_fct_builtins[i].f(args, envs);
			exit(0);
		}
		else
			wait(&status);
	}
	else
		exit(0);
	return (1);
}

int		is_builtin(char *input, char **args, char **envs)
{
	int			i;
	const char	*builtins[] = {
		"cd",
		"exit",
		"echo",
		"env",
		"setenv",
		"unsetenv",
		NULL
	};

	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(builtins[i], args[0]) == 0)
			return (exe_builtin(i, args, envs));
		i++;
	}
	return (0);
}
