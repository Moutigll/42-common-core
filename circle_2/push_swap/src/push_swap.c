/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:01:53 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/06 13:23:32 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int						i;
	struct sorted_list		*presorted;
	struct sorted_list		*next;
	t_stack					*stack_a;
	struct circular_list	*nextc;
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
	nextc = stack_a->head;
	presort_bubblesorthehe(presorted);
	while (next)
	{
		ft_printf("Stack A:%d\n", nextc->value);
		ft_printf("Presorted:%d\n", next->value);
		nextc = nextc->next;
		next = next->next;
	}
	free_list(presorted);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
