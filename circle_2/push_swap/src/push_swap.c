/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:01:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/07 03:49:40 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_clist *next;
	t_clist *nextb;
	int i;

	next = stack_a->head;
	nextb = stack_b->head;
	i = 0;
	ft_printf("------BEGINING OF STACKS-----\n");
	ft_printf("   A Size:%3d |   B Size:%3d\n", stack_a->size, stack_b->size);
	do
	{
		ft_printf("Stack A:%5d | %5d:Stack B\n", next ? next->value : 0, nextb ? nextb->value : 0);
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

int	main(int argc, char **argv)
{
	int						i;
	struct sorted_list		*presorted;
	struct sorted_list		*next;
	t_stack					*stack_a;
	t_stack					*stack_b;

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
	while (next)
	{
		ft_printf("Presorted:%d\n", next->value);
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
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_a(stack_a, stack_b);
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_b(stack_a, stack_b);
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	swap_a(stack_a);
	ft_printf("Swapped A\n");
	print_stacks(stack_a, stack_b);
	swap_b(stack_b);
	ft_printf("Swapped B\n");
	print_stacks(stack_a, stack_b);
	swap_a(stack_a);
	ft_printf("Swapped A\n");
	print_stacks(stack_a, stack_b);
	swap_b(stack_b);
	ft_printf("Swapped B\n");
	print_stacks(stack_a, stack_b);
	rotate_a(stack_a);
	ft_printf("Rotated A\n");
	print_stacks(stack_a, stack_b);
	rotate_b(stack_b);
	ft_printf("Rotated B\n");
	print_stacks(stack_a, stack_b);
	rotate_a(stack_a);
	ft_printf("Rotated A\n");
	print_stacks(stack_a, stack_b);
	rotate_b(stack_b);
	ft_printf("Rotated B\n");
	print_stacks(stack_a, stack_b);
	reverse_rotate_a(stack_a);
	ft_printf("Reverse rotated A\n");
	print_stacks(stack_a, stack_b);
	reverse_rotate_b(stack_b);
	ft_printf("Reverse rotated B\n");
	print_stacks(stack_a, stack_b);
	reverse_rotate_a(stack_a);
	ft_printf("Reverse rotated A\n");
	print_stacks(stack_a, stack_b);
	reverse_rotate_b(stack_b);
	ft_printf("Reverse rotated B\n");
	print_stacks(stack_a, stack_b);
	
	
	free_list(presorted);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
