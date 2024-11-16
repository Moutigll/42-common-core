/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 05:12:44 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/16 16:28:39 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_tests3(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	ft_printf("----------All push tests printed----------\n\n");
}

void	push_tests2(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	ft_printf("Pushed A\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	push_tests3(stack_a, stack_b);
}

void	push_tests(t_stack *stack_a, t_stack *stack_b)
{
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	ft_printf("Pushed B\n");
	print_stacks(stack_a, stack_b);
	push_tests2(stack_a, stack_b);
}
