/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:10 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/07 02:49:52 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>

#include "printf.h"

typedef struct circular_list
{
	int						value;
	struct circular_list	*next;
	struct circular_list	*prev;
}				t_clist;

typedef struct s_stack
{
	t_clist	*head;
	int		size;
}			t_stack;

typedef struct sorted_list
{
	int						value;
	struct sorted_list		*next;
}		t_slist;


// list manipulation
struct sorted_list		*append_sorted(struct sorted_list *previous, int value);
struct circular_list	*insert_circular(struct circular_list *previous, int value);
void					presort_bubblesorthehe(struct sorted_list *list);
void					free_list(struct sorted_list *list);
void					free_stack(t_stack *stack);

// stacks operations
int						push_b(t_stack *stack_a, t_stack *stack_b);
int						push_a(t_stack *stack_a, t_stack *stack_b);
int						swap_a(t_stack *stack_a);
int						swap_b(t_stack *stack_b);
int						rotate_a(t_stack *stack_a);
int						rotate_b(t_stack *stack_b);
int						reverse_rotate_a(t_stack *stack_a);
int						reverse_rotate_b(t_stack *stack_b);
