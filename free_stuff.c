/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:39:23 by ntom              #+#    #+#             */
/*   Updated: 2019/09/06 21:53:37 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_tabdel(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_strdel(&(tab[i]));
		i++;
	}
	ft_memdel((void **)&tab);
}

void 	free_stuff(t_info *infos, int exit_code)
{
	if (exit_code == 1)
		ft_tabdel(infos->envs);
	if (infos->binaries)
		ft_tabdel(infos->binaries);
	ft_tabdel(infos->args);
	if (infos->input)
		ft_strdel(&infos->input);
}
