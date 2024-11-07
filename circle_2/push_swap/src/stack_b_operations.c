/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:37:55 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/07 11:07:20 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*temp;

	if (!stack_a->head)
		return (0);
	temp = stack_a->head;
	if (stack_a->size > 1)
	{
		stack_a->head = stack_a->head->next;
		stack_a->head->prev = temp->prev;
		stack_a->head->prev->next = stack_a->head;
	}
	else
		stack_a->head = NULL;
	if (!stack_b->head)
	{
		stack_b->head = temp;
		stack_b->head->next = stack_b->head;
		stack_b->head->prev = stack_b->head;
	}
	else
	{
		temp->next = stack_b->head;
		temp->prev = stack_b->head->prev;
		stack_b->head->prev->next = temp;
		stack_b->head->prev = temp;
		stack_b->head = temp;
	}
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
	stack_b->head->prev = temp->prev;
	temp->prev = stack_b->head;
	return (1);
}

int	rotate_b(t_stack *stack_b)
{
	if (!stack_b->head || !stack_b->head->next)
		return (0);
	stack_b->head = stack_b->head->next;
	return (1);
}

int reverse_rotate_b(t_stack *stack_b)
{
	if (!stack_b->head || !stack_b->head->next)
		return (0);
	stack_b->head = stack_b->head->prev;
	return (1);
}