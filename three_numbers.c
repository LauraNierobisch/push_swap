/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:38:20 by lnierobi          #+#    #+#             */
/*   Updated: 2024/08/03 15:35:41 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_list **list)
{
	t_list			*current;
	t_si_content	*temp;
	t_si_content	*next;

	current = *list;
	temp = (t_si_content *)current->content;
	next = (t_si_content *)current->next->content;
	if (get_list_length(current) == 3)
	{
		if (temp->index == 0)
		{
			if (!is_sorted(current))
			{
				swap_a(&current);
				rotate_a(&current);
			}
		}
		else if (next->index == 0)
		{
			if (temp->index == 2)
			{
				rotate_a(&current);
			}
			else
			{
				swap_a(&current);
			}
		}
		else
		{
			if (temp->index == 1)
			{
				rev_rotate_a(&current);
			}
			else
			{
				rotate_a(&current);
				swap_a(&current);
			}
		}
	}
	*list = current;
}

void	two_numbers(t_list **list)
{
	t_list *current;

	current = *list;

	if (get_list_length(current) == 2)
	{
		if (!is_sorted(current))
		{
			rotate_a(&current);
		}
	}
	*list = current;
}