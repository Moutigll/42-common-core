/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:37:20 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/06 13:39:23 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*temp;

	if (!stack_b->head)
		return (0);
	if (!stack_a->head)
	{
		stack_a->head = stack_b->head;
		stack_b->head = stack_b->head->next;
		stack_a->head->next = stack_a->head;
		stack_a->head->prev = stack_a->head;
		stack_a->size++;
		stack_b->size--;
		return (1);
	}
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_a->head->prev->next = temp;
	temp->prev = stack_a->head->prev;
	stack_a->head->prev = temp;
	temp->next = stack_a->head;
	stack_a->size++;
	stack_b->size--;
	return (1);
}

int	swap_a(t_stack *stack_a)
{
	t_clist	*temp;

	if (!stack_a->head || !stack_a->head->next)
		return (0);
	temp = stack_a->head;
	stack_a->head = stack_a->head->next;
	temp->next = stack_a->head->next;
	stack_a->head->next = temp;
	stack_a->head->prev = temp;
	temp->prev = stack_a->head;
	return (1);
}
