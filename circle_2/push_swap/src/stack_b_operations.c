/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:37:55 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/06 13:39:49 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*temp;

	if (!stack_a->head)
		return (0);
	if (!stack_b->head)
	{
		stack_b->head = stack_a->head;
		stack_a->head = stack_a->head->next;
		stack_b->head->next = stack_b->head;
		stack_b->head->prev = stack_b->head;
		stack_a->size--;
		stack_b->size++;
		return (1);
	}
	temp = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_b->head->prev->next = temp;
	temp->prev = stack_b->head->prev;
	stack_b->head->prev = temp;
	temp->next = stack_b->head;
	stack_a->size--;
	stack_b->size++;
	return (1);
}

int	swap_b(t_stack *stack_b)
{
	t_clist	*temp;

	if (!stack_b->head || !stack_b->head->next)
		return (0);
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	temp->next = stack_b->head->next;
	stack_b->head->next = temp;
	stack_b->head->prev = temp;
	temp->prev = stack_b->head;
	return (1);
}
