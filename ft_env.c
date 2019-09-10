/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/08/20 23:38:34 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	ft_env(t_info *infos)
{
	int		i;

	i = 0;
	while (infos->envs[i])
	{
		ft_putendl(infos->envs[i]);
		i++;
	}
}