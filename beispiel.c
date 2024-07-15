#include "push_swap.h"


void rotate_a(t_list **stack_a)
{
    t_list *last;

    if (*stack_a != NULL && (*stack_a)->next != *stack_a) // Check for circular condition
    {
        ft_printf("ra\n");
        last = *stack_a;

        while (last->next != *stack_a) // Circular condition
            last = last->next;

        *stack_a = (*stack_a)->next;
        last->next = *stack_a;
    }
}

void rotate_b(t_list **stack_b)
{
    t_list *last;

    if (*stack_b != NULL && (*stack_b)->next != *stack_b) // Check for circular condition
    {
        ft_printf("rb\n");
        last = *stack_b;

        while (last->next != *stack_b) // Circular condition
            last = last->next;

        *stack_b = (*stack_b)->next;
        last->next = *stack_b;
    }
}
void swap_a(t_list **stack_a)
{
    int *temp;

    if (*stack_a != NULL && (*stack_a)->next != *stack_a)
    {
        ft_printf("sa\n");
        temp = (*stack_a)->content;
        (*stack_a)->content = (*stack_a)->next->content;
        (*stack_a)->next->content = temp;
    }
}

void swap_b(t_list **stack_b)
{
    int *temp;

    if (*stack_b != NULL && (*stack_b)->next != *stack_b)
    {
        ft_printf("sb\n");
        temp = (*stack_b)->content;
        (*stack_b)->content = (*stack_b)->next->content;
        (*stack_b)->next->content = temp;
    }
}


void rr(t_list **stack_a, t_list **stack_b)
{
    ft_printf("rr\n");
    rotate_a(stack_a);
    rotate_b(stack_b);
}
int get_max_bits(t_list *stack)
{
    int max_num = 0;
    int bits = 0;
    t_list *current = stack;

    if (stack == NULL)
        return 0;

    current = stack;
    while (1)
    {
        int num = *((int *)current->content);
        if (num > max_num)
            max_num = num;
        current = current->next;
        if (current == stack)
            break;
    }

    while ((max_num >> bits) != 0)
        bits++;

    return bits;
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    int i = 0, j, num, max_bits;
    t_list *current;
    int len;

    max_bits = get_max_bits(*stack_a);
    while (i < max_bits)
    {
        j = 0;

        // Bestimmen der Länge der Liste
        current = *stack_a;
        len = 0;
        if (current != NULL)
        {
            while (1)
            {
                len++;
                current = current->next;
                if (current == *stack_a)
                    break;
            }
        }

        while (j < len)
        {
            num = *((int *)(*stack_a)->content);
            if (((num >> i) & 1) == 1)
            {
                rotate_a(stack_a); // Element bleibt in stack_a
            }
            else
            {
                push_b(stack_a, stack_b); // Element wird nach stack_b verschoben
            }
            j++;
        }

        while (*stack_b != NULL)
        {
            push_a(stack_a, stack_b); // Alle Elemente aus stack_b zurück nach stack_a
        }

        i++;
    }
}

