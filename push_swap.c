/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:04:17 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/17 11:46:16 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_split(const char *str, t_list **head)
{
	int		num;
	int		in_number;
	int		*num_ptr;
	t_list	*new_node;

	num = 0;
	in_number = 0;
	while (*str != '\0')
	{
		if (isdigit(*str))
		{
			num = num * 10 + (*str - '0');
			in_number = 1;
		}
		else if (in_number)
		{
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
			num = 0;
			in_number = 0;
		}
		str++;
	}
	if (in_number)
	{
		num_ptr = malloc(sizeof(int));
		if (num_ptr != NULL)
		{
			*num_ptr = num;
			new_node = ft_lstnew(num_ptr);
			if (new_node != NULL)
			{
				ft_lstadd_back_circle(head, new_node);
			}
			else
			{
				free(num_ptr);
			}
		}
	}
}

// void number_to_list(int num_ptr, )
// {
// 	//von Zeile 55 bis 65 kopiert damit ich das fuer in "" und nicht in "" benutzen kann und ich aknn das 2 mal in new split einfuegen
// num_ptr = malloc(sizeof(int));
// 		if (num_ptr != NULL)
// 		{
// 			*num_ptr = num;
// 			new_node = ft_lstnew(num_ptr);
// 			if (new_node != NULL)
// 			{
// 				ft_lstadd_back_circle(head, new_node);
// 			}
// 			else
// 			{
// 				free(num_ptr);
// 			}
// 		}
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
		return (0);
	current = stack;
	while (1)
	{
		num = *((int *)current->content);
		if (num > max_num)
			max_num = num;
		current = current->next;
		if (current == stack)
			break ;
	}
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		num;
	int		max_bits;
	t_list	*current;
	int		len;

	i = 0;
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		current = *stack_a;
		len = 0;
		if (current != NULL)
		{
			while (1)
			{
				len++;
				current = current->next;
				if (current == *stack_a)
					break ;
			}
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
}
int	main(int argc, char *argv[])
{
	int			*num_ptr;
	t_list		*new_node;
	const char	*str;
	int			i;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (argc == 2)
	{
		str = argv[1];
		new_split(str, &stack_a);
	}
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			num_ptr = (int *)malloc(sizeof(int));
			if (num_ptr == NULL)
			{
				error_function();
			}
			*num_ptr = atoi(argv[i]);
			if (argv[i][0] != '\0' && ((*num_ptr != 0) || argv[i][1]== '\0'))
			{
				new_node = ft_lstnew(num_ptr);
				ft_lstadd_back_circle(&stack_a, new_node);
			}
			else
			{
				free(num_ptr);
			}
			i++;
		}
	}
	ft_printf("Stack A ");
	printlist(stack_a);
	// ft_printf("Stack B");
	// printlist(stack_b);
	// Funktion mit der ich dann die Zahlen sortiere
	return (0);
}



//main plan :
//arg v arg c blah blah
//dann von da aus weiter in den error check
// eror ckeck : obs in der range is mit long ob der das aufnehem kann und obs int ist dupicate
//dann muss ich noch die null am anfang hendeln zB 02 oder so
//dann :
//if > 2 dann in die eine funktion
//if = 2 dann in die andere Funktion und

//und von da dann in die sortierung

int range_int (char **argv)
{
	long num;
	int sign;

	num = 0;
	sign = 1;

	if (*argv == '\0')
	{
		error_function();
	}
	if (*argv == '-')
	{
		sign = -1;
		argv ++;
	}
	if (*argv == '+')

}

int dupli_int(char **argv)
{
	int i;

}

int numbers_only(char **argv)
{

}


