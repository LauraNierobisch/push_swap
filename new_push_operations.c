/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_push_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:47:58 by lnierobi          #+#    #+#             */
/*   Updated: 2024/09/20 12:19:49 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	if (*stack_b == NULL)
	{
		return ;
	}
	ft_printf("pa\n");
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	ft_printf("pb\n");
	if (*stack_a == NULL)
	{
		return ;
	}
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}
