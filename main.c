/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:09:37 by ntom              #+#    #+#             */
/*   Updated: 2019/05/21 04:25:33 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static void	minijoin(char **input, int i, int j, char **executable)
{
	int		k;

	k = 0;
	while (*executable[j] && j <= i)
	{
		*executable[k] = *input[j];
		k++;
		j++;
	}
	return ;
}

static int	malloc_failed()
{
	ft_putstr("Malloc failed\n");
	return (-1);
}

static int	is_white_space(char c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

static int	minisplit(char **executable, char **input)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	while (*input[i] && is_white_space(*input[i]) == 1)
		i++;	
	j = i;
	while (*input[i] && is_white_space(*input[i]) != 1)
		i++;
	x = (sizeof(char) * (i - j) + 1);
	printf("x ---> %d\n", x);
	if (!(executable = ft_memalloc(sizeof(char) * (i - j) + 1)))
		return (malloc_failed());
	minijoin(input, i, j, executable);
	return (0);
}

int			main()
{
	char	*input;
	char	*executable;

	while (19)
	{
		input = NULL;
		executable = NULL;
		ft_putstr("$> ");
		if (get_next_line(0, &input) != 1)
				ft_putstr("GNL FAILED\n");
		//is_builtin();
		minisplit(&executable, &input);
	}
	return (0);
}
