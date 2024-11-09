/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:01:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/09 15:03:42 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_len3(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->head->next->value && stack_a->head->value < stack_a->head->prev->value)
	{
		ft_printf("sa\n");
		swap_stack(stack_a);
	}
	else if (stack_a->head->value > stack_a->head->prev->value && stack_a->head->prev->value > stack_a->head->next->value)
	{
		ft_printf("ra\n");
		rotate_stack(stack_a);
	}
	else if (stack_a->head->value > stack_a->head->prev->value && stack_a->head->value < stack_a->head->next->value)
	{
		ft_printf("rra\n");
		reverse_rotate_stack(stack_a);
	}
	else if (stack_a->head->value > stack_a->head->next->value || stack_a->head->next->value > stack_a->head->prev->value)
	{
		ft_printf("sa\n");
		swap_stack(stack_a);
		if (stack_a->head->value > stack_a->head->next->value)
		{
			ft_printf("ra\n");
			rotate_stack(stack_a);
		}
		else
		{
			ft_printf("rra\n");
			reverse_rotate_stack(stack_a);
		}
	}
}

int	main(int argc, char **argv)
{
	int					i;
	struct sorted_list	*presorted;
	struct sorted_list	*next;
	t_stack				*stack_a;
	t_stack				*stack_b;

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	presorted = append_sorted(NULL, ft_atoi(argv[i]));
	stack_a->head = insert_circular(NULL, ft_atoi(argv[i]));
	next = presorted;
	while (i < argc - 1)
	{
		i++;
		stack_a->head = insert_circular(stack_a->head, ft_atoi(argv[i]));
		next = append_sorted(next, ft_atoi(argv[i]));
	}
	stack_a->size = argc - 1;
	stack_a->head = stack_a->head->next;
	next = presorted;
	presort_bubblesorthehe(presorted);
	if (stack_a->size < 4)
	{
		if (stack_a->size == 2 && stack_a->head->value > stack_a->head->next->value)
		{
			ft_printf("sa\n");
			swap_stack(stack_a);
		}
		if (stack_a->size == 3)
			handle_len3(stack_a);
		free_list(presorted);
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	run_tests(next, stack_a, stack_b);
	if (stack_a->size > 4)
	{
		ft_printf("pb\n");
		push_stack(stack_a, stack_b);
	}
	ft_printf("pb\n");
	push_stack(stack_a, stack_b);
	if (stack_b->head->value < stack_b->head->next->value)
	{
		ft_printf("sb\n");
		swap_stack(stack_b);
	}
	if (stack_a->head->value < stack_b->head->value && stack_a->head->value > stack_b->head->next->value)
	{
		ft_printf("rb\n");
		rotate_stack(stack_b);
		ft_printf("pb\n");
		push_stack(stack_a, stack_b);
		ft_printf("sb\nrrb\n");
		swap_stack(stack_b);
		reverse_rotate_stack(stack_b);
	}
	else
	{
		ft_printf("pb\n");
		push_stack(stack_a, stack_b);
	}
	while (stack_a->size > 3)
	{
		get_best_cost(stack_a, stack_b);
	}
	while (is_min_or_max(stack_b, stack_b->head->prev->value) == 0)
	{
		ft_printf("rb\n");
		rotate_stack(stack_b);
	}
	handle_len3(stack_a);
	if (is_min_or_max(stack_b, stack_b->head->value) != 2)
	{
		if (stack_b->head->value < stack_a->head->prev->value && stack_b->head->value > stack_a->head->prev->prev->value)
		{
			ft_printf("rra\npa\nra\nra\n");
			reverse_rotate_stack(stack_a);
			push_stack(stack_b, stack_a);
			rotate_stack(stack_a);
			rotate_stack(stack_a);
		}
		ft_printf("pa\n");
		push_stack(stack_b, stack_a);
		if (stack_a->head->value > stack_a->head->prev->value)
		{
			ft_printf("ra\n");
			rotate_stack(stack_a);
		}
		if (stack_a->head->value > stack_a->head->next->value)
		{
			ft_printf("sa\n");
			swap_stack(stack_a);
		}
	}
	while (stack_b->size > 0 || is_min_or_max(stack_a, stack_a->head->prev->value) != 2)
	{
		while ((stack_a->head->prev->value > stack_b->head->value && is_min_or_max(stack_a, stack_a->head->prev->value) != 2) || (stack_a->head->prev->value > stack_b->head->value && stack_a->size == 3))
		{
			ft_printf("rra\n");
			reverse_rotate_stack(stack_a);
		}
		if (stack_b->size > 0)
		{
			ft_printf("pa\n");
			push_stack(stack_b, stack_a);
		}
	}
	free_list(presorted);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
