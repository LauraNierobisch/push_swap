/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:04:17 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/15 16:20:10 by lnierobi         ###   ########.fr       */
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
				ft_lstadd_back(head, new_node);
			}
			else
			{
				free(num_ptr);
			}
		}
	}
}


int	main(int argc, char *argv[])
{
	int			*num_ptr;
	t_list		*new_node;
	const char	*str;
	int			i;
	t_list		*stack;

	stack = NULL;
	if (argc < 2)
	{
		printf("Error!\n");
		return (1);
	}
	if (argc == 2)
	{
		str = argv[1];
		new_split(str, &stack);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			num_ptr = (int *)malloc(sizeof(int));
			// if (!num_ptr)
			// 	ft_exit("malloc failed");
			*num_ptr = atoi(argv[i]);
			if (*num_ptr)
			{
				new_node = ft_lstnew(num_ptr);
				ft_lstadd_back(&stack, new_node);
			}
			else
			{
				free(num_ptr);
			}
			i++;
		}
	}
	printList(stack);
	// Funktion mit der ich dann die Zahlen sortiere
	return (0);
}
