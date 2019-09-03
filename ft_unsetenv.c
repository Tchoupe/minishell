/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/03 14:10:25 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// static void		unset_allocation(t_info *infos)
// {
// 	int			i;
// 	char		**keys_tmp;
// 	char		**cont_tmp;
//
// 	i = 0;
// 	while (infos->keys[i])
// 		i++;
// 	if (!(keys_tmp = (char **)ft_memalloc(sizeof(char *) * (i)))
// 	|| !(cont_tmp = (char **)ft_memalloc(sizeof(char *) * (i))))
// 		return (ft_putendl("setenv: Failed to malloc"));
// 	i = 0;
// 	while (infos->keys[i])
// 	{
// 		if ()
// 		keys_tmp[i] = ft_strdup(infos->keys[i]);
// 		cont_tmp[i] = ft_strdup(infos->cont[i]);
// 		ft_strdel(&infos->keys[i]);
// 		ft_strdel(&infos->cont[i]);
// 		i++;
// 	}
// 	ft_memdel((void **)infos->keys);
// 	ft_memdel((void **)infos->cont);
// 	infos->keys = keys_tmp;
// 	infos->cont = cont_tmp;
// }
//
// static void		stock_set(t_info *infos)
// {
// 	int			i;
//
// 	i = 0;
// 	while (infos->keys[i])
// 	{
// 		if (ft_strcmp(infos->keys[i], "HOME") == 0)
// 			infos->home = infos->cont[i];
// 		else if (ft_strcmp(infos->keys[i], "PWD") == 0)
// 			getcwd(infos->pwd, 4097);
// 		else if (ft_strcmp(infos->keys[i], "OLDPWD") == 0)
// 			ft_strcat(infos->oldpwd, infos->cont[i]);
// 		i++;
// 	}
// }
//
// void	ft_unsetenv(t_info *infos)
// {
// 	if (infos)
// 		;
// 	int			i;
// 	int			j;
//
// 	if (error_unset(infos) == 0)
// 		return ;
// 	i = 0;
// 	while (infos->keys[i])
// 	{
//
// 	}
// 	unset_allocation(infos);
// 	return (stock_unset(infos));
// }

void	ft_unsetenv(t_info *infos)
{
	(void)infos;
}
