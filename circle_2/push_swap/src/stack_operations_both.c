/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_both.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:25:46 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/16 15:50:51 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Functions to handle the operations of both stacks

int	rotate_both(t_stack *stack_a, void *stack_b)
{
	stack_b = (t_stack *)stack_b;
	rotate_stack(stack_a, NULL);
	rotate_stack(stack_b, NULL);
	return (1);
}

int	reverse_rotate_both(t_stack *stack_a, void *stack_b)
{
	stack_b = (t_stack *)stack_b;
	reverse_rotate_stack(stack_a, NULL);
	reverse_rotate_stack(stack_b, NULL);
	return (1);
}

int	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a, NULL);
	swap_stack(stack_b, NULL);
	return (1);
}
