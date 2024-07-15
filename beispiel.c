#include "push_swap.h"

void free_list(t_list *head)
{
    t_list  *temp;
    t_list  *start = head;

    if (head == NULL)
        return;

    do {
        temp = head;
        head = head->next;
        free(temp->content);
        free(temp);
    } while (head != start);
}

// void ft_lstremove_front(t_list **lst)
// {
//     t_list  *temp;
//     t_list  *start;

//     if (lst == NULL || *lst == NULL)
//         return;

//     start = *lst;
//     if (start->next == start) { // Nur ein Element in der Liste
//         free(start->content);
//         free(start);
//         *lst = NULL;
//         return;
//     }

//     temp = start;
//     while (temp->next != start) {
//         temp = temp->next;
//     }
//     temp->next = start->next;
//     *lst = start->next;
//     free(start->content);
//     free(start);
// }

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *last;

    if (lst == NULL || new == NULL)
        return;

    if (*lst == NULL) {
        *lst = new;
        new->next = new; // Zirkuläre Verbindung
        return;
    }

    last = *lst;
    while (last->next != *lst) {
        last = last->next;
    }
    last->next = new;
    new->next = *lst; // Zirkuläre Verbindung
}

void new_split(const char *str, t_list **head)
{
    int     num;
    int     in_number;
    int     *num_ptr;
    t_list  *new_node;

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

void printList(t_list *head)
{
    t_list  *temp;
    t_list  *start = head;

    if (head == NULL)
        return;

    temp = head;
    do {
        printf("%d ", *((int *)temp->content));
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}

int main(int argc, char *argv[])
{
    int         *num_ptr;
    t_list      *new_node;
    const char  *str;
    int         i;
    t_list      *stack_a;
    t_list      *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
    {
        printf("Error!\n");
        return (1);
    }
    if (argc == 2)
    {
        str = argv[1];
        new_split(str, &stack_a);
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            num_ptr = (int *)malloc(sizeof(int));
            *num_ptr = atoi(argv[i]);
            if (*num_ptr)
            {
                new_node = ft_lstnew(num_ptr);
                ft_lstadd_back(&stack_a, new_node);
            }
            else
            {
                free(num_ptr);
            }
            i++;
        }
    }
    printf("Stack A: ");
    printList(stack_a);
    // Stack B initial leer, weitere Operationen hier
    printf("Stack B: ");
    printList(stack_b);

    // Beispieloperation: Verschieben von Elementen von stack_a nach stack_b
    while (stack_a != NULL) {
        new_node = stack_a;
        ft_lstremove_front(&stack_a);
        ft_lstadd_back(&stack_b, new_node);
    }

    printf("Nach Verschieben von stack_a nach stack_b:\n");
    printf("Stack A: ");
    printList(stack_a);
    printf("Stack B: ");
    printList(stack_b);

    free_list(stack_a);
    free_list(stack_b);

    return (0);
}
