/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stak <stak@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:30:09 by stak              #+#    #+#             */
/*   Updated: 2024/04/09 09:30:11 by stak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = temp->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	if (*dest != NULL)
		(*dest)->prev = temp;
	temp->next = *dest;
	temp->prev = NULL;
	*dest = temp;
}

void	pa(t_node **a_stack, t_node **b_stack)
{
	push(b_stack, a_stack);
	write(1, "pa\n", 3);
}

void	pb(t_node **a_stack, t_node **b_stack)
{
	push(a_stack, b_stack);
	write(1, "pb\n", 3);
}
