/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:31:51 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/16 16:14:28 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Return 1 if number is the smallest n stack, 
// 2 if number is the biggest and 0 otherwise
int	is_min_or_max(t_stack *stack, int number)
{
	t_clist	*next;

	next = stack->head->next;
	while (next != stack->head && next->value >= number)
		next = next->next;
	if (stack->head == next && stack->head->value >= number)
		return (1);
	next = stack->head->next;
	while (next != stack->head && next->value <= number)
		next = next->next;
	if (stack->head == next && stack->head->value <= number)
		return (2);
	return (0);
}

// If the position is before the middle of the stack, return the cost in rb
// Otherwise return the cost in rrb
t_costb	*compute_stackb_cost(t_stack *stack_b, int i)
{
	t_costb	*cost;

	cost = (t_costb *)malloc(sizeof(t_costb));
	if (!cost)
		return (NULL);
	if (i <= stack_b->size / 2)
	{
		cost->type = 0;
		cost->value = i;
	}
	else
	{
		cost->type = 1;
		cost->value = stack_b->size - i;
	}
	return (cost);
}

/*
	Scan the list to find the place where the number would be considered sorted
	Always sort in descending order and breaks if sorted to get position with i
	If the number is a new minimum or maximum we instead look for the previous
	Max or Min. For Max we check the next position from index to keep descending
*/
t_costb	*get_stackb_cost(int number, t_stack *stack_b)
{
	int		i;
	t_clist	*next;
	int		min_or_max;

	i = 1;
	next = stack_b->head;
	min_or_max = is_min_or_max(stack_b, number);
	while (i < stack_b->size)
	{
		if (min_or_max == 0 && next->value > number
			&& next->next->value < number)
			break ;
		if (min_or_max == 1
			&& is_min_or_max(stack_b, next->value) == 1)
			break ;
		if (min_or_max == 2
			&& is_min_or_max(stack_b, next->next->value) == 2)
			break ;
		next = next->next;
		i++;
	}
	return (compute_stackb_cost(stack_b, i));
}

// Perform n times the function f with the parameters provided

void	print_loop(int (*f)(t_stack *, void *), t_stack *param1,
			void *param2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		f(param1, param2);
		i++;
		if (f == rotate_both)
			write(1, "rr\n", 3);
		else if (f == reverse_rotate_both)
			write(1, "rrr\n", 4);
	}
}

// Use the print_loop above to perform each stack operations according to best
void	print_operations_string(t_total_cost *best,	t_stack *stack_a,
			t_stack *stack_b)
{
	print_loop(rotate_both, stack_a, stack_b, best->rr);
	print_loop(reverse_rotate_both, stack_a, stack_b, best->rrr);
	print_loop(rotate_stack, stack_a, "ra\n", best->ra);
	print_loop(rotate_stack, stack_b, "rb\n", best->rb);
	print_loop(reverse_rotate_stack, stack_a, "rra\n", best->rra);
	print_loop(reverse_rotate_stack, stack_b, "rrb\n", best->rrb);
	push_stack(stack_a, stack_b, "pb\n");
}
