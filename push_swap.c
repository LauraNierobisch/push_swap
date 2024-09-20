/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:04:17 by lnierobi          #+#    #+#             */
/*   Updated: 2024/09/20 17:17:23 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_array_length(char **array)
{
	int	length;

	length = 0;
	while (array[length] != NULL)
		length++;
	return (length);
}

void	ft_array_free(char **array)
{
	int	length;

	if (array == NULL)
		return ;
	length = ft_array_length(array);
	length--;
	while (length >= 0)
	{
		if (array[length])
		{
			free(array[length]);
			array[length] = NULL;
		}
		length--;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
}

void	number_to_list(int num, int pos, t_list **head)
{
	t_list			*new_node;
	t_si_content	*content;

	content = (t_si_content *)malloc(sizeof(t_si_content));
	if (content != NULL)
	{
		content->number = num;
		content->position = pos;
		new_node = ft_lstnew(content);
		if (new_node != NULL)
		{
			ft_lstadd_back(head, new_node);
		}
		else
		{
			free(content);
		}
	}
}

void	bubble_sort_index(t_list *head, int *swapped, t_list *lptr)
{
	t_list			*ptr1;
	t_si_content	*temp_content;
	t_si_content	*content1;
	t_si_content	*content2;

	while (*swapped)
	{
		*swapped = 0;
		ptr1 = head;
		while (ptr1->next != lptr)
		{
			content1 = (t_si_content *)ptr1->content;
			content2 = (t_si_content *)ptr1->next->content;
			if (content1->number > content2->number)
			{
				temp_content = ptr1->content;
				ptr1->content = ptr1->next->content;
				ptr1->next->content = temp_content;
				*swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

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
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	get_list_length(t_list *stack)
{
	int		len;
	t_list	*current;

	len = 0;
	current = stack;
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}

int	get_max_bits(t_list *stack)
{
	int				max_num;
	int				bits;
	t_list			*current;
	t_si_content	*content;

	max_num = 0;
	bits = 0;
	current = stack;
	if (stack == NULL)
		return (0);
	while (current->next)
	{
		content = (t_si_content *)current->content;
		if (content->index > max_num)
			max_num = content->index;
		current = current->next;
	}
	content = (t_si_content *)current->content;
	if (content->index > max_num)
		max_num = content->index;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

static void	while_max(t_list **stack_a, t_list **stack_b, int i)
{
	t_si_content	*content;
	int				len;
	int				j;
	int				num;

	j = 0;
	len = get_list_length(*stack_a);
	while (j < len)
	{
		content = (t_si_content *)(*stack_a)->content;
		num = content->index;
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
}

int	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	max_bits;

	i = 0;
	if (is_sorted(*stack_a))
		return (0);
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		while_max(stack_a, stack_b, i);
		while (*stack_b != NULL)
		{
			push_a(stack_a, stack_b);
		}
		i++;
	}
	return (0);
}

void	set_index(t_list *head)
{
	int				index;
	t_si_content	*content;

	index = 0;
	while (head != NULL)
	{
		content = (t_si_content *)head->content;
		content->index = index++;
		head = head->next;
	}
}

void	bubble_sort_back(t_list *head, t_list *lptr, int *swapped)
{
	t_list			*ptr1;
	t_si_content	*content1;
	t_si_content	*content2;
	t_si_content	*temp_content;

	while (*swapped)
	{
		*swapped = 0;
		ptr1 = head;
		while (ptr1->next != lptr)
		{
			content1 = (t_si_content *)ptr1->content;
			content2 = (t_si_content *)ptr1->next->content;
			if (content1->position > content2->position)
			{
				temp_content = ptr1->content;
				ptr1->content = ptr1->next->content;
				ptr1->next->content = temp_content;
				*swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

void	mycontclear(void *content)
{
	if (content)
		free(content);
}

int	main(int argc, char *argv[])
{
	int				i;
	t_list			*stack_a;
	t_list			*stack_b;
	t_si_content	*thecontent;
	t_list			*new_node;
	int				err_flag;

	i = 1;
	err_flag = 0;
	thecontent = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		count_for_split(argc, argv);
	while (i < argc && !err_flag)
	{
		thecontent = (t_si_content *)malloc(sizeof(t_si_content));
		if (thecontent == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		err_flag = error_checker_complete(argc, argv);
		if (err_flag)
		{
			if (argv && argc == 1)
				ft_array_free(argv);
			free(thecontent);
			break ;
		}
		thecontent->number = ft_atoi(argv[i]);
		thecontent->position = i;
		thecontent->index = 0;
		new_node = ft_lstnew((void *)thecontent);
		if (new_node == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			free(thecontent);
		}
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	sort_stuff(stack_a, stack_b);
	ft_lstclear(&stack_a, mycontclear);
	ft_lstclear(&stack_b, mycontclear);
	return (0);
}

void	sort_stuff(t_list *stack_a, t_list *stack_b)
{
	int		swapped;
	int		swapped2;
	t_list	*lptr;

	lptr = NULL;
	swapped = 1;
	swapped2 = 1;
	if (stack_a)
		bubble_sort_index(stack_a, &swapped, lptr);
	set_index(stack_a);
	if (stack_a)
		bubble_sort_back(stack_a, lptr, &swapped2);
	if (get_list_length(stack_a) == 2)
		two_numbers(&stack_a);
	if (get_list_length(stack_a) == 3)
		three_numbers(&stack_a);
	if (get_list_length(stack_a) > 3)
		radix_sort(&stack_a, &stack_b);
}

void	remove_leading_zeros(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL || *str == '\0')
	{
		return ;
	}
	while (str[i] == '0' && str[i + 1] != '\0')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		str[j++] = str[i++];
	}
	str[j] = '\0';
}

void	count_for_split(int argc, char **argv)
{
	int	split_count;
	int	i;

	split_count = 0;
	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		split_count = 0;
		while (argv[split_count] != NULL)
			split_count++;
		argc = split_count;
		i = 0;
	}
}
