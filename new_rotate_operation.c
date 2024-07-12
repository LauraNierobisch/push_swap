/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_rotate_operation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:04:07 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/12 14:52:32 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*last;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		ft_printf("ra\n");
		last = *stack_a;
		*stack_a = (*stack_a)->next;
		last->next = NULL;
		ft_lstadd_back(stack_a, last);
	}
}

void	rotate_b(t_list **stack_b)
{
	t_list	*last;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		ft_printf("rb\n");
		last = *stack_b;
		*stack_b = (*stack_b)->next;
		last->next = NULL;
		ft_lstadd_back(stack_b, last);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_printf("rr\n");
	rotate_a(stack_a);
	rotate_b(stack_b);
}

