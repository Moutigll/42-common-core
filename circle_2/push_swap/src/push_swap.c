/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:01:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/15 17:39:40 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_is_sorted(t_stack *stack_a, t_stack *stack_b,
			struct sorted_list *presorted)
{
	struct circular_list	*temp;
	struct sorted_list		*next;
	int						i;

	temp = stack_a->head;
	next = presorted;
	i = 0;
	while (i < stack_a->size)
	{
		if (temp->value != next->value)
			break ;
		i++;
		temp = temp->next;
		next = next->next;
	}
	if (i == stack_a->size)
	{
		free_list(presorted);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
}

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
	check_is_sorted(stack_a, stack_b, presorted);
	next = presorted;
	temp = stack_a->head;
	return (presorted);
}

int	main(int argc, char **argv)
{
	struct sorted_list	*presorted;
	t_stack				*stack_a;
	t_stack				*stack_b;

	if (check_args(argc, argv) == 1)
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
	sort_stacks(presorted, stack_a, stack_b);
	return (0);
}
