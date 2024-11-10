/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:54:49 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/10 20:21:57 by ele-lean         ###   ########.fr       */
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

void	compute_total_cost(t_total_cost *cost, t_stack *stack_a, int i, t_clist *next, t_stack *stack_b)
{
	t_costb			*costb;

	costb = get_stackb_cost(next->value, stack_b);
	compute_total_cost2(cost, costb, stack_a, i);
	if (costb->type == 1 && i > stack_a->size / 2)
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
	cost->total = cost->ra + cost->rb + cost->rr
		+ cost->rra + cost->rrb + cost->rrr + 1;
	free(costb);
}

void	get_best_cost(t_stack *stack_a, t_stack *stack_b)
{
	int				i;
	t_clist			*next;
	t_total_cost	*cost_list;
	t_total_cost	*cost;
	int				best;

	i = 0;
	next = stack_a->head;
	cost = init_total_cost();
	cost_list = cost;
	best = -1;
	while (i < stack_a->size)
	{
		if (i < best || stack_a->size - i < best || best == -1)
		{
			compute_total_cost(cost, stack_a, i, next, stack_b);
			if (cost->total < best || best == -1)
				best = cost->total;
		}
		else
			cost->total = 100000;
		cost->next = init_total_cost();
		if (cost->total < 3 && cost->total > 0)
			break ;
		cost = cost->next;
		next = next->next;
		i++;
	}
	extract_best_cost(cost_list, stack_a, stack_b);
}
