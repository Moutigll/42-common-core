/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 05:24:42 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/10 13:39:47 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_tests3(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	swap_stack(stack_a, "sa");
	ft_printf("Swapped empty A\n");
	print_stacks(stack_a, stack_b);
}

void	swap_tests2(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_b, "sb");
	ft_printf("Swapped B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "pa");
	swap_stack(stack_b, "sb");
	ft_printf("Pushed A and swapped B\n");
	print_stacks(stack_a, stack_b);
	swap_stack(stack_b, "sb");
	ft_printf("Swapped B\n");
	print_stacks(stack_a, stack_b);
	swap_stack(stack_b, "sb");
	push_stack(stack_a, stack_b, "pb");
	ft_printf("Swapped B and pushed B\n");
	print_stacks(stack_a, stack_b);
	swap_stack(stack_b, "sb");
	ft_printf("Swapped B\n");
	print_stacks(stack_a, stack_b);
	swap_tests3(stack_a, stack_b);
}

void	swap_tests(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	push_stack(stack_a, stack_b, "pb");
	print_stacks(stack_a, stack_b);
	swap_stack(stack_a, "sa");
	ft_printf("Swapped A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "pb");
	swap_stack(stack_a, "sa");
	ft_printf("Pushed B and swapped A\n");
	print_stacks(stack_a, stack_b);
	swap_stack(stack_a, "sa");
	ft_printf("Swapped A\n");
	print_stacks(stack_a, stack_b);
	swap_stack(stack_a, "sa");
	push_stack(stack_b, stack_a, "pa");
	ft_printf("Swapped A and pushed A\n");
	print_stacks(stack_a, stack_b);
	swap_stack(stack_a, "sa");
	ft_printf("Swapped A\n");
	print_stacks(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	swap_tests2(stack_a, stack_b);
}
