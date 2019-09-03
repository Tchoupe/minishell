/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/03 14:09:31 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// static int		put_error(int i)
// {
// 	if (i == 1)
// 		ft_putendl("setenv: Too many arguments.");
// 	else if (i == 2)
// 		ft_putendl("setenv: Variable name must begin with a letter.");
// 	else if (i == 3)
// 		ft_putendl("setenv: Variable name"
// 		" must contain alphanumeric characters.");
// 	return (0);
// }
//
// static int		error_set(t_info *infos)
// {
// 	int			i;
//
// 	i = 0;
// 	if (infos->argc > 3)
// 		return (put_error(1));
// 	if (!ft_isalpha(infos->args[1][0]))
// 		return (put_error(2));
// 	while (infos->args[1][i])
// 	{
// 		if (infos->args[1][i] != '_' && !ft_isalnum(infos->args[1][i]))
// 			return (put_error(3));
// 		i++;
// 	}
// 	return (1);
// }
//
// static void		set_allocation(t_info *infos)
// {
// 	int			i;
// 	char		**keys_tmp;
// 	char		**cont_tmp;
//
// 	i = 0;
// 	while (infos->keys[i])
// 		i++;
// 	if (!(keys_tmp = (char **)ft_memalloc(sizeof(char *) * (i + 2)))
// 	|| !(cont_tmp = (char **)ft_memalloc(sizeof(char *) * (i + 2))))
// 		return (ft_putendl("setenv: Failed to malloc"));
// 	i = 0;
// 	while (infos->keys[i])
// 	{
// 		keys_tmp[i] = ft_strdup(infos->keys[i]);
// 		if (infos->cont[i])
// 			cont_tmp[i] = ft_strdup(infos->cont[i]);
// 		ft_strdel(&infos->keys[i]);
// 		ft_strdel(&infos->cont[i]);
// 		i++;
// 	}
// 	keys_tmp[i] = ft_strdup(infos->args[1]);
// 	cont_tmp[i] = infos->argc != 2 ? ft_strdup(infos->args[2]) : NULL;
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
// 			ft_strcpy(infos->oldpwd, infos->cont[i]);
// 		i++;
// 	}
// }
//
// void			ft_setenv(t_info *infos)
// {
// 	int			i;
//
// 	if (error_set(infos) == 0)
// 		return ;
// 	i = 0;
// 	while (infos->keys[i])
// 	{
// 		if (ft_strcmp(infos->keys[i], infos->args[1]) == 0)
// 		{
// 			ft_strdel(&infos->cont[i]);
// 			infos->cont[i] =
// 				infos->argc != 2 ? ft_strdup(infos->args[2]) : NULL;
// 			return (stock_set(infos));
// 		}
// 		i++;
// 	}
// 	set_allocation(infos);
// 	return (stock_set(infos));
// }
void			ft_setenv(t_info *infos)
{
	if (infos)
		;
}
