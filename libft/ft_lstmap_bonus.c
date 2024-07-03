/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:04:40 by lnierobi          #+#    #+#             */
/*   Updated: 2024/04/03 11:34:20 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_better_lstnew(void *content, void (*del)(void *))
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
	{
		del(content);
		return (NULL);
	}
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_better_lstnew(f(lst->content), del);
	if (!new_list)
		return (NULL);
	head = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_better_lstnew(f(lst->content), del);
		if (!(new_list)->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	return (head);
}
