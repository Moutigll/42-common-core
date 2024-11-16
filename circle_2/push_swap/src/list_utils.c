/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:10:59 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/16 17:49:24 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct circular_list	*insert_empty(struct circular_list *new)
{
	new->next = new;
	new->prev = new;
	return (new);
}

struct circular_list	*insert_circular(struct circular_list *previous,
							int value)
{
	struct circular_list	*new;

	new = (struct circular_list *)malloc(sizeof(struct circular_list));
	if (!new)
		return (NULL);
	new->value = value;
	if (!previous)
		return (insert_empty(new));
	if (previous->next == previous)
	{
		previous->next = new;
		previous->prev = new;
		new->next = previous;
		new->prev = previous;
	}
	else
	{
		new->next = previous->next;
		new->prev = previous;
		previous->next = new;
		new->next->prev = new;
	}
	return (new);
}

void	free_stack(t_stack *stack)
{
	t_clist	*current;
	t_clist	*next;
	int		i;

	if (!stack)
		return ;
	if (!stack->head)
		return (free(stack));
	current = stack->head;
	i = stack->size;
	next = 0;
	while (i)
	{
		next = current->next;
		free(current);
		current = next;
		i--;
	}
	free(stack);
}
