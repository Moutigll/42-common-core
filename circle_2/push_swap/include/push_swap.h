/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:10 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/08 11:35:01 by ele-lean         ###   ########.fr       */
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

typedef struct s_costb
{
	int	type;
	int	value;
}			t_costb;

typedef struct s_total_cost
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	int				total;
	struct s_total_cost	*next;
}				t_total_cost;

// list manipulation
struct sorted_list		*append_sorted(struct sorted_list *previous, int value);
struct circular_list	*insert_circular(struct circular_list
							*previous, int value);
void					presort_bubblesorthehe(struct sorted_list *list);
void					free_list(struct sorted_list *list);
void					free_stack(t_stack *stack);

// stacks operations
int						push_stack(t_stack *stack_a, t_stack *stack_b);
int						swap_stack(t_stack *stack);
int						rotate_stack(t_stack *stack);
int						reverse_rotate_stack(t_stack *stack);

// Tests functions
void					run_tests(struct sorted_list *next,
							t_stack *stack_a, t_stack *stack_b);
void					push_tests(t_stack *stack_a, t_stack *stack_b);
void					swap_tests(t_stack *stack_a, t_stack *stack_b);
void					print_stacks(t_stack *stack_a, t_stack *stack_b);
void					rotate_tests(t_stack *stack_a, t_stack *stack_b);
void					get_best_cost(t_stack *stack_a, t_stack *stack_b);
