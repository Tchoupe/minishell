/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/04 16:28:16 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void			ft_unsetenv(t_info *infos)
{
	int		i;
	int		size;
	int		j;
	char	**tmp;
	int		x;
	int		y;

	j = 1;
	size = 0;
	while (infos->envs[size])
		size++;
	if (infos->argc == 1)
		return (ft_putendl("unsetenv: Too few arguments."));
	while (infos->args[j])
	{
		if ((i = find_env(infos, infos->args[j])) != -1)
		{
			x = 0;
			y = 0;
			if (!(tmp = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
				return ;
			while (infos->envs[x] && x < size)
			{
				if (x != i)
					if (!(tmp[y++] = ft_strdup(infos->envs[x])))
						return ;
				ft_strdel(&infos->envs[x++]);
			}
			size--;
			ft_memdel((void **)&infos->envs);
			infos->envs = tmp;
		}
		j++;
	}

}
