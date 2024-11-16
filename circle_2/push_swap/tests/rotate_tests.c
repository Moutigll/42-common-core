/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:26:08 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/16 16:29:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_tests(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n\n\nreverse_rotate_tests\n\n\n");
	print_stacks(stack_a, stack_b);
	reverse_rotate_stack(stack_a, "");
	ft_printf("reverse_rotate_stack(stack_a)\n");
	print_stacks(stack_a, stack_b);
	reverse_rotate_stack(stack_a, "");
	ft_printf("reverse_rotate_stack(stack_a)\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_b, stack_a, "");
	reverse_rotate_stack(stack_b, "");
	ft_printf("reverse_rotate_stack(stack_b) empty stack\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	reverse_rotate_stack(stack_a, "");
	ft_printf("push reverse_rotate_stack(stack_a)\n");
	print_stacks(stack_a, stack_b);
}

void	rotate_tests(t_stack *stack_a, t_stack *stack_b)
{
	push_stack(stack_b, stack_a, "");
	push_stack(stack_b, stack_a, "");
	push_stack(stack_b, stack_a, "");
	push_stack(stack_b, stack_a, "");
	push_stack(stack_b, stack_a, "");
	push_stack(stack_b, stack_a, "");
	ft_printf("\n\n\nrotate_tests\n\n\n");
	print_stacks(stack_a, stack_b);
	rotate_stack(stack_a, "");
	ft_printf("rotate_stack(stack_a)\n");
	print_stacks(stack_a, stack_b);
	rotate_stack(stack_a, "");
	ft_printf("rotate_stack(stack_a)\n");
	print_stacks(stack_a, stack_b);
	rotate_stack(stack_b, "");
	ft_printf("rotate_stack(stack_b) empty stack\n");
	print_stacks(stack_a, stack_b);
	push_stack(stack_a, stack_b, "");
	rotate_stack(stack_a, "");
	ft_printf("push rotate_stack(stack_a)\n");
	print_stacks(stack_a, stack_b);
	reverse_rotate_tests(stack_a, stack_b);
}
