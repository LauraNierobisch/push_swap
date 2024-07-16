/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_circle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:19:32 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/16 15:08:57 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_circle(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		new->next = new;
		*lst = new;
		*lst = new;
	}
	else
	{
		last = *lst;
		while (last->next != *lst)
		{
			last = last->next;
		}
		new->next = *lst;
		last->next = new;
		*lst = new;
	}
}
