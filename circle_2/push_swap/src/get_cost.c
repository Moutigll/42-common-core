/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:54:49 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/11 17:20:45 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extract_best_cost(t_total_cost *cost_list, t_stack *stack_a,
			t_stack *stack_b)
{
	t_total_cost	*best;
	t_total_cost	*current;

	best = cost_list;
	current = cost_list->next;
	while (current)
	{
		if (current->total < best->total && current->total != 0)
			best = current;
		current = current->next;
	}
	print_operations_string(best, stack_a, stack_b);
	current = cost_list;
	while (current)
	{
		best = current;
		current = current->next;
		free(best);
	}
}

void	compute_total_cost2(t_total_cost *cost,
			t_costb *costb, t_stack *stack_a, int i)
{
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
}

void	compute_total_cost(t_stack *stack_a, t_args *args, t_stack *stack_b)
{
	t_costb			*costb;
	int				i;

	i = args->i;
	costb = get_stackb_cost(args->next->value, stack_b);
	compute_total_cost2(args->cost, costb, stack_a, i);
	if (costb->type == 1 && i > stack_a->size / 2)
	{
		if (costb->value < stack_a->size - i)
		{
			args->cost->rrr = costb->value;
			args->cost->rra = stack_a->size - i - costb->value;
		}
		else
		{
			args->cost->rrr = stack_a->size - i;
			args->cost->rrb = costb->value - (stack_a->size - i);
		}
	}
	args->cost->total = args->cost->ra + args->cost->rb + args->cost->rr
		+ args->cost->rra + args->cost->rrb + args->cost->rrr + 1;
	free(costb);
}

t_args	*init_args(t_stack *stack_a)
{
	t_args			*args;

	args = (t_args *)malloc(sizeof(t_args));
	args->cost = init_total_cost();
	args->i = 0;
	args->next = stack_a->head;
	args->cost_list = args->cost;
	return (args);
}

void	get_best_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_args			*args;
	int				best;

	args = init_args(stack_a);
	best = -1;
	while (args->i < stack_a->size)
	{
		if (args->i < best || stack_a->size - args->i < best || best == -1)
		{
			compute_total_cost(stack_a, args, stack_b);
			if (args->cost->total < best || best == -1)
				best = args->cost->total;
		}
		else
			args->cost->total = 100000;
		args->cost->next = init_total_cost();
		if (args->cost->total < 3 && args->cost->total > 0)
			break ;
		args->cost = args->cost->next;
		args->next = args->next->next;
		args->i++;
	}
	free(args);
	extract_best_cost(args->cost_list, stack_a, stack_b);
}
