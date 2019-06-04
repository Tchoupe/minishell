/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:40:05 by ntom              #+#    #+#             */
/*   Updated: 2019/06/04 13:35:50 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** LIBRARIES
*/

# include "../srcs/libft/libft.h"
# include <sys/stat.h>

/*
** MACROS
*/

/*
** STRUCTURES
*/

typedef struct	s_fct
{
	void		(*f)();
}				t_fct;

typedef struct	s_launch
{
	char		*select;
	int			(*f)();
}				t_lauch;

typedef struct	s_info
{
	char		*input;
	char		**args;
	char		**envs;
	char		**binaries;
	int			status;
	char		**keys;
	char		**cont;
	char		*home;
	char		*pwd;
	int			argc;
}				t_info;

/*
** FUNCTIONS
*/

void			ft_cd();
void			ft_exit();
void			ft_echo();
void			ft_env();
void			ft_setenv();
void			ft_unsetenv();

/*
** BUILTINS.C
*/

int				is_builtin(t_info *infos);

/*
** TOOLS.C
*/

int				miniwhitespace(char c);
size_t			ft_c(char const *s);
char			**minisplit(char const *s, int *argc);
char			**ft_tab_dup(char **str);
int				check_replace(char **keys, char **cont, char **input);

#endif
