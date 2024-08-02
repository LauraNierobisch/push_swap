/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:03:25 by lnierobi          #+#    #+#             */
/*   Updated: 2024/08/02 15:22:23 by lnierobi         ###   ########.fr       */
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
// structure hinbauen

typedef struct s_si_content
{
	int	number;
	int	index;
	int	position;
}		t_si_content;

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
int		new_split(const char *str, t_list **head);
int		get_max_bits(t_list *stack);
char	error_function(void);
int		error_checker_complete(int argc, char *argv[]);
void	error_for_quotes(char *argv);
int		radix_sort(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *list);
void	three_numbers(t_list **list);
void	rev_rotate_a(t_list **stack_a);
int		get_list_length(t_list *stack);
int		zero_together(int argc, char *argv[]);
void	remove_leading_zeros(char *str);

#endif
