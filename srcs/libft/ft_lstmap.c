/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntom <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:47:32 by ntom              #+#    #+#             */
/*   Updated: 2018/07/10 13:49:48 by ntom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (ft_lstnew(NULL, 0));
	if (!(new = malloc(sizeof(t_list))) || !lst || !f)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	tmp = new;
	while (lst)
	{
		new->next = f(lst);
		new = new->next;
		lst = lst->next;
	}
	new = tmp;
	return (new);
}
