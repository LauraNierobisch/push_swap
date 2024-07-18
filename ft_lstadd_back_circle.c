/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_circle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:40:50 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/18 15:59:35 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_circle(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		new->next = new;
		return ;
	}
	last = *lst;
	if (!*lst)
	{
		*lst = new;
		new->index = 0;
		return ;
	}
	while (last->next->index != 0)
	{
		last = last->next;
		if (last == *lst) 
		{
			break ;
		}
	}
	new->index = last->index + 1;
	last->next = new;
	new->next = *lst;
}
// index muss fuer alle nodes hingemacht werden damit ich ein ende finde kann wenn nur NULL dann macht das ewig weiter