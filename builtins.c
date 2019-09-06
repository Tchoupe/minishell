/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/06 21:28:43 by ntom             ###   ########.fr       */
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

int		is_builtin(t_info *infos)
{
	int			i;
	const char	*builtins[] = {
		"cd", "exit", "echo", "env", "setenv", "unsetenv", NULL
	};

	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(builtins[i], infos->args[0]) == 0)
		{
			if (i == 1)
			{
				free_stuff(infos, 1);
				exit(0);
			}
			g_fct_builtins[i].f(infos);
			return (1);
		}
		i++;
	}
	return (0);
}
