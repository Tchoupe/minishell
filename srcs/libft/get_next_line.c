/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <ntom@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:15:36 by ntom              #+#    #+#             */
/*   Updated: 2019/09/04 02:13:06 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getn(char *tab[OPEN_MAX], const int fd, char **line)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	if (!(tab[fd]) || tab[fd][0] == '\0')
	{
		ft_strdel(&tab[fd]);
		return (0);
	}
	tmp = tab[fd];
	while (tab[fd][i] && tab[fd][i] != '\n')
		i++;
	*line = ft_strsub(tmp, 0, i);
	if (tab[fd][i] == '\n')
		i++;
	tab[fd] = ft_strsub(tmp, i, ft_strlen(tmp));
	ft_strdel(&tmp);
	ft_strdel(&tab[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*tab[OPEN_MAX];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || fd >= OPEN_MAX || BUFF_SIZE < 1 || !(line))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (!(tab[fd]))
			tab[fd] = ft_strdup(buf);
		else
		{
			tmp = tab[fd];
			if (!(tab[fd] = ft_strjoin(tab[fd], buf)))
				return (-1);
			ft_strdel(&tmp);
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (getn(tab, fd, line));
}
