/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/09/03 14:11:55 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		init_vars(t_info *infos, char **env)
{
	infos->envs = NULL;
	infos->envs = ft_tab_dup(env);
}

int			init_vars_prompt(t_info *infos, int *i, char *path)
{
	infos->input = NULL;
	infos->args = NULL;
	infos->status = 0;
	*i = 0;
	path[0] = '\0';
	ft_putstr("$> ");
	if (get_next_line(0, &infos->input) != 1)
	{
		if (infos->input == NULL)
		{
			ft_putendl("exit");
			exit(0);
		}
		ft_putstr("GNL FAILED\n");
		return (1);
	}
	return (0);
}
