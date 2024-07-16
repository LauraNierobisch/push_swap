/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_rotate_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:04:07 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/16 12:43:51 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*last;

	if (*stack_a != NULL && (*stack_a)->next != *stack_a)
	{
		ft_printf("ra\n");
		last = *stack_a;
		while (last->next != *stack_a)
			last = last->next;
		*stack_a = (*stack_a)->next;
		last->next = *stack_a;
	}
}

void	rotate_b(t_list **stack_b)
{
	t_list	*last;

	if (*stack_b != NULL && (*stack_b)->next != *stack_b)
	{
		ft_printf("rb\n");
		last = *stack_b;
		while (last->next != *stack_b)
			last = last->next;
		*stack_b = (*stack_b)->next;
		last->next = *stack_b;
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_printf("rr\n");
	rotate_a(stack_a);
	rotate_b(stack_b);
}
