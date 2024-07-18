/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:30:54 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/18 19:22:50 by lnierobi         ###   ########.fr       */
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
//new

// void	printlist(t_list *head)
// {
// 	t_list			*temp;
// 	t_si_content	*thecontent;

// 	if (!head)
// 		return ;
// 	temp = head;
// 	while (temp->next != NULL)
// 	{
// 		thecontent = (t_si_content *)temp->content;
// 		ft_printf("[number: %s, position: %s, index: %s]\n", thecontent->number, thecontent->position, thecontent->index);
// 		temp = temp->next;
// 	}
// 	ft_printf("\n");
// }

//old
void	printlist(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (1)
	{
		ft_printf("%d ", *((int *)temp->content));
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
