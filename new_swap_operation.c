void swap_a(t_list **stack_a)
{
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		ft_printf("sa\n");
		int *temp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = temp;
	}
}

void swap_b(t_list **stack_b)
{
	if(*stack_b != NULL && (*stack_b)->next != NULL)
	{
		ft_printf("sb\n");
		int *temp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp;
	}
}

void ss(t_list **stack_a, t_list **stack_b)
{
	ft_printf("ss\n");
	sa(stack_a);
	sb(stack_b);
}
