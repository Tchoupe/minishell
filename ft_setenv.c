/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/04 00:39:32 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void			ft_setenv(t_info *infos)
{
	int		i;
	int		size;
	char	**ret;
	char	buf[4097];
	int		j;

	i = 0;
	j = 0;
	if (infos->argc > 3)
		return (ft_putendl("setenv: Too many arguments."));
	if (infos->argc == 1)
		return (ft_env(infos));
	if (!ft_isalpha(infos->args[1][0]))
		return (ft_putendl("setenv: Variable name must begin with a letter."));
	while (infos->args[1][i])
	{
		if (infos->args[1][i] != '_' && !ft_isalnum(infos->args[1][i]))
			return (ft_putendl("setenv: Variable"
			" name must contain alphanumeric characters."));
		i++;
	}
	size = 0;
	buf[0] = '\0';
	if ((i = find_env(infos, infos->args[1]) == -1))
	{
		while (infos->envs[size])
			size++;
		if (!(ret = ft_tab_dup(infos->envs, size + 1)))
			return ;
		ft_strcat(buf, infos->args[1]);
		ft_strcat(buf, "=");
		if (infos->args[2])
			ft_strcat(buf, infos->args[2]);
		ret[size] = ft_strdup(buf);
		ft_tabdel(infos->envs);
		infos->envs = ret;
	}
	else
	{
		while (infos->envs[i][j] != '=')
			i++;
		infos->envs[i] =
		ft_strsrepl(infos->envs[i], (infos->envs[i] + j), infos->args[2]);
	}
}
