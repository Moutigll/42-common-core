/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:14:07 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/10 20:42:04 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(struct sorted_list *presorted, t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		while ((stack_a->head->prev->value > stack_b->head->value
				&& is_min_or_max(stack_a, stack_a->head->prev->value) != 2)
			|| (stack_a->head->prev->value > stack_b->head->value
				&& stack_a->size == 3))
			reverse_rotate_stack(stack_a, "rra");
		if (stack_b->size > 0)
			push_stack(stack_b, stack_a, "pa");
	}
	reverse_rotate_stack(stack_a, "rra");
	free_list(presorted);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	sort2(struct sorted_list *presorted, t_stack *stack_a, t_stack *stack_b)
{
	if (is_min_or_max(stack_b, stack_b->head->value) != 2)
	{
		if (stack_b->head->value < stack_a->head->prev->value
			&& stack_b->head->value > stack_a->head->prev->prev->value)
		{
			reverse_rotate_stack(stack_a, "rra");
			push_stack(stack_b, stack_a, "pa");
			rotate_stack(stack_a, "ra");
			rotate_stack(stack_a, "ra");
		}
		push_stack(stack_b, stack_a, "pa");
		if (stack_a->head->value > stack_a->head->prev->value)
			rotate_stack(stack_a, "ra");
		if (stack_a->head->value > stack_a->head->next->value)
			swap_stack(stack_a, "sa");
	}
	sort3(presorted, stack_a, stack_b);
}

void	sort_stacks(struct sorted_list *presorted, t_stack *stack_a,
			t_stack *stack_b)
{
	run_tests(presorted, stack_a, stack_b);
	if (stack_a->size > 4)
		push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	if (stack_b->head->value < stack_b->head->next->value)
		swap_stack(stack_b, "sb");
	if (stack_a->head->value < stack_b->head->value
		&& stack_a->head->value > stack_b->head->next->value)
	{
		rotate_stack(stack_b, "rb");
		push_stack(stack_a, stack_b, "pb");
		swap_stack(stack_b, "sb");
		reverse_rotate_stack(stack_b, "rrb");
	}
	else
		push_stack(stack_a, stack_b, "pb");
	while (stack_a->size > 3)
		get_best_cost(stack_a, stack_b);
	while (is_min_or_max(stack_b, stack_b->head->prev->value) == 0)
		rotate_stack(stack_b, "rb");
	handle_len3(stack_a);
	sort2(presorted, stack_a, stack_b);
}
