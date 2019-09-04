/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:39:23 by ntom              #+#    #+#             */
/*   Updated: 2019/09/04 02:26:46 by ntom             ###   ########.fr       */
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
		ft_strdel(&tab[i]);
		i++;
	}
	ft_memdel((void *)tab);
}

void 	free_stuff(t_info *infos)
{
	ft_tabdel(infos->binaries);
	ft_tabdel(infos->envs);
	ft_tabdel(infos->args);
	if (infos->input)
		ft_strdel(&infos->input);
}
