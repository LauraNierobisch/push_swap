#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}


void split(const char *str, t_list **head)
{
int num = 0;
int in_number = 0;

while (*str != '\0') {
if (isdigit(*str)) {
num = num * 10 + (*str - '0');
in_number = 1;
} else if (in_number) {
int *num_ptr = malloc(sizeof(int));
if (num_ptr != NULL) {
*num_ptr = num;
t_list *new_node = ft_lstnew(num_ptr);
if (new_node != NULL) {
ft_lstadd_back(head, new_node);
} else {
free(num_ptr);
}
}
num = 0;
in_number = 0;
}
str++;
}
if (in_number) {
int *num_ptr = malloc(sizeof(int));
if (num_ptr != NULL) {
*num_ptr = num;
t_list *new_node = ft_lstnew(num_ptr);
if (new_node != NULL) {
ft_lstadd_back(head, new_node);
} else {
free(num_ptr);
}
}
}
}


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
	ft_printf("Error!\n");
	return 1;
	}

if (argc == 2)
{
	const char *str = argv[1];

	split(str, &head);

	else
	{
		i = 1;
		if( i < argc)
		{
		int *num_ptr = malloc(sizeof(int));
		i++;
		if(num_ptr = ft_atoi(argv[i]))
		{
		t_list *new_node = ft_lstnew(num_ptr);
		ft_lstadd_back(&head, new_node);
		}
		}
	}

	//Funktion mit der ich dann die Zahlen sortiere
	t_list *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
	}
	return (0);
}

