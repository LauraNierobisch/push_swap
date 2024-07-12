/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_push_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:47:58 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/12 15:19:30 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (*stack_b != NULL)
	{
		ft_printf("pa\n");
		top_b = *stack_b;
		*stack_b = (*stack_b)->next;
		top_b->next = NULL;
		ft_lstadd_front(stack_a, top_b);
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a != NULL)
	{
		ft_printf("pb\n");
		t_list *top_a = *stack_a;
		*stack_a = (*stack_a)->next;
		top_a->next = NULL;
		ft_lstadd_front(stack_b, top_a);
	}
}