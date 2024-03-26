/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:42:51 by stak              #+#    #+#             */
/*   Updated: 2024/03/26 11:36:40 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_list *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_list	*highest(t_list **stack)
{
	t_list	*current;
	t_list	*highest;

	current = *stack;
	highest = current->next;
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	while (current != NULL)
	{
		if (current->content > highest->content)
			highest = current;
		current = current->next;
	}
	return (highest);
}

t_list	*lowest(t_list **stack)
{
	t_list	*current;
	t_list	*lowest;

	current = *stack;
	lowest = current->next;
	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	while (current != NULL)
	{
		if (current->content < lowest->content)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

t_list	*find_last(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// int main() {
//     // Create a linked list for testing
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));

//     node1->content = 0;
//     node1->next = node2;
//     node2->content = 7;
//     node2->next = node3;
//     node3->content = 5;
//     node3->next = NULL;

//     t_list *stack = node1;

//     // Call the highest function and print the result
// 	t_list *result = highest(&stack);
//     if (result == 0)
//         printf("The list is empty or has only one element.\n");
//     else
//         printf("The highest value in the list is: %ld\n", result->content);

//     // Free allocated memory
//     free(node1);
//     free(node2);
//     free(node3);

//     return 0;
// }