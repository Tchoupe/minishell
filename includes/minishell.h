/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 19:40:05 by ntom              #+#    #+#             */
/*   Updated: 2019/09/07 00:30:32 by ntom             ###   ########.fr       */
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
	int			argc;
}				t_info;

/*
** BUILTINS
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
char			**ft_tab_dup(char **str, int size);
int				check_replace(t_info *infos);
char			**replace_tilde(char **str, t_info *infos);

/*
** INIT_VARS.C
*/

void			init_vars(t_info *infos, char **env);
int				init_vars_prompt(t_info *infos, int *i);

/*
** FREE_STUFF.C
*/

void			ft_tabdel(char **tab);
void			free_stuff(t_info *infos, int exit_code);

/*
** MAIN.C
*/

int				find_env(t_info *infos, char *needle);
void			c_handler(int sig_num);
void			proghandler(int sig_num);

#endif
