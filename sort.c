/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:30:31 by stak              #+#    #+#             */
/*   Updated: 2024/03/25 12:16:29 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	t_list	*max_node;

	max_node = highest(a);
	if ((*a)->lst == max_node->lst)
		rotate_ra(a);
	else if ((*a)->next->lst == max_node->lst)
		reverse_rotate_rra(a);
	if ((*a)->lst > (*a)->next->lst)
		swap_sa(a);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;

	min = lowest(stack_a);
	if ((*stack_a)->content != min->content)
	{
		while ((*stack_a)->content != min->content)
		{
			if (min->content == ft_lstlast(*stack_a)->content || \
				min->content == ft_lstlast(*stack_a)->prev->content)
				reverse_rotate_rra(stack_a);
			else
				rotate_ra(stack_a);
		}
	}
	if ((*stack_a)->content == min->content)
	{
		push_pb(stack_a, stack_b);
		sort_3(stack_a);
		push_pa(stack_a, stack_b);
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;

	while (ft_lstsize(*stack_a) > 3)
	{
		min = lowest(stack_a);
		while ((*stack_a)->content != min->content)
		{
			if (min->content == ft_lstlast(*stack_a)->content || \
			min->content == (*stack_a)->prev->content)
				reverse_rotate_rra(stack_a);
			else
				rotate_ra(stack_a);
		}
		push_pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (*stack_b)
		push_pa(stack_a, stack_b);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size == 2)
		swap_sa(stack_a);
	if (stack_size == 3)
		sort_3(stack_a);
	if (stack_size == 4)
		sort_4(stack_a, stack_b);
	if (stack_size == 5)
		sort_5(stack_a, stack_b);
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}


// int main(void)
// {
// 	int i = 0;

// 	t_list *stack_a = NULL; // First stack
// 	t_list *stack_b = NULL; // Second stack

// 	// Populate the stack
// 	while (i < 10)
// 	{
// 		t_list *node = malloc(sizeof(t_list));
// 		if (!node)
// 			return (0);
// 		node->content = i;
// 		node->next = NULL;
// 		ft_lstadd_back(&stack_a, node);
// 		i++;
// 	}

// 	printf("%s\n", "Before sorting:");
// 	t_list *current = stack_a;
// 	while (current != NULL)
// 	{
// 		printf("%ld\n", current->content); // Assuming content is an integer
// 		current = current->next;
// 	}

// 	// Sort the stack
// 	sort_5(&stack_a, &stack_b);

// 	printf("%s\n", "After sorting:");
// 	t_list *current_sorted = stack_a;
// 	while (current_sorted != NULL)
// 	{
// 		printf("%ld\n", current_sorted->content); // Assuming content is an integer
// 		current_sorted = current_sorted->next;
// 	}

// 	return (0);
// }

// //sort_3
// int main(void)
// {
//     int i = 0;

//     t_list *root = NULL; // Single stack

//     // Populate the stack
//     while (i < 10)
//     {
//         t_list *node = malloc(sizeof(t_list));
//         if (!node)
//             return (0);
//         node->content = i;
//         node->next = NULL;
//         ft_lstadd_back(&root, node);
//         i++;
//     }

//     printf("%s\n", "Before sorting:");
//     t_list *current = root;
//     while (current != NULL)
//     {
//         printf("%ld\n", current->content); // Assuming content is an integer
//         current = current->next;
//     }

//     // Sort the stack
//     sort_3(&root);

//     printf("%s\n", "After sorting:");
//     t_list *current_sorted = root;
//     while (current_sorted != NULL)
//     {
//         printf("%ld\n", current_sorted->content); // Assuming content is an integer
//         current_sorted = current_sorted->next;
//     }

//     return (0);
// }
