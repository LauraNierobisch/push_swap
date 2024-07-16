/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_swap_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:49:47 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/16 15:09:45 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int	*temp;

	if (*stack_a != NULL && (*stack_a)->next != *stack_a)
	{
		ft_printf("sa\n");
		temp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = temp;
	}
}

void	swap_b(t_list **stack_b)
{
	int	*temp;

	if (*stack_b != NULL && (*stack_b)->next != *stack_b)
	{
		ft_printf("sb\n");
		temp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp;
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_printf("ss\n");
	swap_a(stack_a);
	swap_b(stack_b);
}
