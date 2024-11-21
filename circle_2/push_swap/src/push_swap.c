/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:01:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/21 16:49:08 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	struct circular_list	*temp;
	int						i;

	temp = stack_a->head;
	i = 0;
	while (i < stack_a->size)
	{
		if (temp->prev->value > temp->value && i != 0)
			break ;
		i++;
		temp = temp->next;
	}
	if (i == stack_a->size)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
}

void	init_lists(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	struct circular_list	*temp;
	int						i;

	stack_b->head = NULL;
	stack_b->size = 0;
	i = 1;
	stack_a->head = insert_circular(NULL, ft_atoi(argv[i]));
	temp = stack_a->head;
	while (i < argc - 1)
	{
		i++;
		temp = insert_circular(temp, ft_atoi(argv[i]));
	}
	stack_a->size = argc - 1;
	check_is_sorted(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack				*stack_a;
	t_stack				*stack_b;

	if (check_args(argc, argv) == 1)
		return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return (free(stack_b), 1);
	if (!stack_b)
		return (free(stack_a), 1);
	init_lists(stack_a, stack_b, argc, argv);
	if (stack_a->size < 4)
	{
		if (stack_a->size == 2 && stack_a->head->value
			> stack_a->head->next->value)
			swap_stack(stack_a, "sa\n");
		if (stack_a->size == 3)
			handle_len3(stack_a);
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stacks(stack_a, stack_b);
	return (0);
}
