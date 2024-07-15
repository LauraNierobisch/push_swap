/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:30:54 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/15 16:18:45 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// new list function
void	ft_lstremove_front(t_list **lst)
{
	t_list	*temp;
	t_list	*start;

	if (lst == NULL || *lst == NULL)
	{
		return ;
	}
	start = *lst;
	if (start->next == start)
	{
		free(start->content);
		free(start);
		*lst = NULL;
		return ;
	}
	temp = start;
	while (temp->next != start)
	{
		temp = temp->next;
	}
	temp->next = start->next;
	*lst = start->next;
	free(start->content);
	free(start);
}

void	printlist(t_list *head)
{
	t_list	*temp;


	temp = head;
	while (1)
	{
		printf("%d ", *((int *)temp->content));
		temp = temp->next;
		if(temp == head)
		break;
	}
	printf("\n");
}

void	free_list(t_list *head)
{
	t_list	*temp;
	t_list	*start;

	if (head == NULL)
	return;

start = head;
	while (1)
	{
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp);

		if(head == start)
		break;
	}
}
