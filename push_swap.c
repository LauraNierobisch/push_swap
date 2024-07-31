/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:04:17 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/31 12:32:25 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	new_split(const char *str, t_list **head)
{
	int	num;
	int	in_number;
	int	position;

	num = 0;
	in_number = 0;
	position = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			num = num * 10 + (*str - '0');
			in_number = 1;
		}
		else if (in_number)
		{
			number_to_list(num, position, head);
			num = 0;
			in_number = 0;
		}
		if (!ft_isdigit(*str))
		{
			position++;
		}
		str++;
	}
	if (in_number)
	{
		number_to_list(num, position, head);
	}
	return (0);
}

// void	number_to_list(int num, t_list **head)
// {
// 	t_list	*new_node;
// 	int		*num_ptr;
// 	int		i;

// 	// t_si_content	*thecontent;
// 	i = 0;
// 	// thecontent = NULL;
// 	num_ptr = malloc(sizeof(int));
// 	if (num_ptr != NULL)
// 	{
// 		*num_ptr = num;
// 		new_node = ft_lstnew(num_ptr);
// 		if (new_node != NULL)
// 		{
// 			ft_lstadd_back(head, new_node);
// 			i++;
// 		}
// 		else
// 		{
// 			free(num_ptr);
// 		}
// 		// thecontent->position = i - 1;
// 	}
// }

// int	new_split(const char *str, t_list **head)
// {
// 	int				num;
// 	int				in_number;
// 	t_si_content	*thecontent;
// 	const char *start_str = str;

// 	thecontent = (t_si_content *)malloc(sizeof(t_si_content));
// 	if (thecontent == NULL)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return (1);
// 		free(thecontent);
// 	}
// 	num = 0;
// 	in_number = 0;
// 	while (*str != '\0')
// 	{
// 		if (ft_isdigit(*str))
// 		{
// 			num = num * 10 + (*str - '0');
// 			in_number = 1;
// 		}
// 		else if (in_number)
// 		{
// 			number_to_list(num, head);
// 			num = 0;
// 			in_number = 0;
// 		}
// 		str++;
// 	}
// 	if (in_number)
// 		number_to_list(num, head);
// 	thecontent->position = (int)(str - start_str -1);
// 	return(0);
// }

// oldnew
void	bubble_sort_index(t_list *head)
{
	int				swapped;
	t_list			*ptr1;
	t_list			*lptr;
	t_si_content	*temp_content;
	t_si_content	*content1;
	t_si_content	*content2;

	lptr = NULL;
	if (head == NULL)
	{
		return ;
	}
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
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
				swapped = 1;
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
			return (0); // Liste ist nicht sortiert
		}
		current = current->next;
	}
	return (1); // Liste ist sortiert
}
// int get_list_length(t_list *stack)
// {
// 	int len;
// 	t_list *current;

// 	len = 0;
// 	current = stack;
// 	while (current != NULL)
// 	{
// 		current = current->next;
// 		len++;
// 	}

// 	return (len);
// }

// int get_max_bits(t_list *stack)
// {
// 	int max_num;
// 	int bits;
// 	t_list *current;
// 	t_si_content *content;

// 	max_num = 0;
// 	bits = 0;
// 	current = stack;
// 	if (stack == NULL)
// 		return (0);
// 	while (current != NULL)
// 	{
// 		content = (t_si_content *)current->content;
// 		if (content->index > max_num)
// 			max_num = content->index;
// 		current = current->next;
// 	}
// 	while ((max_num >> bits) != 0)
// 		bits++;
// 	return (bits);
// }

// int radix_sort(t_list **stack_a, t_list **stack_b)
// {
// 	t_si_content *content;
// 	int len;
// 	int i, j, num, max_bits;

// 	i = 0;
// 	if (is_sorted(*stack_a))
// 		return (0);
// 	max_bits = get_max_bits(*stack_a);
// 	while (i < max_bits)
// 	{
// 		j = 0;
// 		len = get_list_length(*stack_a);
// 		while (j < len)
// 		{
// 			content = (t_si_content *)(*stack_a)->content;
// 			num = content->index;
// 			if (((num >> i) & 1) == 1)
// 			{
// 				rotate_a(stack_a); // Behalte das Element in stack_a
// 			}
// 			else
// 			{
// 				push_b(stack_a, stack_b); // Verschiebe das Element nach stack_b
// 			}
// 			j++;
// 		}
// 		while (*stack_b != NULL)
// 		{
// 			push_a(stack_a, stack_b);
// Verschiebe die Elemente zurück nach stack_a
// 		}
// 		i++;
// 	}
// 	return (0);
// }

//?kind of worked?
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
int	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_si_content	*content;
	int				len;

	// t_list			*current;
	int i, j, num, max_bits;
	i = 0;
	if (is_sorted(*stack_a))
		return (0);
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
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
		while (*stack_b != NULL)
		{
			push_a(stack_a, stack_b);
		}
		i++;
	}
	return (0);
}

// old
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
void	bubble_sort_back(t_list *head)
{
	int				swapped;
	t_list			*ptr1;
	t_list			*lptr;
	t_si_content	*content1;
	t_si_content	*content2;
	t_si_content	*temp_content;

	lptr = NULL;
	if (head == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
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
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
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
	if (argc == 2)
	{
		str = argv[1];
		error_for_quotes(*argv);
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
				free(thecontent);
			}
			error_checker_complete(argc, argv);
			thecontent->number = ft_atoi(argv[i]);
			thecontent->position = i - 1;
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
	}
	// ft_printf("Stack A\n");
	bubble_sort_index(stack_a);
	set_index(stack_a);
	//  ft_printf("Stack A index sorting:\n");
	//  printlist(stack_a);
	bubble_sort_back(stack_a);
	//  ft_printf("Stack back to possition:A\n");
	//  printlist(stack_a);
	radix_sort(&stack_a, &stack_b);
	//  ft_printf("Stack A after redix sort\n");
	//  printlist(stack_a);
	// Funktion mit der ich dann die Zahlen sortiere
	// free_list(stack_a);
	return (0);
	free_list(stack_a);
	free_list(stack_b);
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
// main plan :
// wenn es nur 2 zahlen sind muss ich erst ueberprüfen ob die sortiert sind und wenn nicht dann nur swapen.
// der algorithmus ist scheisse und ich muss was besseres finden weil ich unter 700 schritte pro 100 zahlen kommen muss.

// jeder zahl ein index geben mit bubble sort um dann die zahlen zu sortieren und dann mit redix sort sortieren aber nur die indexe nicht die zahlen an sich
// und dann mit redix sort sortieren die liste mit den indexen die dann aber noch durcheinander sind
// und dann hab ih die kleineren zahlen und die - zahlen abgedeckt
// also ich sortiere mit bubble sort dann sortier ich wieder zurueck nach possition und dann sortiere ich mit redix sort aber nach dem index mit den operatinen
// ich muss noch den radix sort fuer ohne " " fertig machen und fuer die mit "" alles noch anpassen
//
//to do
// Nullen vor der error kontrolle wegschneiden
// -5 - behandeln
// 0 und -0 als doppelte zahlen behandeln 
// 3er extra sortierung machen
//aus dreier sortierung 5er sortierung machen