/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:30:54 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/22 11:26:21 by lnierobi         ###   ########.fr       */
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


//old
void	printlist(t_list *head)
{
	t_list	*temp;
	if(head == NULL)
	{
		return ;
	}
	temp = head;
	while (temp != NULL)
	{
		t_si_content *content = (t_si_content *)temp->content;
		ft_printf("Number: %d, Position: %d, Index: %d\n", content->number, content->position, content->index);
		temp = temp->next;
		if (temp == head)
			break ;
	}
	ft_printf("\n");
}



void	free_list(t_list *head)
{
	t_list	*temp;
	t_list	*start;

	if (head == NULL)
		return ;
	start = head;
	while (1)
	{
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
		if (head == start)
			break ;
	}
}
