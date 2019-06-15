/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:27:11 by ntom              #+#    #+#             */
/*   Updated: 2019/06/15 16:35:46 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	c_handler(int sig_num)
{
	signal(SIGINT, c_handler);
	ft_putchar('\n');
	ft_putstr("$> ");
	(void)sig_num;
}

void	proghandler(int sig_num)
{
	ft_putchar('\n');
	signal(SIGINT, SIG_IGN);
	(void)sig_num;
}
