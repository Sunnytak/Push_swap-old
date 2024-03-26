/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:58:45 by stak              #+#    #+#             */
/*   Updated: 2024/03/26 11:41:15 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	long	n;
// 	t_list	*head;
// 	t_list	*stack_a;

// 	i = 1;
// 	head = NULL;
// 	if (1 == argc || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 	{
// 		argv = ft_split(argv[1], ' ');
// 		i--;
// 	}
// 	while (argv[i])
// 	{
// 		n = ft_atoi(argv[i]);
// 		if (n > INT_MAX || n < INT_MIN)
// 			printf("");
// 		if (ft_atoi(argv[i]) != 0 && !ft_dup_check(argv, i))
// 		{
// 			stack_a = malloc(sizeof(t_list));
// 			stack_a->content = ft_atoi(argv[i]);
// 			stack_a->next = head;
// 			head = stack_a;
// 			printf("Inserted: %ld\n", stack_a->content);
// 		}
// 		else
// 		{
// 			printf("Error");
// 			return (1);
// 		}
// 		i++;
// 	}
// 	// Swap nodes
// 	swap_sa(&head);

// 	// Print the list after swapping
// 	printf("List content after swapping:\n");
// 	t_list *current = head;
// 	while (current != NULL)
// 	{
// 		printf("%ld\n", current->content);
// 		current = current->next;
// 	}
// 	// t_list *current = head;
// 	// while(current != NULL)
// 	// {
// 	// 	printf("after%ld\n", current->content);
// 	// 	current = current->next;
// 	// }
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
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
// int	main(int argc, char **argv)
// {
// 	int		i;
// 	t_list	*head;
// 	t_list	*stack_a;

// 	i = 1;
// 	head = NULL;
// 	if (1 == argc || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	else if (argc == 2)
// 	{
// 		argv = ft_split(argv[1], ' ');
// 		i--;
// 	}
// 	while (argv[i])
// 	{
// 		if (ft_atoi(argv[i]) != 0 && !ft_dup_check(argv, i))
// 		{
// 			stack_a = malloc(sizeof(t_list));
// 			stack_a->content = ft_atoi(argv[i]);
// 			stack_a->next = head;
// 			head = stack_a;
// 			printf("Inserted: %ld\n", stack_a->content);
// 		}
// 		else
// 		{
// 			printf("Error");
// 			return (1);
// 		}
// 		i++;
// 	}
// 	// Swap nodes
// 	sa(&head, false);

// 	// Print the list after swapping
// 	printf("List content after swapping:\n");
// 	t_list *current = head;
// 	while (current != NULL)
// 	{
// 		printf("%ld\n", current->content);
// 		current = current->next;
// 	}
// 	// t_list *current = head;
// 	// while(current != NULL)
// 	// {
// 	// 	printf("after%ld\n", current->content);
// 	// 	current = current->next;
// 	// }
// 	return (0);
// }

// static void swap(t_list **head)
// {
// 	int	len;
//  	len = ft_lstsize(*head);
// 	if (NULL == *head || NULL == head || 1 == len)
// 		return ;
//     t_list *first = *head;
//     t_list *second = first->next;
//     first->next = second->next;
//     second->next = first;
//     *head = second;
// }

// void swap_sa(t_list **head)
// {
//     // Check if the list is empty or has only one element
//     if (*head == NULL || (*head)->next == NULL)
//         return;

//     // Save pointers to the first two nodes
//     t_list *first = *head;
//     t_list *second = (*head)->next;

//     // Swap the positions of the first two nodes
//     first->next = second->next;
//     second->next = first;

//     // Update the head pointer to point to the new first node (which is the second node after swapping)
//     *head = second;
// }
// void	sa(t_list	**a, bool checker)
// {
// 	swap(a);
// 	if (!checker)
// 		write(1, "sa\n", 3);
// }

// void	sb(t_list **b, bool checker)
// {
// 	swap(b);
// 	if (!checker)
// 		write(1, "sb\n", 3);
// }

// void	ss(t_list **a, t_list **b, bool checker)
// {
// 	swap(a);
// 	swap(b);
// 	if (!checker)
// 		write(1, "ss\n", 3);
// }
// int	ft_lstsize(t_list *lst)
// {
// 	int	count;

// 	count = 0;
// 	if (lst == NULL)
// 		return (0);
// 	while (lst != NULL)
// 	{
// 		count++;
// 		lst = lst -> next;
// 	}
// 	return (count);
// }

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