/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/06/08 18:16:33 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		init_vars(t_info *infos, char **env)
{
	infos->envs = NULL;
	infos->keys = NULL;
	infos->cont = NULL;
	infos->envs = ft_tab_dup(env);
	infos->pwd[0] = '\0';
	infos->oldpwd[0] = '\0';
	stock_env(infos);
}


void		init_vars_prompt(t_info *infos, int *i, char *path)
{
	infos->input = NULL;
	infos->args = NULL;
	infos->status = 0;
	*i = 0;
	path[0] = '\0';
	ft_putstr("$> ");
	if (get_next_line(0, &infos->input) != 1)
	{
		ft_putstr("GNL FAILED\n");
		return ;
	}
}
