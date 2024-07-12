#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Für bool-Datentyp

// Definition der Linked List (Stack)
typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;

// Funktion zum Erstellen eines neuen Knotens
t_list *ft_lstnew(void *content) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node) {
        return NULL;
    }
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Funktion zum Hinzufügen eines neuen Knotens am Anfang der Liste
void ft_lstadd_front(t_list **lst, t_list *new) {
    if (lst == NULL) {
        return;
    }
    new->next = *lst;
    *lst = new;
}

// Funktion zum Hinzufügen eines neuen Knotens am Ende der Liste
void ft_lstadd_back(t_list **lst, t_list *new) {
    if (lst == NULL) {
        return;
    }
    if (*lst == NULL) {
        *lst = new;
        return;
    }
    t_list *last = *lst;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new;
}

// Funktion zum Entfernen des ersten Knotens der Liste
void ft_lstremove_front(t_list **lst) {
    if (lst == NULL || *lst == NULL) {
        return;
    }
    t_list *temp = *lst;
    *lst = (*lst)->next;
    free(temp->content); // Freigabe des Inhalts (hier int *)
    free(temp);          // Freigabe des Knotens
}

// Funktion zum Ausdrucken der Liste (für Debugging-Zwecke)
void printList(t_list *head) {
    t_list *temp = head;
    while (temp != NULL) {
        printf("%d ", *((int *)temp->content));
        temp = temp->next;
    }
    printf("\n");
}

// Funktion zum Freigeben der gesamten Liste
void free_list(t_list *head) {
    t_list *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->content);  // Freigabe des Inhalts (hier int *)
        free(temp);           // Freigabe des Knotens
    }
}

// Reverse Rotate Operationen
void rra(t_list **stack_a) {
    if (*stack_a != NULL && (*stack_a)->next != NULL) {
        t_list *second_last = NULL;
        t_list *last = *stack_a;

        while (last->next != NULL) {
            second_last = last;
            last = last->next;
        }

        second_last->next = NULL;
        ft_lstadd_front(stack_a, last);
    }
}

void rrb(t_list **stack_b) {
    if (*stack_b != NULL && (*stack_b)->next != NULL) {
        t_list *second_last = NULL;
        t_list *last = *stack_b;

        while (last->next != NULL) {
            second_last = last;
            last = last->next;
        }

        second_last->next = NULL;
        ft_lstadd_front(stack_b, last);
    }
}

void rrr(t_list **stack_a, t_list **stack_b) {
    rra(stack_a);
    rrb(stack_b);
}

int main() {
    // Beispiel zur Verwendung der Operationen
    t_list *stack_a = NULL; // Stack A
    t_list *stack_b = NULL; // Stack B

    // Beispielzahlen hinzufügen
    int num1 = 3, num2 = 1, num3 = 5, num4 = 2;
    ft_lstadd_front(&stack_a, ft_lstnew(&num1));
    ft_lstadd_front(&stack_a, ft_lstnew(&num2));
    ft_lstadd_front(&stack_a, ft_lstnew(&num3));
    ft_lstadd_front(&stack_a, ft_lstnew(&num4));

    printf("Unsortierter Stack A: ");
    printList(stack_a);

    // Beispiel: Sortieren mit ss (sa und sb gleichzeitig)
    printf("\nSortiere mit ss (sa und sb):\n");
    ss(&stack_a, &stack_b);
    printf("Sortierter Stack A: ");
    printList(stack_a);
    printf("Sortierter Stack B: ");
    printList(stack_b);

    // Freigabe der Listen
    free_list(stack_a);
    free_list(stack_b);

    return 0;
}
