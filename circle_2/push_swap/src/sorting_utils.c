/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:59:33 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/10 13:34:11 by ele-lean         ###   ########.fr       */
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
