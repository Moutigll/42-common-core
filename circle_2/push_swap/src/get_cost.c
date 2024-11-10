/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:54:49 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/10 13:30:10 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min_or_max(t_stack *stack, int number)
{
	t_clist	*next;
	int		i;

	next = stack->head->next;
	i = 0;
	while (next != stack->head && next->value >= number)
	{
		next = next->next;
		i++;
	}
	if (i == stack->size - 1 && stack->head->value >= number)
		return (1);
	next = stack->head->next;
	i = 0;
	while (next != stack->head && next->value <= number)
	{
		next = next->next;
		i++;
	}
	if (i == stack->size - 1 && stack->head->value <= number)
		return (2);
	return (0);
}

t_costb	*get_stackb_cost(int number, t_stack *stack_b)
{
	int		i;
	t_costb	*cost;
	t_clist	*next;
	int		min_or_max;

	i = 1;
	next = stack_b->head;
	min_or_max = is_min_or_max(stack_b, number);
	cost = (t_costb *)malloc(sizeof(t_costb));
	while (i < stack_b->size)
	{
		if (is_min_or_max(stack_b, number) == 0 && next->value > number && next->next->value < number)
			break ;
		if (is_min_or_max(stack_b, number) == 1 && is_min_or_max(stack_b, next->value) == 1)
			break ;
		if (is_min_or_max(stack_b, number) == 2 && is_min_or_max(stack_b, next->next->value) == 2)
			break ;
		next = next->next;
		i++;
	}
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

// Perform n times the function f with the parameters provided
void	print_loop(int (*f)(t_stack *, void *), t_stack *param1, void *param2, int n)
{
	int i = 0;
	while (i < n)
	{
		f(param1, param2);
		i++;
	}
}


// Use the print_loop above to perform each stack operations according to best
void	get_operations_string(t_total_cost *best,	t_stack *stack_a,
			t_stack *stack_b)
{
	print_loop(rotate_both, stack_a, stack_b, best->rr);
	print_loop(reverse_rotate_both, stack_a, stack_b, best->rrr);
	print_loop(rotate_stack, stack_a, "ra", best->ra);
	print_loop(rotate_stack, stack_b, "rb", best->rb);
	print_loop(reverse_rotate_stack, stack_a, "rra", best->rra);
	print_loop(reverse_rotate_stack, stack_b, "rrb", best->rrb);
	push_stack(stack_a, stack_b, "pb");
	free(best);
}

void	extract_best_cost(t_total_cost *cost_list, t_stack *stack_a,
			t_stack *stack_b)
{
	t_total_cost	*best;
	t_total_cost	*current;
	t_total_cost	*temp;

	best = cost_list;
	current = cost_list->next;
	while (current)
	{
		if (current->total < best->total && current->total != 0)
		{
			free(best);
			best = current;
		}
		else
		{
			temp = current;
			free(temp);
		}
		current = current->next;
	}
	get_operations_string(best, stack_a, stack_b);
}

void	get_best_cost(t_stack *stack_a, t_stack *stack_b)
{
	int				i;
	t_clist			*next;
	t_costb			*costb;
	t_total_cost	*cost_list;
	t_total_cost	*cost;
	int				best;

	i = 0;
	next = stack_a->head;
	cost = init_total_cost();
	cost_list = cost;
	best = 100000;
	while (i < stack_a->size)
	{
		if (i < best || stack_a->size - i < best)
		{
			costb = get_stackb_cost(next->value, stack_b);
			if (costb->type == 0 && i <= stack_a->size / 2)
			{
				if (costb->value < i)
				{
					cost->rr = costb->value;
					cost->ra = i - costb->value;
				}
				else
				{
					cost->rr = i;
					cost->rb = costb->value - i;
				}
			}
			else if (costb->type == 0 && i > stack_a->size / 2)
			{
				cost->rb = costb->value;
				cost->rra = stack_a->size - i;
			}
			else if (costb->type == 1 && i <= stack_a->size / 2)
			{
				cost->ra = i;
				cost->rrb = costb->value;
			}
			else if (costb->type == 1 && i > stack_a->size / 2)
			{
				if (costb->value < stack_a->size - i)
				{
					cost->rrr = costb->value;
					cost->rra = stack_a->size - i - costb->value;
				}
				else
				{
					cost->rrr = stack_a->size - i;
					cost->rrb = costb->value - (stack_a->size - i);
				}
			}
			cost->total = cost->ra + cost->rb + cost->rr + cost->rra + cost->rrb + cost->rrr + 1;
			if (cost->total < best)
				best = cost->total;
			free(costb);
		}
		else
			cost->total = 100000;
		cost->next = init_total_cost();
		if (cost->total < 3)
			break ;
		cost = cost->next;
		next = next->next;
		i++;
	}
	extract_best_cost(cost_list, stack_a, stack_b);
}
