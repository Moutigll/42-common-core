/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:21:05 by moutig            #+#    #+#             */
/*   Updated: 2024/11/16 17:53:55 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacka(t_clist *next, int nextb_value)
{
	int		next_value;
	int		next_prev_value;
	int		next_next_value;

	next_value = 0;
	next_prev_value = 0;
	next_next_value = 0;
	if (next)
	{
		next_value = next->value;
		next_prev_value = next->prev->value;
		next_next_value = next->next->value;
	}
	ft_printf("Stack A:%2d | Stack B:%2d  (A prev:%2d | next:%2d)",
		next_value, nextb_value, next_prev_value,
		next_next_value);
}

void	print_stacks2(t_clist *next, t_clist *nextb, int nextb_next_value)
{
	int		nextb_value;
	int		nextb_prev_value;

	nextb_value = 0;
	nextb_prev_value = 0;
	if (nextb)
	{
		nextb_value = nextb->value;
		nextb_prev_value = nextb->prev->value;
		nextb_next_value = nextb->next->value;
	}
	print_stacka(next, nextb_value);
	ft_printf("(B prev:%2d | next:%2d)\n",
		nextb_prev_value, nextb_next_value);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*next;
	t_clist	*nextb;
	int		i;
	int		nextb_next_value;

	next = stack_a->head;
	nextb = stack_b->head;
	i = 0;
	ft_printf("------BEGINNING OF STACKS-----\n");
	ft_printf("   A Size:%3d |   B Size:%3d\n", stack_a->size, stack_b->size);
	while (next || nextb)
	{
		nextb_next_value = 0;
		print_stacks2(next, nextb, nextb_next_value);
		i++;
		if (next && i < stack_a->size)
			next = next->next;
		else
			next = NULL;
		if (nextb && i < stack_b->size)
			nextb = nextb->next;
		else
			nextb = NULL;
	}
	ft_printf("--------END OF STACKS--------\n\n");
}

#ifdef TESTING

void	run_tests(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n\n----------Stacks tests----------\n\n");
	ft_printf("\n\n\nPush tests:\n\n\n");
	push_tests(stack_a, stack_b);
	ft_printf("\n\n\nSwap tests:\n\n\n");
	swap_tests(stack_a, stack_b);
	rotate_tests(stack_a, stack_b);
}
#else

void	run_tests(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return ;
}
#endif
