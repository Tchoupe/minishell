/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:54:44 by ntom              #+#    #+#             */
/*   Updated: 2019/09/06 22:41:59 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int		errors_setenv(t_info *infos)
{
	int			i;
	const char	str[] = "setenv: Variable name must begin with a letter.\n";

	i = 0;
	if (infos->argc > 3)
		return (write(1, "setenv: Too many arguments.\n", 28));
	if (infos->argc == 1)
	{
		ft_env(infos);
		return (1);
	}
	if (!ft_isalpha(infos->args[1][0]))
		return (write(1, str, 48));
	while (infos->args[1][i])
	{
		if (infos->args[1][i] != '_' && !ft_isalnum(infos->args[1][i]))
		{
			ft_putendl("setenv: Variable"
			" name must contain alphanumeric characters.");
			return (1);
		}
		i++;
	}
	return (0);
}

static int		new_env(t_info *infos)
{
	int			size;
	char		**ret;
	char		buf[4097];

	size = 0;
	buf[0] = '\0';
	while (infos->envs[size])
		size++;
	if (!(ret = ft_tab_dup(infos->envs, size + 1)))
		return (1);
	ft_strcat(buf, infos->args[1]);
	ft_strcat(buf, "=");
	if (infos->args[2])
		ft_strcat(buf, infos->args[2]);
	ret[size] = ft_strdup(buf);
	ft_tabdel(infos->envs);
	infos->envs = ret;
	return (0);
}

void			ft_setenv(t_info *infos)
{
	int			i;
	int			j;
	char		buf[4097];

	j = 0;
	buf[0] = '\0';
	if (errors_setenv(infos) > 0)
		return ;
	if ((i = find_env(infos, infos->args[1])) == -1)
	{
		if (new_env(infos) == 1)
			return ;
	}
	else
	{
		ft_strdel(&infos->envs[i]);
		ft_strcat(buf, infos->args[1]);
		ft_strcat(buf, "=");
		if (infos->args[2])
			ft_strcat(buf, infos->args[2]);
		infos->envs[i] = ft_strdup(buf);
	}
}
