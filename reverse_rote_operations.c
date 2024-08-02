/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rote_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:36:01 by lnierobi          #+#    #+#             */
/*   Updated: 2024/08/02 17:08:00 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **stack_a)
{
	t_list	*second_last;
	t_list	*last;

	if (*stack_a != NULL && (*stack_a)->next != *stack_a)
	{
		ft_printf("rra\n");
		second_last = NULL;
		last = *stack_a;
//fehler!!!!!!!!!
		while (last->next != *stack_a)
		{
			second_last = last;
			last = last ->next;
		}
		second_last ->next = *stack_a;
		last ->next = *stack_a;
		*stack_a = last;
	}
}

void	rev_rotate_b(t_list **stack_b)
{
	t_list	*second_last;
	t_list	*last;

	if (*stack_b != NULL && (*stack_b)->next != *stack_b)
	{
		ft_printf("rrb \n");
		second_last = NULL;
		last = *stack_b;

		while (last->next != *stack_b)
		{
			second_last = last;
			last = last ->next;
		}
		second_last ->next = *stack_b;
		*stack_b = last;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_printf("rrr \n");
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
}

