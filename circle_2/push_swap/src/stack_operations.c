/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:37:20 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/08 06:59:47 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stack *stack_a, t_stack *stack_b)
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

int	swap_stack(t_stack *stack)
{
	int	temp;

	if (!stack->head || !stack->head->prev)
		return (0);
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	return (1);
}

int	rotate_stack(t_stack *stack)
{
	if (!stack->head || !stack->head->prev)
		return (0);
	stack->head = stack->head->next;
	return (1);
}

int	reverse_rotate_stack(t_stack *stack)
{
	if (!stack->head || !stack->head->prev)
		return (0);
	stack->head = stack->head->prev;
	return (1);
}
