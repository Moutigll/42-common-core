/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:21:05 by moutig            #+#    #+#             */
/*   Updated: 2024/11/07 12:05:13 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*next;
	t_clist	*nextb;
	int		i;

	next = stack_a->head;
	nextb = stack_b->head;
	i = 0;
	ft_printf("------BEGINING OF STACKS-----\n");
	ft_printf("   A Size:%3d |   B Size:%3d\n", stack_a->size, stack_b->size);
	do
	{
		ft_printf("Stack A:%2d | Stack B:%2d  (A prev:%2d | next:%2d) (B prev:%2d | next:%2d)\n",
			next ? next->value : 0,
			nextb ? nextb->value : 0,
			next ? next->prev->value : 0,
			next ? next->next->value : 0,
			nextb ? nextb->prev->value : 0,
			nextb ? nextb->next->value : 0);
		
		i++;
		if (next && i < stack_a->size)
			next = next->next;
		else
			next = 0;
		if (nextb && i < stack_b->size)
			nextb = nextb->next;
		else
			nextb = 0;
	} while (i < stack_a->size || i < stack_b->size);
	ft_printf("--------END OF STACKS--------\n\n");
}

#ifdef TESTING

void	run_tests(struct sorted_list *next, t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Presorted list:\n");
	while (next)
	{
		ft_printf("%d\n", next->value);
		next = next->next;
	}
	ft_printf("\n\n----------Stacks tests----------\n\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	// Test cases to cover all possible combinations of push_a and push_b
	// Initial stack_a: [1, 2, 3, 4, 5], stack_b: []

	// Push all elements from stack_a to stack_b
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);

	// Push all elements back from stack_b to stack_a
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);

	// Push some elements to stack_b and then back to stack_a
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);

	// Push all elements to stack_b and then push some back to stack_a
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
}
#else
void	run_tests(struct sorted_list *next, t_stack *stack_a, t_stack *stack_b)
{
	(void)next;
	(void)stack_a;
	(void)stack_b;
	return ;
}
#endif
