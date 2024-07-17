/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:03:25 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/17 10:05:15 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_lstremove_front(t_list **lst);
void	printlist(t_list *head);
void	free_list(t_list *head);
void	ft_lstadd_back_circle(t_list **lst, t_list *new);
void	ft_lstadd_front_circle(t_list **lst, t_list *new);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	new_split(const char *str, t_list **head);
int		get_max_bits(t_list *stack);
void	radix_sort(t_list **stack_a, t_list **stack_b);
char	error_function(void);
#endif
