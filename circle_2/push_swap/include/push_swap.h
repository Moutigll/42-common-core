/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:10 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/06 11:34:43 by ele-lean         ###   ########.fr       */
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

struct sorted_list		*append_sorted(struct sorted_list *previous, int value);
int						ft_atoi(char *str);
struct circular_list	*insert_circular(struct circular_list *previous, int value);
void					presort_bubblesorthehe(struct sorted_list *list);
void					free_list(struct sorted_list *list);
void					free_stack(t_stack *stack);
