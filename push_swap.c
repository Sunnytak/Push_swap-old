/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:58:45 by stak              #+#    #+#             */
/*   Updated: 2024/02/12 17:53:34 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	i;
	
	i = 1;
	t_list *head = NULL;
	if (1 == argc)
		printf("%s\n", argv[0]);
	else if (2 == argc)
	{
        argv = ft_split(argv[1], ' ');
		i--;
    }
	while (argv[i])
    {
		if (ft_atoi(argv[i]) != 0 && !ft_dup_check(argv, i))
		{
			t_list *stack_a = malloc (sizeof(t_list));
			stack_a->content = ft_atoi(argv[i]);
			stack_a->next = NULL;
			sb(&head, false);
		}
		else 
		{
			printf("Error");
			return (1);
		}
		i++;
    }
	t_list *current = head;
	while(current != NULL)
	{
		printf("%ld\n", current->content);
		current = current->next;
	}
    return (0);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next)
		temp = temp -> next;
	temp -> next = new;
}
static void	swap(t_list **head)
{
	int	len;

	len = ft_lstsize(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	t_list *second = (*head)->next;
    (*head)->next = second->next;
    second->next = *head;
    *head = second;
}

void	sa(t_list	**a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}
// void reverse(t_list **lst) 
// {
//     t_list *prev = NULL;
//     t_list current = **lst;
//     t_list *next = NULL;

//     while (current != NULL) 
// 	{
//         next = current->next; // Store the next node
//         current->next = prev; // Reverse the current node's pointer
//         prev = current;       // Move pointers one position ahead
//         current = next;
//     }

//     *lst = prev; // Update the head pointer to point to the new head (prev)
// }

// void ft_list(char **argv) 
// {
//     if ((argv[]) > ft_atoi(argv[2])) {
//         ft_swap_sa(&argv[1], &argv[2]);
//         ft_list(argv); // Recursively call ft_list
//     }
// }

// void ft_swap_sa(int **nbr, int **index) {
//     // Swap the values pointed to by nbr and index
//     if (nbr && index) {
//         int temp = **nbr;
//         **nbr = **index;
//         **index = temp;
//     }
// }


// void	ft_list(char **argv)
// {
// 	while (2 == argv)
// 	{
// 		if ((*argv)->nbr > (*argv)->next->nbr) 
// 		sa(a, false)
// 	}
// }
// void	ft_swap_sa(t_stack_node *nbr, t_stack_node *index)
// {
// 	if (nbr && index)
// 	{
// 		nbr -> index = nbr;
// 		nbr = index;
// 	}
// }