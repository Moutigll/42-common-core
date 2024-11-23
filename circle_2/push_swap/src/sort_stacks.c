/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:14:07 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/23 15:42:59 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 0 && stack_a->head->prev->value > stack_b->head->value)
		reverse_rotate_stack(stack_a, "rra\n");
	while (stack_b->size > 0)
	{
		while ((stack_a->head->prev->value > stack_b->head->value
				&& (is_min_or_max(stack_a, stack_a->head->prev->value) != 2)))
			reverse_rotate_stack(stack_a, "rra\n");
		if (stack_b->size > 0)
			push_stack(stack_b, stack_a, "pa\n");
	}
	while (stack_a->head->prev->value < stack_a->head->value)
		reverse_rotate_stack(stack_a, "rra\n");
	free_stack(stack_a);
	free_stack(stack_b);
}

void	sort2(t_stack *stack_a, t_stack *stack_b)
{
	if (is_min_or_max(stack_b, stack_b->head->value) != 2)
	{
		if (stack_b->head->value < stack_a->head->prev->value
			&& stack_b->head->value > stack_a->head->next->value)
		{
			reverse_rotate_stack(stack_a, "rra\n");
			push_stack(stack_b, stack_a, "pa\n");
			rotate_stack(stack_a, "ra\n");
			rotate_stack(stack_a, "ra\n");
		}
		else
		{
			push_stack(stack_b, stack_a, "pa\n");
			if (stack_a->head->value > stack_a->head->prev->value)
				rotate_stack(stack_a, "ra\n");
			if (stack_a->head->value > stack_a->head->next->value)
				swap_stack(stack_a, "sa\n");
		}
	}
	sort3(stack_a, stack_b);
}

void	sort_stacks(t_stack *stack_a,
			t_stack *stack_b)
{
	run_tests(stack_a, stack_b);
	push_stack(stack_a, stack_b, "pb\n");
	if (stack_a->size < 4)
		handle_len5(stack_a, stack_b);
	push_stack(stack_a, stack_b, "pb\n");
	if (stack_a->size < 4)
		handle_len5(stack_a, stack_b);
	if (stack_b->head->value < stack_b->head->next->value)
		swap_stack(stack_b, "sb\n");
	if (stack_a->head->value < stack_b->head->value
		&& stack_a->head->value > stack_b->head->next->value)
	{
		rotate_stack(stack_b, "rb\n");
		push_stack(stack_a, stack_b, "pb\n");
		swap_stack(stack_b, "sb\n");
		reverse_rotate_stack(stack_b, "rrb\n");
	}
	else
		push_stack(stack_a, stack_b, "pb\n");
	while (stack_a->size > 3)
		get_best_cost(stack_a, stack_b);
	while (is_min_or_max(stack_b, stack_b->head->prev->value) != 1)
		rotate_stack(stack_b, "rb\n");
	handle_len3(stack_a);
	sort2(stack_a, stack_b);
}
