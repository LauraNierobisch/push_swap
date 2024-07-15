/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rote_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 09:36:01 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/15 11:17:10 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **stack_a)
{
	t_list	*second_last;
	t_list	*last;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		ft_printf("rrb \n");
		second_last = NULL;
		last = *stack_a;

		while (last->next != NULL)
		{
			second_last = last;
			last = last ->next;
		}
		second_last ->next = NULL;
		ft_lstadd_front(stack_a, last);
	}
}

void	rev_rotate_b(t_list **stack_b)
{
	t_list	*second_last;
	t_list	*last;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		ft_printf("rrb \n");
		second_last = NULL;
		last = *stack_b;

		while (last->next != NULL)
		{
			second_last = last;
			last = last ->next;
		}
		second_last ->next = NULL;
		ft_lstadd_front(stack_b, last);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_printf("rrr \n");
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
}

