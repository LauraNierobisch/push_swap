void rotate_a(t_list **stack_a)
{
	if(*stack_a != NULL && (*stack_a)-> != NULL)
	{
		t_list *last = *stack_a;
		*stack_a = (*stack_a)->next;
		last->next = NULL;
		ft_lstadd_back(stack_a, last );
	}
}
