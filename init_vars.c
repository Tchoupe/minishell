/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/09/03 21:30:45 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		init_vars(t_info *infos, char **env)
{
	infos->envs = NULL;
	infos->envs = ft_tab_dup(env, -1);
}

int			init_vars_prompt(t_info *infos, int *i, char **path)
{
	int		j;
	int		x;

	x = 0;
	infos->input = NULL;
	infos->args = NULL;
	infos->status = 0;
	if ((j = find_env(infos, "PATH")) != -1)
		while (infos->envs[j][x] != '=')
			x++;
	if (path != NULL)
		ft_strdel(path);
	*path = ft_strdup(infos->envs[j] + x + 1);
	*i = 0;
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
