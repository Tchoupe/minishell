/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/06/07 23:42:25 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_env(t_info *infos)
{
	int		i;

	i = 0;
	while (infos->envs[i])
	{
		if (ft_strcmp("PWD", infos->keys[i]) == 0)
		{
			ft_putstr("PWD=");
			ft_putendl(infos->pwd);
		}
		else if (ft_strcmp("OLDPWD", infos->keys[i]) == 0)
		{
			ft_putstr("OLDPWD=");
			ft_putendl(infos->oldpwd);
		}
		else
		{
			ft_putstr(infos->keys[i]);
			ft_putchar('=');
			ft_putendl(infos->cont[i]);
		}
		i++;
	}
}
