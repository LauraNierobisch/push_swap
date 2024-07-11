/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:27:03 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/10 14:51:06 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putlst(t_list *mylst)
{
	t_list	*current;

	current = mylst;
	while (current->next != NULL)
	{
		ft_printf("LISTITEM:\n");
		current = current->next;
		ft_printf("remove me later");
	}
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if ((!argv[1][0] && argc == 2) || (argc == 1))
	{
		ft_printf("Error!");
		return (1);
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(&a, argv + 1);
		if (!stack_sorted(a))
		{
			if (stack_len(a) == 2)
				sa(&a, false);
			else if (stack_len(a) == 3)
				sort_three(&a);
			else
				sort_stacks(&a, &b);
		}
		free_stack(&a);
		return (0);
	}
}
		// wenns normale zahlen sind ohne "" sofort in stack a
		// wenns in "" dann ft_split den string in Zahlen umwandeln und dann in stuck a rein
		// dann von stack a in stuck b indexieren
		// und dann die move funktionen benutzen um es nach der indexierung zu sortieren und alle zahlen in stuck a zurueck zu geben und dann fertig
	/* 1. zuerst argv argc bauen das es unendlich zahlen aufnhemen kann auch wenn man das als 1 sting hat also "zahlenzeugs zahl zahl" das man den langem string umwandelt in die einzelnen zahlen mit ft_split.
	2. dann die 2 stucks bauen a und b also alles was argc aufnimmt muss gleich in stack a rein gehen linked list oder array ist ein stack
	3. dann muss ich die ganzen Funktionen fuer die moves bauen sa sb ss pa pb ra rb rr rra rrb rrr die muessen jedes mal auf dem Bildschirm geprintet werden wenn man das benuzt.
	4. dann muss ich einen algorithmus bauen der die zahlen in stack b sortiert und am ende dann in stack a muessen alle zahlen sortiert abgelegt sein
es muss soriert sein das die oberste zahl die kleinste zahl ist und die groeste am ende
und ich muss zuerst jeder zahl einen index geben damit die schon vorsortiert sind


also zahl erhalten
zahl indexieren
schauen welches sortierung am guenstigsten ist und sortieren
schritte ausgeben
ende
*/


void	free_stack(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

