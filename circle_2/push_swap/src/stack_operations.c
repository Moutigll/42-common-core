/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:37:20 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/10 13:31:07 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//All function to to manipulate the stacks

void	push_check_stack(t_stack *stack_a, t_clist *temp)
{
	if (stack_a->size > 1)
	{
		stack_a->head = stack_a->head->next;
		stack_a->head->prev = temp->prev;
		stack_a->head->prev->next = stack_a->head;
	}
	else
		stack_a->head = NULL;
}

int	push_stack(t_stack *stack_a, t_stack *stack_b, char *str)
{
	t_clist	*temp;

	if (!stack_a->head)
		return (0);
	temp = stack_a->head;
	push_check_stack(stack_a, temp);
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
	ft_printf("%s\n", str);
	stack_a->size--;
	stack_b->size++;
	return (1);
}

int	swap_stack(t_stack *stack, char *str)
{
	int	temp;

	if (!stack->head || !stack->head->prev)
		return (0);
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
	if (str)
		ft_printf("%s\n", str);
	return (1);
}

int	rotate_stack(t_stack *stack, void *str)
{
	str = (char *)str;
	if (!stack->head || !stack->head->prev)
		return (0);
	stack->head = stack->head->next;
	if (str)
		ft_printf("%s\n", str);
	return (1);
}

int	reverse_rotate_stack(t_stack *stack, void *str)
{
	str = (char *)str;
	if (!stack->head || !stack->head->prev)
		return (0);
	stack->head = stack->head->prev;
	if (str)
		ft_printf("%s\n", str);
	return (1);
}
