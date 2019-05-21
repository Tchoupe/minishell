/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:39:31 by ntom              #+#    #+#             */
/*   Updated: 2018/08/14 19:45:28 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*tmp;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(tmp = ft_memalloc(content_size)))
			return (NULL);
		tmp = ft_strcpy(tmp, content);
		new->content = tmp;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
