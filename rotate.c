/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:08:43 by stak              #+#    #+#             */
/*   Updated: 2024/02/16 16:31:29 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_list **a)
{
	t_list	*last_a;

	last_a = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (last_a->next != NULL)
		last_a = last_a->next;
	last_a->next = *a;
	*a = (*a)->next;
	last_a->next->next = NULL;
	printf("ra\n");
}

void	rotate_rb(t_list **b)
{
	t_list	*last_b;

	last_b = *b;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	while (last_b->next != NULL)
		last_b = last_b->next;
	last_b->next = *b;
	*b = (*b)->next;
	last_b->next->next = NULL;
	printf("rb\n");
}

void	rotate_rr(t_list **a, t_list **b)
{
	t_list	*last_a;
	t_list	*last_b;

	last_a = *a;
	last_b = *b;
	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	while (last_a->next != NULL)
		last_a = last_a->next;
	last_a->next = *a;
	*a = (*a)->next;
	last_a->next->next = NULL;
	while (last_b->next != NULL)
		last_b = last_b->next;
	last_b->next = *b;
	*b = (*b)->next;
	last_b->next->next = NULL;
	printf("rr\n");
}

int    main(void)
{
	int i;
	int j;
	i = 0;
	j = 5;

	t_list *root_a = NULL;
	t_list *root_b = NULL;

	while (i < 5)
	{
		t_list *stack_a = malloc(sizeof(t_list));
		if (!stack_a)
			return (0);
		stack_a->content = i;
		stack_a->next = NULL;
		ft_lstadd_back(&root_a, stack_a);
		i++;
	}
	while (j < 10)
	{
		t_list *stack_b = malloc(sizeof(t_list));
		if (!stack_b)
			return (0);
		stack_b->content = j;
		stack_b->next = NULL;
		ft_lstadd_back(&root_b, stack_b);
		j++;
	}
	printf("%s\n", "before rotate a:");
	t_list *current_a = root_a;
	while (current_a != NULL)
	{
		printf("%ld\n", current_a->content);
		current_a = current_a->next;
	}
	printf("%s\n", "before rotate b:");
	t_list *current_b = root_b;
	while (current_b != NULL)
	{
		printf("%ld\n", current_b->content);
		current_b = current_b->next;
	}
	printf("%s\n", "after rotate_ra a:");
	rotate_rr(&root_a, &root_b);
	t_list *current_a2 = root_a;
	while (current_a2 != NULL)
	{
		printf("%ld\n", current_a2->content);
		current_a2 = current_a2->next;
	}
	printf("%s\n", "after rotate_rb b:");
	// swap_ss(&root_a, &root_b);
	t_list *current_b2 = root_b;
	while (current_b2 != NULL)
	{
		printf("%ld\n", current_b2->content);
		current_b2 = current_b2->next;
	}
	return (0);
}
