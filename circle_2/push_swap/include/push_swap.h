/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:10 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/10 16:18:46 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>

#include "printf.h"

// A node in a circular doubly linked list
typedef struct circular_list
{
	int						value;
	struct circular_list	*next;
	struct circular_list	*prev;
}				t_clist;

// Head of a stack
typedef struct s_stack
{
	t_clist	*head;
	int		size;
}			t_stack;

// Node for linked list to store sorted list for checker
typedef struct sorted_list
{
	int						value;
	struct sorted_list		*next;
}		t_slist;

// Structure to store the cost of sorting a number in stack b
typedef struct s_costb
{
	int	type;
	int	value;
}			t_costb;

// Structure to store all the operation to sort a number and the total cost
typedef struct s_total_cost
{
	int					ra;
	int					rb;
	int					rra;
	int					rrb;
	int					rr;
	int					rrr;
	int					total;
	struct s_total_cost	*next;
}				t_total_cost;

// List manipulation
struct sorted_list		*append_sorted(struct sorted_list *previous, int value);
struct circular_list	*insert_circular(struct circular_list
							*previous, int value);
void					free_list(struct sorted_list *list);
void					free_stack(t_stack *stack);

// Stacks operations
int						push_stack(t_stack *stack_a, t_stack *stack_b,
							char *str);
int						swap_stack(t_stack *stack, char *str);
int						rotate_stack(t_stack *stack, void *str);
int						reverse_rotate_stack(t_stack *stack, void *str);
int						rotate_both(t_stack *stack_a, void *stack_b);
int						reverse_rotate_both(t_stack *stack_a, void *stack_b);
int						swap_both(t_stack *stack_a, t_stack *stack_b);

// Cost functions
void					get_best_cost(t_stack *stack_a, t_stack *stack_b);
int						is_min_or_max(t_stack *stack, int number);
t_costb					*get_stackb_cost(int number, t_stack *stack_b);
void					print_operations_string(t_total_cost *best,
							t_stack *stack_a, t_stack *stack_b);

// Functions to check sorting and sort small lists
void					handle_len3(t_stack *stack_a);
void					bubblesort(struct sorted_list *list);

// Tests functions
void					run_tests(struct sorted_list *next,
							t_stack *stack_a, t_stack *stack_b);
void					push_tests(t_stack *stack_a, t_stack *stack_b);
void					swap_tests(t_stack *stack_a, t_stack *stack_b);
void					print_stacks(t_stack *stack_a, t_stack *stack_b);
void					rotate_tests(t_stack *stack_a, t_stack *stack_b);
