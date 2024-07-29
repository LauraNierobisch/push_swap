/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:30:54 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/29 19:58:14 by lnierobi         ###   ########.fr       */
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

// old
// void	printlist(t_list *head)
// {
// 	t_list			*temp;
// 	t_si_content	*content;

// 	if (head == NULL)
// 	{
// 		return ;
// 	}
// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		content = (t_si_content *)temp->content;
// 		ft_printf("Number: %d, Position: %d, Index: %d\n", content->number,
// 			content->position, content->index);
// 		temp = temp->next;
// 		if (temp == head)
// 			break ;
// 	}
// 	ft_printf("\n");
// }
void	printlist(t_list *head)
{
	t_list			*current;
	t_si_content	*content;

	current = head;
	while (current != NULL)
	{
		content = (t_si_content *)current->content;
		printf("Value: %d, Index: %d, position: %d\n", content->number, content->index, content->position);
		current = current->next;
	}
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

void	insert_node(t_list **head, t_list *new_node)
{
	t_list	*last;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = new_node;
	}
	else
	{
		last = *head;
		while (last->next != *head)
		{
			last = last->next;
		}
		last->next = new_node;
		new_node->next = *head;
	}
}
t_list	*create_node(int value)
{
	t_si_content	*content;
	t_list			*node;

	content = (t_si_content *)malloc(sizeof(t_si_content));
	if (content == NULL)
	{
		return (NULL);
	}
	content->number = value;
	content->position = 0;
	content->index = 0;
	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
	{
		free(content);
		return (NULL);
	}
	node->content = (void *)content;
	node->next = NULL;
	return (node);
}
