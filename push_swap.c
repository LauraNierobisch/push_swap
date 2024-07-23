/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:04:17 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/23 17:58:13 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	number_to_list(int num, t_list **head)
{
	t_list	*new_node;
	int		*num_ptr;

	num_ptr = malloc(sizeof(int));
	if (num_ptr != NULL)
	{
		*num_ptr = num;
		new_node = ft_lstnew(num_ptr);
		if (new_node != NULL)
		{
			ft_lstadd_back(head, new_node);
		}
		else
		{
			free(num_ptr);
		}
	}
}

void	new_split(const char *str, t_list **head)
{
	int	num;
	int	in_number;

	// int		*num_ptr;
	// t_list	*new_node;
	num = 0;
	in_number = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			num = num * 10 + (*str - '0');
			in_number = 1;
		}
		else if (in_number)
		{
			number_to_list(num, head);
			num = 0;
			in_number = 0;
		}
		str++;
	}
	if (in_number)
		number_to_list(num, head);
}

// int	get_max_bits(t_list *stack)
// {
// 	int		max_num;
// 	int		bits;
// 	t_list	*current;
// 	int		num;

// 	max_num = 0;
// 	bits = 0;
// 	current = stack;
// 	if (stack == NULL)
// 		return (0);
// 		current = stack;
// 	while (1)
// 	{
// 		num = *((int *)current->content);
// 		if (num > max_num)
// 			max_num = num;
// 		current = current->next;
// 			if(current == stack)
// 			{
// 			break ;
// 			}
// 		//  printf("hier ist der fehler\n");
// 		if (current == stack)
// 			break ;
// 	}
// 	while ((max_num >> bits) != 0)
// 		bits++;
// 	return (bits);
// }
int	get_max_bits(t_list *stack)
{
	int		max_num;
	int		bits;
	t_list	*current;
	int		num;

	max_num = 0;
	bits = 0;
	current = stack;
	if (stack == NULL)
	{
		return (0);
	}
	do
	{
		num = *((int *)current->content);
		if (num > max_num)
		{
			max_num = num;
		}
		current = current->next;
	} while (current != stack && current != NULL);
	while ((max_num >> bits) != 0)
	{
		bits++;
	}
	return (bits);
}

// void	radix_sort(t_list **stack_a, t_list **stack_b)
// {

// 	int		i;
// 	int		j;
// 	int		num;
// 	int		max_bits;
// 	t_list	*current;
// 	int		len;

// 	i = 0;
// 	max_bits = get_max_bits(*stack_a);
// 	while (i < max_bits)
// 	{

// 		j = 0;
// 		current = *stack_a;
// 		len = 0;
// 		if (current != NULL)
// 		{
// 			while (1)
// 			{
// 				len++;
// 				current = current->next;
// 				if (current == *stack_a)
// 					break ;
// 			}
// 		}
// 		while (j < len)
// 		{
// 			num = *((int *)(*stack_a)->content);
// 			if (((num >> i) & 1) == 1)
// 			{
// 				rotate_a(stack_a);
// 			}
// 			else
// 			{
// 				push_b(stack_a, stack_b);
// 			}
// 			j++;
// 		}
// 		while (*stack_b != NULL)
// 		{
// 			push_a(stack_a, stack_b);
// 		}
// 		i++;
// 	}
// }

int	is_sorted(t_list *list)
{
	t_list			*current;
	t_si_content	*current_content;
	t_si_content	*next_content;

	current = list;
	while (current != NULL && current->next != NULL)
	{
		current_content = (t_si_content *)current->content;
		next_content = (t_si_content *)current->next->content;
		if (current_content->number > next_content->number)
		{
			return (0); // Liste ist nicht sortiert
		}
		current = current->next;
	}
	return (1); // Liste ist sortiert
}
// hier muss ich checken ob ich mehr als eine zahl erhalten hab wenn ich nur eine zahl hab mach ich nix return(0).
// und ich Ueberpruefe ob die zahlen schon sortiert sind wenn ja return (0).nix wird sortiert.

int	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		len;

	int i, j, num, max_bits;
		// if (*stack_a == NULL || (*stack_a)->next == NULL)
		// 	{
		// 		return (0);
		// 	}
	i = 0;
	max_bits = get_max_bits(*stack_a);
	if (is_sorted(*stack_a))
		return (0);

	while (i < max_bits)
	{
		j = 0;
		current = *stack_a;
		len = 0;
		if (current != NULL)
		{
			do
			{
				len++;
				current = current->next;
			} while (current != *stack_a && current != NULL);
		}
		while (j < len)
		{
			num = *((int *)(*stack_a)->content);
			if (((num >> i) & 1) == 1)
			{
				rotate_a(stack_a);
			}
			else
			{
				push_b(stack_a, stack_b);
			}
			j++;
		}
		while (*stack_b != NULL)
		{
			push_a(stack_a, stack_b);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char			*str;
	int				i;
	t_list			*stack_a;
	t_list			*stack_b;
	t_si_content	*thecontent;
	t_list			*new_node;

	thecontent = NULL;
	stack_a = NULL;
	stack_b = NULL;
	// if ((argc == 2 && !argv[1][0]))
	// 	return(0);
	// ft_putstr_fd("Error\n", 2);
	if (argc == 2)
	{
		str = argv[1];
		error_for_quotes(argc, str);
		new_split(str, &stack_a);
	}
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			thecontent = (t_si_content *)malloc(sizeof(t_si_content));
			if (thecontent == NULL)
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			error_checker_complete(argc, argv);
			thecontent->number = ft_atoi(argv[i]);
			thecontent->position = i - 1;
			thecontent->index = 0;
			new_node = ft_lstnew((void *)thecontent);
			if (new_node == NULL)
			{
				new_node->next = stack_a;
				ft_putstr_fd("Error\n", 2);
				free(thecontent);
			}
			else
			{
				ft_lstadd_back(&stack_a, new_node);
			}
			i++;
		}
	}
	// ft_printf("Stack A\n");
	radix_sort(&stack_a, &stack_b);
	// printlist(stack_a);
	// ft_printf("Stack B");
	// printlist(stack_b);
	// Funktion mit der ich dann die Zahlen sortiere
	return (0);
}

// main plan :
// wenn ich nur 1 zahla ls argument hab segfault -> muss ich fixen!
// der algorithmus ist scheisse und ich muss was besseres finden weil ich unter 700 schritte pro 100 zahlen kommen muss. 

