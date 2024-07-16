/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_push_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:47:58 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/16 11:56:06 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;
	t_list	*last_b;

	if (*stack_b != NULL)
	{
		ft_printf("pa\n");
		top_b = *stack_b;
		if (top_b->next == top_b)
			*stack_b = NULL;
		else
		{
			last_b = top_b;
			while (last_b->next != top_b)
			{
				last_b = last_b->next;
			}
			*stack_b = top_b->next;
			last_b->next = *stack_b;
		}
		ft_lstadd_front(stack_a, top_b);
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	t_list	*last_a;

	if (*stack_a != NULL)
	{
		ft_printf("pa\n");
		top_a = *stack_a;
		if (top_a->next == top_a)
			*stack_a = NULL;
		else
		{
			last_a = top_a;
			while (last_a->next != top_a)
			{
				last_a = last_a->next;
			}
			*stack_a = top_a->next;
			last_a->next = *stack_a;
		}
		ft_lstadd_front(stack_b, top_a);
	}
}
