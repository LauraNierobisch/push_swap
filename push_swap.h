/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:03:25 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/10 12:50:50 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					ft_putlst(t_list *mylst);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					set_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					current_index(t_stack_node *stack);
void					init_stack_a(t_stack_node **a, char **argv);
void					min_on_top(t_stack_node **a);
void					move_b_to_a(t_stack_node **a, t_stack_node **b);
void					move_a_to_b(t_stack_node **a, t_stack_node **b);
void					move_b_to_a(t_stack_node **a, t_stack_node **b);
void					min_on_top(t_stack_node **a);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					set_target_a(t_stack_node *a, t_stack_node *b);
void					set_target_b(t_stack_node *a, t_stack_node *b);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
void					sort_three(t_stack_node **a);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
void					free_stack(char **numbers);

#endif
