/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:59:33 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/12 16:17:26 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_len3(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->head->next->value
		&& stack_a->head->value < stack_a->head->prev->value)
		swap_stack(stack_a, "sa");
	else if (stack_a->head->value > stack_a->head->prev->value
		&& stack_a->head->prev->value > stack_a->head->next->value)
		rotate_stack(stack_a, "ra");
	else if (stack_a->head->value > stack_a->head->prev->value
		&& stack_a->head->value < stack_a->head->next->value)
		reverse_rotate_stack(stack_a, "rra");
	else if (stack_a->head->value > stack_a->head->next->value
		|| stack_a->head->next->value > stack_a->head->prev->value)
	{
		swap_stack(stack_a, "sa");
		if (stack_a->head->value > stack_a->head->next->value)
			rotate_stack(stack_a, "ra");
		else
			reverse_rotate_stack(stack_a, "rra");
	}
}

void	handle_len5bis(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->head->value > stack_a->head->next->value
		&& stack_b->head->value < stack_a->head->next->next->value)
	{
		rotate_stack(stack_a, "ra");
		push_stack(stack_b, stack_a, "pa");
		swap_stack(stack_a, "sa");
		reverse_rotate_stack(stack_a, "rra");
	}
	else if (stack_b->head->value > stack_a->head->prev->prev->value
		&& stack_b->head->value < stack_a->head->prev->value)
	{
		reverse_rotate_stack(stack_a, "rra");
		push_stack(stack_b, stack_a, "pa");
		rotate_stack(stack_a, "ra");
		rotate_stack(stack_a, "ra");
	}
}

void	handle_len5(t_stack *stack_a, t_stack *stack_b,
	struct sorted_list *presorted)
{
	handle_len3(stack_a);
	while (stack_b->size > 0)
	{
		if (stack_b->head->value > stack_a->head->prev->value)
		{
			push_stack(stack_b, stack_a, "pa");
			rotate_stack(stack_a, "ra");
		}
		else if (stack_b->head->value < stack_a->head->value)
			push_stack(stack_b, stack_a, "pa");
		else if (stack_b->head->value > stack_a->head->value
			&& stack_b->head->value < stack_a->head->next->value)
		{
			push_stack(stack_b, stack_a, "pa");
			swap_stack(stack_a, "sa");
		}
		else if (stack_b->head->value > stack_a->head->next->value
			&& stack_b->head->value < stack_a->head->next->next->value)
			handle_len5bis(stack_a, stack_b);
	}
	free_list(presorted);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(0);
}

void	bubblesort(struct sorted_list *list)
{
	struct sorted_list	*current;
	int					temp;

	current = list;
	while (current->next)
	{
		if (current->value > current->next->value)
		{
			temp = current->value;
			current->value = current->next->value;
			current->next->value = temp;
			current = list;
		}
		else
			current = current->next;
	}
}

// init total cost structure used to keep cost to sort each number
t_total_cost	*init_total_cost(void)
{
	t_total_cost	*cost;

	cost = (t_total_cost *)malloc(sizeof(t_total_cost));
	if (!cost)
		return (NULL);
	cost->ra = 0;
	cost->rb = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rr = 0;
	cost->rrr = 0;
	cost->total = 0;
	cost->next = NULL;
	return (cost);
}
