/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:01:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/10 18:40:43 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct sorted_list	*init_lists(t_stack *stack_a,
						t_stack *stack_b, int argc, char **argv)
{
	struct sorted_list		*next;
	struct sorted_list		*presorted;
	struct circular_list	*temp;
	int						i;

	stack_b->head = NULL;
	stack_b->size = 0;
	i = 1;
	presorted = append_sorted(NULL, ft_atoi(argv[i]));
	stack_a->head = insert_circular(NULL, ft_atoi(argv[i]));
	next = presorted;
	temp = stack_a->head;
	while (i < argc - 1)
	{
		i++;
		temp = insert_circular(temp, ft_atoi(argv[i]));
		next = append_sorted(next, ft_atoi(argv[i]));
	}
	stack_a->size = argc - 1;
	bubblesort(presorted);
	return (presorted);
}

int	main(int argc, char **argv)
{
	struct sorted_list	*presorted;
	t_stack				*stack_a;
	t_stack				*stack_b;

	if (argc < 2)
		return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	presorted = init_lists(stack_a, stack_b, argc, argv);
	if (stack_a->size < 4)
	{
		if (stack_a->size == 2 && stack_a->head->value
			> stack_a->head->next->value)
			swap_stack(stack_a, "sa");
		if (stack_a->size == 3)
			handle_len3(stack_a);
		free_list(presorted);
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
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
	while (stack_b->size > 0
		|| is_min_or_max(stack_a, stack_a->head->prev->value) != 2)
	{
		while ((stack_a->head->prev->value > stack_b->head->value
				&& is_min_or_max(stack_a, stack_a->head->prev->value) != 2)
			|| (stack_a->head->prev->value > stack_b->head->value
				&& stack_a->size == 3))
			reverse_rotate_stack(stack_a, "rra");
		if (stack_b->size > 0)
			push_stack(stack_b, stack_a, "pa");
	}
	free_list(presorted);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
