/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/09/07 00:35:16 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int					find_env(t_info *infos, char *needle)
{
	int				i;

	i = 0;
	while (infos->envs[i])
	{
		if (ft_strcmp(infos->envs[i], needle) == '=')
			return (i);
		i++;
	}
	return (-1);
}

int					main(int argc, char **argv, char **env)
{
	int				i;
	t_info			infos;
	char			*path;

	if ((path = NULL) || argv || argc)
		;
	init_vars(&infos, env);
	signal(SIGINT, c_handler);
	while (19)
	{
		if (init_vars_prompt(&infos, &i) != 0)
			continue ;
		check_replace(&infos);
		infos.args = minisplit(infos.input, &infos.argc);
		infos.args = replace_tilde(infos.args, &infos);
		infos.binaries = is_binary(&infos);
		if (!infos.args[0] || is_builtin(&infos))
		{
			free_stuff(&infos, 0);
			continue ;
		}
		binaries_and_notfound(&infos, path);
	}
	return (0);
}
