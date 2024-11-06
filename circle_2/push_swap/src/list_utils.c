/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:10:59 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/06 13:42:40 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct sorted_list	*append_sorted(struct sorted_list *previous, int value)
{
	struct sorted_list	*new;

	new = (struct sorted_list *)malloc(sizeof(struct sorted_list));
	if (!new)
		return (0);
	new->value = value;
	new->next = NULL;
	if (!previous)
	{
		previous = new;
		return (new);
	}
	previous->next = new;
	return (new);
}

struct circular_list	*insert_circular(struct circular_list *previous, int value)
{
	struct circular_list	*new;

	new = (struct circular_list *)malloc(sizeof(struct circular_list));
	if (!new)
		return (NULL);
	new->value = value;
	if (!previous)
	{
		new->next = new;
		new->prev = new;
		return (new);
	}
	if (previous->next == previous)
	{
		previous->next = new;
		previous->prev = new;
		new->next = previous;
		new->prev = previous;
		return (new);
	}
	else
	{
		new->next = previous->next;
		new->prev = previous;
		previous->next = new;
		new->next->prev = new;
		return (new);
	}
}

void	presort_bubblesorthehe(struct sorted_list *list)
{
	struct sorted_list	*current;
	int					temp;

	current = list;
	while (current->next)
	{
		if (current->value > current->next->value)
		{
			temp = current->value;
			current->value = current->next->value;
			current->next->value = temp;
			current = list;
		}
		else
			current = current->next;
	}
}

void	free_list(struct sorted_list *list)
{
	struct sorted_list	*current;
	struct sorted_list	*next;

	if (!list)
		return ;
	current = list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
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
